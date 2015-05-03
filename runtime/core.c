/*
	Functions
*/

#include "inc/core.h"
#include "inc/output.h"
#include <stdlib.h>
#include <assert.h>

GWBC_Variable* gwbc_NewVariable(int type, char* name)
{
	GWBC_Variable* var = (GWBC_Variable*) malloc(sizeof(GWBC_Variable));
	var->type = type;
	var->name = name;
	
	if (type == GWBCT_VALUE)
	{
		var->val = (GWBC_Value*) malloc(sizeof(GWBC_Value));
	}
	else if (type == GWBCT_ARRAY)
	{
		var->arr = (GWBC_Array*) malloc(sizeof(GWBC_Array));
	}
	return var;		
}

void gwbc_DeleteVariable(GWBC_Variable* var)
{
	free(var);
}

GWBC_VariableListNode* gwbc_NewVariableListNode()
{
	GWBC_VariableListNode* result = (GWBC_VariableListNode*) malloc(sizeof(GWBC_VariableListNode));
	return result;
}

GWBC_Value gwbc_Variable_GetArrayValue(GWBC_Variable* var, int* indexes)
{
	/* Not Implemented */
}

GWBR_Result gwbc_Variable_SetArrayValue(GWBC_Variable* var, int* indexes, GWBC_Value val)
{
	/* Not Implemented */
}
#include <stdio.h>
GWBR_Result gwbc_Variable_SetValue(GWBC_Variable* var, GWBC_Value* val)
{
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;

	assert(var != NULL);
	assert(val != NULL);

	if (var->type == GWBCT_VALUE)
	{
		if (var->val->type == val->type)
		{
			free(var->val);
			var->val = val;
			return result; 
		}
		else 
		{
			printf("var->val->type = %d\n", var->val->type);
			printf("val->type = %d\n", val->type);
			/* error! */
			gwbo_DisplayMessage(NULL,  "type mismatch\n");
			exit(0);
		}
	}
	return result;
}
