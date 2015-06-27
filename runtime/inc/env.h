/* GWBasic IDE Environment structure and operations with this structure */

#ifndef _GWBR_ENVIRONMENT_H_

#define _GWBR_ENVIRONMENT_H_

#include "errors.h"		/* GWBR_Result */
#include "parser.h" 		/* GWBN_Interpreter */
#include "core.h"		/* GWBC_Variable, GWBC_Array */

/*
	Type Definitions
*/
typedef struct GWBE_Environment GWBE_Environment;
typedef struct GWBE_Context GWBE_Context;
typedef struct GWBE_CallbackStack GWBE_CallbackStack;
typedef struct GWBE_Program GWBE_Program;
typedef struct GWBE_Function GWBE_Function;
typedef struct GWBE_FunctionListNode GWBE_FunctionListNode;
typedef struct GWBE_ProgramLine GWBE_ProgramLine;
typedef struct GWBE_ProgramLineListNode GWBE_ProgramLineListNode;

/*
	Environment Dependencies
*/
#include "input.h"

/*
	Environment
*/
#define GWBE_RUNTIMEMODE_INTERPRETER		1			/* Интерпретация запроса пользователя */
#define GWBE_RUNTIMEMODE_PROGRAM		2			/* Исполнение программы на GW-Basic */
#define GWBE_RUNTIMEMODE_INTERPRETERWAIT	3			/* Ожидание пользовательского запроса */
#define GWBE_RUNTIMEMODE_PROGRAMWAIT		4			/* Ожидание ввода данных пользователем в процессе выполения программы */

struct GWBE_Environment {
	int trace_mode;							/* Режим трассировки (0 - выключен, 1 - включен) */ 
	int runtime_mode;						/* GWBE_RUNTIMEMODE_INTERPRETER, GWBE_RUNTIMEMODE_PROGRAM */
	int graphics_mode;						/* 0 - DISABLED GRAPHIX, 1 - ENABLED GRAPHIX */
	struct GWBE_Context* ctx;
	struct GWBE_Program* program;
	struct GWBE_Keyboard* keyboard;		
	struct GWBE_FunctionListNode* udef_funcs;
	struct GWBI_Input* input;
};

/*
	Context
*/
#define GWBE_CTX_MAXLEVELS	255

struct GWBE_Context {
	int level;							/* уровень вложенности */
	int skip_flag;							/* флаг, указывающий на то, следует ли пропускать инструкции в Indirect Mode */
	int current_line;						/* текущая строка */
	struct GWBC_VariableListNode* system_vars;			/* глобальные переменные GWBasic */
	struct GWBC_VariableListNode* local_vars[GWBE_CTX_MAXLEVELS];	/* локальные переменные для каждого блока кода (в зависимости от вложенности) */
	struct GWBE_CallbackStack* callback_stack;				
};

#define GWBE_CALLBACKSTACK_MAXSIZE	255

struct GWBE_CallbackStack {
	int top_index;
	int callback[GWBE_CALLBACKSTACK_MAXSIZE];
};

/*
	Program
*/
#define GWBE_PROGRAM_MAXLINES	65536

struct GWBE_Program {
	struct GWBE_ProgramLine* lines[GWBE_PROGRAM_MAXLINES];		
};

struct GWBE_ProgramLine {
	int number;
	char* source;					// заменить на GWBCT_Char
	struct GWBN_Statements* stmts;
};

struct GWBE_ProgramLineListNode{
	struct GWBE_ProgramLine *line;
	struct GWBE_ProgramLineListNode *next; 
};

/*
	Functions
*/
struct GWBE_Function {
	char* name;
	struct GWBE_VariableListNode* vars;
	struct GWBN_Expression* body;		/* function body */
};

struct GWBE_FunctionListNode {
	struct GWBE_Function *val, *next;
};

/*
	Keyboard
*/
struct GWBE_Keyboard {
	int pressed_key;			/* ASCII code of the pressed key */
};

/*
	Prototypes
*/

/* Ctors */
GWBE_Environment* gwbe_NewEnvironment();
GWBE_Program* gwbe_NewProgram();
GWBE_Context* gwbe_NewContext(); 
GWBE_CallbackStack* gwbe_NewCallbackStack();

/* Dtors */
void gwbe_DeleteEnvironment(GWBE_Environment* env);

GWBE_ProgramLine* gwbe_NewProgramLine();
GWBE_ProgramLine* gwbe_DeleteProgramLine();

/* Environment */
void gwbe_PushCharToRequest(GWBE_Environment* env, char c);
void gwbe_ClearRequest(GWBE_Environment* env);
void gwbe_PopCharFromRequest(GWBE_Environment* env);
void gwbe_SetRuntimeMode(GWBE_Environment* env, int new_mode);
void gwbe_SetRuntimeWaitMode(GWBE_Environment* env, int new_mode);

//GWBE_Function* GWBE_NewFunction(char* name, struct GWBE_VariableListNode* vars, struct GWBN_Expression* body);
//void GWBE_DeleteFunction(struct GWBE_Function* func);

/* FunctionListNode Prototypes */
GWBR_Result gwbe_FunctionListNode_Add(GWBE_FunctionListNode** list, GWBE_Function* func);
GWBR_Result gwbe_FunctionListNode_Remove(GWBE_FunctionListNode** list, char* name);

/* Context Prototypes */
GWBC_Variable* gwbe_Context_GetVariable(GWBE_Environment* env, char* var_name);
GWBR_Result gwbe_Context_AddVariable(GWBE_Environment* env, GWBC_Variable* var);
GWBR_Result gwbe_Context_AddLocalVariable(GWBE_Environment* env, GWBC_Variable* var);

/* Context */
char gwbe_Context_ExistsVariableByName(GWBE_Environment* env, char* name);
char gwbe_Context_ExistsVariable(GWBE_Environment* env, GWBC_Variable* var);
void gwbe_Context_IncSkipFlag(GWBE_Environment* env);
void gwbe_Context_DecSkipFlag(GWBE_Environment* env);
void gwbe_Context_PushLocalVariableLevel(GWBE_Environment* env);
void gwbe_Context_PopLocalVariableLevel(GWBE_Environment* env);


/* CallbackStack Prototypes */
void gwbe_CallbackStack_PushCurrentLine(GWBE_Environment* env);
void gwbe_CallbackStack_Pop(GWBE_Environment* env);
int gwbe_CallbackStack_Top(GWBE_Environment* env);

#endif
