/*
	Functions
*/

#include "inc/core.h"
#include <stdlib.h>

GWBC_Variable* gwbc_NewVariable()
{
	GWBC_Variable* result = (GWBC_Variable*) malloc(sizeof(GWBC_Variable));
	return result;		
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

