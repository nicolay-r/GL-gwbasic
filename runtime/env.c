/* GWBasic Runtime Environment implementation */

#include <stdlib.h>	/* malloc, free */

#include "inc/env.h"
#include "inc/runtime.h"
#include "inc/core.h"

#include <output.h>	/* gwbo_* */

#include <assert.h>	/* assert() */
#include <string.h>	/* strcmp() */
/*
	Init Environment
*/
GWBE_Environment* gwbe_NewEnvironment()
{
	/* Инициализация окружения */
	GWBE_Environment* env = (GWBE_Environment*) malloc(sizeof(GWBE_Environment));
	env->runtime_mode = GWBE_RUNTIMEMODE_INTERPRETER;
	env->trace_mode = 1;		/* Trace mode ENABLED. */
	env->graphics_mode = 0;		/* Graphics mode DISABLED. */

	/* Инициализация программы */
	env->program = gwbe_NewProgram();

	/* Инициализация контекста */
	env->ctx = gwbe_NewContext();

	/* Инициализация и очистка Input буфера */	
	env->input = gwbi_NewInput();

	return env;
}

void gwbe_DeleteEnvironment(GWBE_Environment* env)
{
	free(env);
}

GWBE_Program* gwbe_NewProgram()
{
	/* Инициализация программы */
	GWBE_Program* program = (GWBE_Program*) malloc(sizeof(GWBE_Program));
	return program;
}

GWBE_Context* gwbe_NewContext()
{
	/* Инициализация контекста */
	GWBE_Context* ctx = (GWBE_Context*) malloc(sizeof(GWBE_Context));
	ctx->current_line = 0;
	ctx->level = 0;
	ctx->local_vars[0] = NULL;
	
	/* Инициализация стека возврата */
	ctx->callback_stack = gwbe_NewCallbackStack();
	
	return ctx;
}

GWBE_CallbackStack* gwbe_NewCallbackStack()
{	
	GWBE_CallbackStack* callback_stack;
		
	callback_stack = malloc(sizeof(GWBE_CallbackStack));
	callback_stack->top_index = -1;
	
	return callback_stack;
}

GWBR_Result gwbe_FunctionListNode_Add(GWBE_FunctionListNode** list, GWBE_Function* func)
{
	GWBR_Result result;

	assert(0 && "Unimpelemented funtion");

	return result;
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
