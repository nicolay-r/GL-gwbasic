/*
	Functions
*/

#include "inc/core.h"
#include <stdlib.h>

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

GWBC_Value gwbc_Variable_GetArrayValue(GWBC_Variable* var, int* indexes)
{
	/* Not Implemented */
}

GWBR_Result gwbc_Variable_SetArrayValue(GWBC_Variable* var, int* indexes, GWBC_Value val)
{
	/* Not Implemented */
}

