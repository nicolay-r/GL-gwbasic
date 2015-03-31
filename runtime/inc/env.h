/* GWBasic IDE Environment structure and operations with this structure */

#ifndef _GWBR_ENVIRONMENT_H_

#define _GWBR_ENVIRONMENT_H_

#include "parser.h" /* Interpreter */

/*
	Variable
*/
typedef struct {
	int type;
	char* name;
	union VariableValue {
		int _int;
		float _float;
		double _double;
	} value;
} GWBE_Variable;

void gwbe_NewVariable();
void gwbe_DeleteVariable();

typedef struct {
	GWBE_Variable *value, *next;
} GWBE_VariableList;

// можно вместо void возвращать GWBR_Result;
void gwbe_VariableList_Add(GWBE_Variable* new_var);
void gwbe_VariableList_Remove(char* name);

/*
	Program
*/
typedef struct {
	int number;
	char* source;
	Interpreter* parsed;
} GWBE_ProgramLine;

GWBE_ProgramLine* gwbe_NewProgramLine();
GWBE_ProgramLine* gwbe_DeleteProgramLine();

typedef struct {
	GWBE_ProgramLine *value, *next; 
} GWBE_ProgramLineList;

// можно вместо void возвращать GWBR_Result;
void gwbe_ProgramLineList_Add(GWBE_ProgramLine* new_line);
void gwbe_ProgramLineList_Remove(int number);

typedef struct {
	GWBE_VariableList* global_vars;
	GWBE_ProgramLineList* lines;	
} GWBE_Program;

/*
	Environment
*/
typedef struct {
	GWBE_VariableList* vars;
	GWBE_Program* program;		
} GWBE_Environment;

/* Malloc environment structure */
GWBE_Environment* gwbe_Create();
/* Free environment structure */
void gwbe_Delete(GWBE_Environment* env);

#endif
