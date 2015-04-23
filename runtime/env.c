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
	env->ctx = (GWBE_Context*) malloc(sizeof(GWBE_Context));

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
	GWBR_Result result; 
	result.type = GWBR_RESULT_OK;

	assert(env->ctx != NULL);

	GWBE_Context* ctx = env->ctx;

	assert(ctx->local_vars != NULL);
	assert(ctx->local_vars[ctx->level] != NULL);
	
	struct GWBC_VariableListNode** var_node = ctx->local_vars;
	
	if (*var_node == NULL)
	{
		*var_node = malloc(sizeof(GWBC_VariableListNode));
		(*var_node)->var = var;
		(*var_node)->next = NULL;
	}
	else 
	{
		struct GWBC_VariableListNode* node = *var_node;
		
		while (node != NULL)
		{
			if (strcmp(node->var->name, var->name) == 0)
			{
				/* проверить существование такой переменной */
				return result;
			}	
			node = node->next;
		}
		node->next = malloc(sizeof(GWBC_VariableListNode));
		node->next->var = var;
		node->next->next = NULL;
	}

	return result;
}

char gwbe_Context_ExistsVariable(GWBE_Environment* env, GWBC_Variable* var)
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
			if (strcmp(vars->var->name, var->name) == 0)
				return 1;
			vars = vars->next;
		}
	}

	return 0;
}
