/* GWBasic IDE Environment structure and operations with this structure */

#ifndef _GWBR_ENVIRONMENT_H_

#define _GWBR_ENVIRONMENT_H_

#include "parser.h" 		/* GWBN_Interpreter */
#include "core.h"		/* GWBC_Variable, GWBC_Array */
typedef struct {
	GWBC_Variable *value, *next;
} GWBE_VariableList;

// можно вместо void возвращать GWBR_Result;
void gwbe_VariableList_Add(GWBE_VariableList** list, GWBC_Variable* new_var);
void gwbe_VariableList_Remove(GWBE_VariableList** list, char* name);

/*
	Program
*/
typedef struct {
	int number;
	char* source;			// заменить на GWBCT_Char
	GWBN_Interpreter* parsed;
} GWBE_ProgramLine;

GWBE_ProgramLine* gwbe_NewProgramLine();
GWBE_ProgramLine* gwbe_DeleteProgramLine();

typedef struct {
	GWBE_ProgramLine *value, *next; 
} GWBE_ProgramLineList;

void gwbe_ProgramLineList_Add(GWBE_ProgramLineList** list, GWBE_ProgramLine* new_line); // можно вместо void возвращать GWBR_Result;
void gwbe_ProgramLineList_Remove(GWBE_ProgramLineList** list, int number);

typedef struct {
	GWBE_VariableList* global_vars;
	GWBE_ProgramLineList* lines;	
} GWBE_Program;

/*
	Functions
*/
typedef struct {
	char* name;
	GWBE_VariableList* vars;
	GWBN_Expression* body;		/* function body */
} GWBE_Function;

GWBE_Function* GWBE_NewFunction(char* name, GWBE_VariableList* vars, GWBN_Expression* body);
void GWBE_DeleteFunction(GWBE_Function* func);

typedef struct {
	GWBE_Function *value, *next;
} GWBE_FunctionList;

void gwbe_FunctionList_Add(GWBE_FunctionList** list, GWBE_Function* func);
void gwbe_FunctionList_Remove(GWBE_FunctionList** list, char* name);

/*
	Environment
*/
typedef struct {
	char* line_buffer;
	GWBE_VariableList* vars;
	GWBE_Program* program;		
	GWBE_FunctionList* udef_funcs;
} GWBE_Environment;

/* Malloc environment structure */
GWBE_Environment* gwbe_NewEnvironment();
/* Free environment structure */
void gwbe_DeleteEnvironment(GWBE_Environment* env);

#endif
