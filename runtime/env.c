/* GWBasic Runtime Environment implementation */

#include <stdlib.h>	/* malloc, free */

#include "inc/env.h"
#include "inc/runtime.h"
#include <assert.h>	/* assert() */

/*
	Init Environment
*/
GWBE_Environment* gwbe_NewEnvironment()
{
	GWBE_Environment* env = (GWBE_Environment*) malloc(sizeof(GWBE_Environment));

	env->line_buffer = (char*) malloc(GWBR_LINE_LENGTH * sizeof(char));
	env->program = (GWBE_Program*) malloc(sizeof(GWBE_Program));

	return env;
}

void gwbe_DeleteEnvironment(GWBE_Environment* env)
{
	free(env);
}

GWBR_Result gwbe_FunctionListNode_Add(GWBE_FunctionListNode** list, GWBE_Function* func)
{

}
GWBR_Result gwbe_FunctionListNode_Remove(GWBE_FunctionListNode** list, char* name)
{

}

GWBR_Result gwbe_VariableListNode_Add(GWBE_VariableListNode** list, GWBC_Variable* new_var)
{

}
GWBR_Result gwbe_VariableListNode_Remove(GWBE_VariableListNode** list, char* name)
{

}
