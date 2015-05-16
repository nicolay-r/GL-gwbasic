/* GWBasic Runtime Output implementation */

#include <output.h>
#include "inc/core.h"

#include <assert.h>
#include <stdio.h>

void gwbo_DisplayMessage(GWBE_Environment* env, char* msg)
{
	printf("%s", msg);	
}

void gwbo_DisplayCoreValue(GWBE_Environment* env, GWBC_Value *result)
{
	assert(env != NULL);
	assert(result != NULL);

	switch (result->type)
	{
		case GWBCT_INTEGER:
			printf("integer %d\n", result->int_val);		
			break;
		case GWBCT_SINGLE:
			printf("single %f\n", result->single_val);
			break;
		case GWBCT_DOUBLE:
			printf("double %lf\n", result->double_val);
			break;
		case GWBCT_STRING:
			assert(result->str_val != NULL);
			printf("%s\n", result->str_val);
			break;
	}
}
