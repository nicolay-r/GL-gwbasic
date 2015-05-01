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
typedef struct GWBE_Input GWBE_Input;

/*
	Environment
*/
struct GWBE_Environment {
	char* line_buffer;
	struct GWBE_Context* ctx;
	struct GWBE_Program* program;		
	struct GWBE_FunctionListNode* udef_funcs;
	struct GWBE_Input* input;
};

/*
	Context
*/
#define GWBE_CTX_MAXLEVELS	255

struct GWBE_Context {
	int level;							/* уровень вложенности */
	int current_line;							/* текущая строка */
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
	Input
*/
#define GWBE_INPUT_BUFFERLENGTH			2048
struct GWBE_Input {
	char* buffer;				/* буфер прочитанной строки */
	size_t buffer_len;			/* длина буфера (задается при инициализации Environment структуры */
};

/*
	Prototypes
*/
GWBE_Environment* gwbe_NewEnvironment();
void gwbe_DeleteEnvironment(GWBE_Environment* env);

GWBE_ProgramLine* gwbe_NewProgramLine();
GWBE_ProgramLine* gwbe_DeleteProgramLine();

//GWBE_Function* GWBE_NewFunction(char* name, struct GWBE_VariableListNode* vars, struct GWBN_Expression* body);
//void GWBE_DeleteFunction(struct GWBE_Function* func);

/* FunctionListNode Prototypes */
GWBR_Result gwbe_FunctionListNode_Add(GWBE_FunctionListNode** list, GWBE_Function* func);
GWBR_Result gwbe_FunctionListNode_Remove(GWBE_FunctionListNode** list, char* name);

/* Context Prototypes */
GWBC_Variable* gwbe_Context_GetVariable(GWBE_Environment* env, char* var_name);
GWBR_Result gwbe_Context_AddVariable(GWBE_Environment* env, GWBC_Variable* var);
char gwbe_Context_ExistsVariable(GWBE_Environment* env, GWBC_Variable* var);

#endif
