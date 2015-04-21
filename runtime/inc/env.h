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
typedef struct GWBE_VariableListNode GWBE_VariableListNode;
typedef struct GWBE_Program GWBE_Program;
typedef struct GWBE_Function GWBE_Function;
typedef struct GWBE_FunctionListNode GWBE_FunctionListNode;
typedef struct GWBE_VariableListNode GWBE_VariableListNode;
typedef struct GWBE_ProgramLine GWBE_ProgramLine;
typedef struct GWBE_ProgramLineListNode GWBE_ProgramLineListNode;

/*
	Environment
*/
struct GWBE_Environment {
	char* line_buffer;
	struct GWBE_Context* ctx;
	struct GWBE_Program* program;		
	struct GWBE_FunctionListNode* udef_funcs;
};

/*
	Context
*/
struct GWBE_Context {
	int level;					/* уровень вложенности */
	struct GWBE_VariableListNode* system_vars;	/* глобальные переменные GWBasic */
	struct GWBE_VariableListNode* local_vars[255];	/* локальные переменные для каждого блока кода (в зависимости от вложенности) */
};

/*
	Variable ListNode
*/
struct GWBE_VariableListNode {
	GWBC_Variable* var;
	struct GWBE_VariableListNode *next;
};

/*
	Program
*/
struct GWBE_Program {
	struct GWBE_ProgramLine* lines[65536];		
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
	Prototypes
*/
/* Malloc environment structure */
GWBE_Environment* gwbe_NewEnvironment();
/* Free environment structure */
void gwbe_DeleteEnvironment(GWBE_Environment* env);

GWBE_ProgramLine* gwbe_NewProgramLine();
GWBE_ProgramLine* gwbe_DeleteProgramLine();

//GWBE_Function* GWBE_NewFunction(char* name, struct GWBE_VariableListNode* vars, struct GWBN_Expression* body);
//void GWBE_DeleteFunction(struct GWBE_Function* func);

GWBR_Result gwbe_FunctionListNode_Add(GWBE_FunctionListNode** list, GWBE_Function* func);
GWBR_Result gwbe_FunctionListNode_Remove(GWBE_FunctionListNode** list, char* name);

GWBR_Result gwbe_VariableListNode_Add(GWBE_VariableListNode** list, GWBC_Variable* new_var);
GWBR_Result gwbe_VariableListNode_Remove(GWBE_VariableListNode** list, char* name);

GWBC_Variable* gwbe_Variable_Get(GWBE_Environment* env, char* var_name);

#endif
