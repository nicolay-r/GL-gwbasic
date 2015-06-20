/*
	Functions
*/

#include "inc/core.h"
#include <output.h>

#include <string.h>	/* strdup() */
#include <stdlib.h>
#include <assert.h>

int gwbc_ConvertToCoreType(int node_var_type)
{
	switch (node_var_type)
	{
		case GWBNT_STRINGVARIABLE:
			return GWBCT_STRING;
		case GWBNT_INTEGERVARIABLE:
			return GWBCT_INTEGER;
		case GWBNT_SINGLEPRECISIONVARIABLE:
			return GWBCT_SINGLE;
		case GWBNT_DOUBLEPRECISIONVARIABLE:
			return GWBCT_DOUBLE;
		default:
			assert(0 && "Undefinded type of AST-node");
			break;
	}
}

GWBC_Variable* gwbc_NewVariable(char* name, int node_var_type)
{
	GWBC_Variable* var = (GWBC_Variable*) malloc(sizeof(GWBC_Variable));
	var->type = GWBCT_VALUE;
	var->name = strdup(name);
	
	var->val = (GWBC_Value*) malloc(sizeof(GWBC_Value));
	
	var->val->type =  gwbc_ConvertToCoreType(node_var_type);

	return var;		
}

GWBC_Variable* gwbc_NewArrayVariable(char* name, int node_var_type, GWBC_Indexes* inds)
{
	GWBC_Variable* var = (GWBC_Variable*) malloc(sizeof(GWBC_Variable));
	var->type = GWBCT_ARRAY;
	var->name = strdup(name);

	var->arr = (GWBC_Array*) malloc(sizeof(GWBC_Array));
	var->arr->dim_count = inds->count;

	GWBC_ArrayDimension *curr_dim = malloc(sizeof(GWBC_ArrayDimension));
	gwbc_InitArrayDimension(inds, 0, node_var_type, curr_dim);	

	return var;	
}

void gwbc_InitArrayDimension(GWBC_Indexes* inds, int curr_index, int node_var_type, GWBC_ArrayDimension* this)
{
	assert(this != NULL);
	
	int i;
	for (i = curr_index; i < inds->count; i++)
	{
		this->length = inds->indexes[i];
		
		this->cells = malloc(sizeof(GWBC_ArrayCell)*this->length);

		/* Init cells */
		int j;
		for (j = 0; j < this->length; j++)
		{
			if (i < inds->count - 1)
			{
				/* Create Next Dimension */
				this->type = GWBCT_ARRAYDIMENSION;
				this->cells[j].next_dim = malloc(sizeof(GWBC_ArrayDimension)*inds->indexes[i+1]);
				gwbc_InitArrayDimension(inds, i+1, node_var_type, this->cells[j].next_dim);
			}
			else 
			{	/* Has value */
				this->cells[j].val.type = GWBCT_VALUE;
				this->cells[j].val.type = gwbc_ConvertToCoreType(node_var_type);
			}
		}
	}
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
GWBC_Value gwbc_Variable_GetArrayValue(GWBC_Variable* var, GWBC_Indexes* inds)
{
	assert(var != NULL);
	assert(var->arr != NULL);
	assert(inds != NULL);
	assert(inds->indexes != NULL);

	GWBC_ArrayDimension* curr_dim = var->arr->dim; 
	int i;
	for (i = 0; i < inds->count-1; i++)
	{
		int cell_index = inds->indexes[i];
		curr_dim = curr_dim->cells[cell_index].next_dim;
	}

	int last_index = inds->indexes[inds->count - 1];

	return curr_dim->cells[last_index].val;
}

GWBR_Result gwbc_Variable_SetArrayValue(GWBC_Variable* var, GWBC_Indexes* inds, GWBC_Value val)
{
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;

	/* Здесь нужна проверка на выход за границы массива */
	GWBC_ArrayDimension* curr_dim = var->arr->dim; 
	int i;
	for (i = 0; i < inds->count-1; i++)
	{
		int cell_index = inds->indexes[i];
		curr_dim = curr_dim->cells[cell_index].next_dim;
	}

	int last_index = inds->indexes[inds->count - 1];

	curr_dim->cells[last_index].val = val;

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
