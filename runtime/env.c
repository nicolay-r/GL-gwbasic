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

GWBC_Variable* gwbe_Context_GetVariable(GWBE_Environment* env, char* var_name)
{
	assert(env->ctx != NULL);

	GWBE_Context* ctx = env->ctx;
	
	int curr_level;
	for (curr_level = ctx->level; curr_level >= 0; curr_level--)
	{
		assert(ctx->local_vars[curr_level] != NULL);

		GWBC_VariableListNode* vars = ctx->local_vars[curr_level];		
		while (vars != NULL)
		{
			if (strcmp(vars->var->name, var_name) == 0)
				return vars->var;
			vars = vars->next;
		}
	}
	
	return NULL;	
}

GWBR_Result gwbe_Context_AddLocalVariable(GWBE_Environment* env, GWBC_Variable* var)
{
	assert(env->ctx != NULL);

	GWBE_Context* ctx = env->ctx;

	assert(ctx->local_vars != NULL);
	assert(ctx->local_vars[ctx->level] != NULL);


			
}
