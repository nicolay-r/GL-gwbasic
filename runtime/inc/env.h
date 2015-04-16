/* GWBasic IDE Environment structure and operations with this structure */

#ifndef _GWBR_ENVIRONMENT_H_

#define _GWBR_ENVIRONMENT_H_

#include "parser.h" 		/* GWBN_Interpreter */
#include "core.h"		/* GWBC_Variable, GWBC_Array */
/*
	Type Definitions
*/
typedef struct GWBE_Environment GWBE_Environment;
typedef struct GWBE_VariableList GWBE_VariableList;
typedef struct GWBE_Program GWBE_Program;
typedef struct GWBE_Function GWBE_Function;
typedef struct GWBE_FunctionList GWBE_FunctionList;
typedef struct GWBE_VariableList GWBE_VariableList;
typedef struct GWBE_ProgramLine GWBE_ProgramLine;
typedef struct GWBE_ProgramLineList GWBE_ProgramLineList;

/*
	Environment
*/
struct GWBE_Environment {
	char* line_buffer;
	struct GWBE_VariableList* vars;
	struct GWBE_Program* program;		
	struct GWBE_FunctionList* udef_funcs;
};

/*
	Variable List
*/
struct GWBE_VariableList {
	struct GWBC_Variable *value, *next;
};

/*
	Program
*/
struct GWBE_Program {
	struct GWBE_VariableList* global_vars;
	struct GWBE_ProgramLineList* lines;	
};

struct GWBE_ProgramLine {
	int number;
	char* source;			// заменить на GWBCT_Char
	struct GWBN_Interpreter* parsed;
};

struct GWBE_ProgramLineList{
	struct GWBE_ProgramLine *value, *next; 
};

/*
	Functions
*/
struct GWBE_Function {
	char* name;
	struct GWBE_VariableList* vars;
	struct GWBN_Expression* body;		/* function body */
};

struct GWBE_FunctionList {
	struct GWBE_Function *value, *next;
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

//GWBE_Function* GWBE_NewFunction(char* name, struct GWBE_VariableList* vars, struct GWBN_Expression* body);
//void GWBE_DeleteFunction(struct GWBE_Function* func);

/*
	Надо добавить GWBR_Result, но его надо вынести в отдельный хедер
	Иначе получается циклический include
*/


void gwbe_ProgramLineList_Add(GWBE_ProgramLineList** list, GWBE_ProgramLine* new_line); // можно вместо void возвращать GWBR_Result;
void gwbe_ProgramLineList_Remove(GWBE_ProgramLineList** list, int number);

void gwbe_FunctionList_Add(GWBE_FunctionList** list, GWBE_Function* func);
void gwbe_FunctionList_Remove(GWBE_FunctionList** list, char* name);

void gwbe_VariableList_Add(GWBE_VariableList** list, GWBC_Variable* new_var);
void gwbe_VariableList_Remove(GWBE_VariableList** list, char* name);

#endif
