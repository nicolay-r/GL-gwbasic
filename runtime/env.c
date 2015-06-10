/* GWBasic Runtime Environment implementation */

#include <stdlib.h>	/* malloc, free */

#include "inc/env.h"
#include "inc/runtime.h"
#include "inc/core.h"
#include <assert.h>	/* assert() */

/*
	Init Environment
*/
GWBE_Environment* gwbe_NewEnvironment()
{
	GWBE_Environment* env = (GWBE_Environment*) malloc(sizeof(GWBE_Environment));
	env->runtime_mode = GWBE_RUNTIMEMODE_INTERPRETER;
	env->trace_mode = 1;	/* режим трассировки */

	/* Инициализация программы */
	env->program = (GWBE_Program*) malloc(sizeof(GWBE_Program));

	/* Инициализация контекста */
	env->ctx = (GWBE_Context*) malloc(sizeof(GWBE_Context));
	env->ctx->current_line = 0;
	env->ctx->level = 0;
	env->ctx->local_vars[0] = NULL;

	/* Инициализация и очистка Input буфера */	
	assert(GWBE_INPUT_BUFFERLENGTH > 0);
	env->input = (GWBI_Input*) malloc(sizeof(GWBI_Input));
	env->input->buffer = (char*) malloc(sizeof(char)*GWBE_INPUT_BUFFERLENGTH);
	env->input->buffer_len = 0;
	env->input->buffer[0] = 0;		
	
	/* Инициализация стека возврата */
	env->ctx->callback_stack = malloc(sizeof(GWBE_CallbackStack));
	env->ctx->callback_stack->top_index = -1;
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
	assert(env->ctx->level >= 0);

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
		GWBC_VariableListNode *node = *var_node, *prev = node;	
		while (node != NULL)
		{
			assert(node->var->name != NULL);
			assert(var->name != NULL);
			if (strcmp(node->var->name, var->name) == 0)
			{
				/* проверить существование такой переменной */
				return result;
			}	
			prev = node;
			node = node->next;
		}
		
		assert(prev != NULL);
		prev->next = malloc(sizeof(GWBC_VariableListNode));
		prev->next->var = var;
		prev->next->next = NULL;
	}

	return result;
}

char gwbe_Context_ExistsVariable(GWBE_Environment* env, GWBC_Variable* var)
{
	assert(env->ctx != NULL);
	assert(env->ctx->level >= 0);
	
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

void gwbe_CallbackStack_PushCurrentLine(GWBE_Environment* env)
{	
	assert(env != NULL);
	assert(env->ctx != NULL);
	assert(env->ctx->local_vars != NULL);
	assert(env->ctx->callback_stack != NULL);
	assert(env->ctx->callback_stack->callback != NULL);

	env->ctx->callback_stack->top_index++;
	env->ctx->callback_stack->callback[env->ctx->callback_stack->top_index] = env->ctx->current_line;
}

void gwbe_CallbackStack_Pop(GWBE_Environment* env)
{
	assert(env != NULL);
	assert(env->ctx != NULL);
	assert(env->ctx->local_vars != NULL);
	assert(env->ctx->callback_stack != NULL);
	assert(env->ctx->callback_stack->callback != NULL);
	
	env->ctx->callback_stack->top_index--;
}

int gwbe_CallbackStack_Top(GWBE_Environment* env)
{
	assert(env != NULL);
	assert(env->ctx != NULL);
	assert(env->ctx->local_vars != NULL);
	assert(env->ctx->callback_stack != NULL);
	assert(env->ctx->callback_stack->callback != NULL);

	int top_index = env->ctx->callback_stack->top_index;
	return env->ctx->callback_stack->callback[top_index];
}

void gwbe_Context_IncSkipFlag(GWBE_Environment* env)
{
	assert(env != NULL);
	assert(env->ctx != NULL);
	env->ctx->skip_flag++;
}

void gwbe_Context_DecSkipFlag(GWBE_Environment* env)
{
	assert(env != NULL);
	assert(env->ctx != NULL);
	env->ctx->skip_flag--;
}

void gwbe_Context_PushLocalVariableLevel(GWBE_Environment* env)
{
	assert(env != NULL);
	assert(env->ctx != NULL);
	env->ctx->level++;
}

void gwbe_Context_PopLocalVariableLevel(GWBE_Environment* env)
{
	assert(env != NULL);
	assert(env->ctx != NULL);
	gwbc_VariableListNode_Clear(&env->ctx->local_vars[env->ctx->level]); 
	env->ctx->level--;
}
