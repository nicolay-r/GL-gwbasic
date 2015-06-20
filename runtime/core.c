/*
	Functions
*/

#include "inc/core.h"
#include <output.h>

#include <string.h>	/* strdup() */
#include <stdlib.h>
#include <assert.h>

GWBC_Variable* gwbc_NewVariable(char* name, int node_var_type)
{
	GWBC_Variable* var = (GWBC_Variable*) malloc(sizeof(GWBC_Variable));
	var->type = GWBCT_VALUE;
	var->name = strdup(name);
	
	var->val = (GWBC_Value*) malloc(sizeof(GWBC_Value));
	
	switch (node_var_type)
	{
		case GWBNT_STRINGVARIABLE:
			var->val->type = GWBCT_STRING;
			break;
		case GWBNT_INTEGERVARIABLE:
			var->val->type = GWBCT_INTEGER;
			break;
		case GWBNT_SINGLEPRECISIONVARIABLE:
			var->val->type = GWBCT_SINGLE;
			break;
		case GWBNT_DOUBLEPRECISIONVARIABLE:
			var->val->type = GWBCT_DOUBLE;
			break;
		default:
			assert(0 && "Undefinded type of AST-node");
			break;
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

void gwbc_VariableListNode_Clear(GWBC_VariableListNode** list)
{
	assert(list != NULL);
	
	if (*list != NULL)
	{
		GWBC_VariableListNode* node = *list;
		while (node != NULL)
		{
			GWBC_VariableListNode* prev = node;
			node = node->next;

			gwbc_DeleteVariable(prev->var);
			free(prev);
		}

		/* Делаем список пустым */
		*list = NULL;
	}
}
GWBC_Value gwbc_Variable_GetArrayValue(GWBC_Variable* var, GWBC_Value* indexes, int indexes_count)
{
	GWBC_Value value;

	/* Not Implemented */
	assert(0 && "Unimplemented Exception");

	return value;
}

GWBR_Result gwbc_Variable_SetArrayValue(GWBC_Variable* var, GWBC_Value* indexes, int indexes_count, GWBC_Value val)
{
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;

	/* Not Implemented */
	assert(0 && "Unimplemented Exception");

	return result;	
}
#include <stdio.h>
GWBR_Result gwbc_Variable_SetValue(GWBC_Variable* var, GWBC_Value val)
{
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;

	assert(var != NULL);

	if (var->type == GWBCT_VALUE)
	{
		switch (var->val->type)
		{
			case GWBCT_INTEGER:
			{
				switch (val.type)
				{
					case GWBCT_INTEGER:
						*(var->val) = val;
						break;
					case GWBCT_SINGLE:
						result.type = GWBR_ERROR_TYPEMISMATCH;
						break;
					case GWBCT_DOUBLE:
						result.type = GWBR_ERROR_TYPEMISMATCH;
						break;
					case GWBCT_STRING:
						result.type = GWBR_ERROR_TYPEMISMATCH;
						break;
				}
				break;
			}
			case GWBCT_SINGLE:
			{
				switch (val.type)
				{
					case GWBCT_INTEGER:
						/* приведение типов */
						val.type = GWBCT_SINGLE;
						val.single_val =  val.int_val;
						*(var->val) = val;
						break;
					case GWBCT_SINGLE:
						*(var->val) = val;
						break;
					case GWBCT_DOUBLE:
						val.type = GWBCT_SINGLE;
						val.single_val = val.double_val;
						*(var->val) = val;
						break;
					case GWBCT_STRING:
						result.type = GWBR_ERROR_TYPEMISMATCH;
						break;
				}
				break;
			}
			case GWBCT_DOUBLE:
			{
				switch (val.type)
				{
					case GWBCT_INTEGER:
						/* приведение типов */
						val.type = GWBCT_DOUBLE;
						val.double_val = val.int_val;
						*(var->val) = val;
						break;
					case GWBCT_SINGLE:
						/* приведение типов */
						val.type = GWBCT_DOUBLE;
						val.double_val = val.single_val;
						*(var->val) = val;
						break;
					case GWBCT_DOUBLE:
						*(var->val) = val;
						break;
					case GWBCT_STRING:
						result.type = GWBR_ERROR_TYPEMISMATCH;
						break;
				}
				break;
			}
			case GWBCT_STRING:
			{
				switch (val.type)
				{
					case GWBCT_STRING:
						*(var->val) = val;
						break;
					default:
						result.type = GWBR_ERROR_TYPEMISMATCH;
						break;
				}
				break;
			}
		}	
	}
	return result;
}	
