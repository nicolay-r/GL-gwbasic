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
	
	env->ctx->level = 0;
	env->ctx->local_vars[0] = NULL;

	return env;
}

void gwbe_DeleteEnvironment(GWBE_Environment* env)
{
	free(env);
}

GWBR_Result gwbe_FunctionListNode_Add(GWBE_FunctionListNode** list, GWBE_Function* func)
{

}

GWBC_Variable* gwbe_Context_GetVariable(GWBE_Environment* env, char* var_name)
{
	assert(env->ctx != NULL);

	GWBE_Context* ctx = env->ctx;
	
	int curr_level;
	for (curr_level = ctx->level; curr_level >= 0; curr_level--)
	{
		if(ctx->local_vars[curr_level] != NULL)
		{ /*если список не пустой */
			GWBC_VariableListNode* vars = ctx->local_vars[curr_level];		
			while (vars != NULL)
			{
				assert(vars->var != NULL);
				assert(vars->var->name != NULL);
				assert(var_name != NULL);	
				if (strcmp(vars->var->name, var_name) == 0)
					return vars->var;
				vars = vars->next;
			}
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
	
	struct GWBC_VariableListNode** var_node = &ctx->local_vars[ctx->level];	
	if (*var_node == NULL)	/* если список пуст*/
	{	
		*var_node = malloc(sizeof(GWBC_VariableListNode));
		(*var_node)->var = var;
		(*var_node)->next = NULL;
	}
	else	/* если в списке есть элементы */ 
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
		if (ctx->local_vars[curr_level] != NULL)
		{ /* если список не пустой */
			GWBC_VariableListNode* vars = ctx->local_vars[curr_level];		
			while (vars != NULL)
			{
				assert(vars->var != NULL);
				assert(vars->var->name != NULL);
				assert(var->name != NULL);
				if (strcmp(vars->var->name, var->name) == 0)
					return 1;
				vars = vars->next;
			}
		}
	}

	return 0;
}
