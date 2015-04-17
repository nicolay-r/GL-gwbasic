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
	return env;
}

void gwbe_DeleteEnvironment(GWBE_Environment* env)
{
	free(env);
}

GWBR_Result gwbe_ProgramLineListNode_Add(GWBE_ProgramLineListNode** list, GWBE_ProgramLine* new_line)
{
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;
	
	assert(list != NULL);
	
	if (*list == NULL)
	{	
		*list = malloc(sizeof(GWBE_ProgramLineListNode));
		(*list)->val = new_line;
		(*list)->next = NULL;
	}
	else
	{
		GWBE_ProgramLineListNode *elem = *list;
		while (elem->next != NULL)
			elem = elem->next;
		elem->next = malloc(sizeof(GWBE_ProgramLineListNode));
		elem->next->val = new_line;
	}

	return result; 
}
GWBR_Result gwbe_ProgramLineListNode_Remove(GWBE_ProgramLineListNode** list, int number)
{
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;
	
	assert(list != NULL);

	if (*list != NULL)
	{
		GWBE_ProgramLineListNode *elem = *list;
		GWBE_ProgramLineListNode *prev = NULL;
		while (elem->next != NULL)
		{	
			GWBE_ProgramLine* val = elem->val;
			if (val->number == number)
			{
				if (prev != NULL)
					prev->next = elem->next;
				else
					*list = elem->next;
				// Дописать удаление
				// GWBE_DeleteProgramLineListNode(elem);
			}
			prev = elem;
			elem = elem->next;
		}
		elem->next = malloc(sizeof(GWBE_ProgramLineListNode));
	}

	return result;
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
