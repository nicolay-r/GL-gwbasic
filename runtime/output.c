/* GWBasic Runtime Output implementation */

#include <output.h>
#include "inc/core.h"

#include <assert.h>
#include <stdio.h>

void gwbo_DisplayMessage(GWBE_Environment* env, char* msg)
{
	printf("%s", msg);
}

void gwbo_DisplayDebugMessage(GWBE_Environment* env, char* msg)
{
	assert(env != NULL);
	assert(msg != NULL);

	if (env->trace_mode)
	{
		printf("%s\n", msg);
	}
}	
void gwbo_NextLine(GWBE_Environment* env)
{
	assert(env != NULL);
	printf("\n");
}

void gwbo_DisplayResult(GWBE_Environment* env, GWBR_Result result)
{
	assert(env != NULL);
	
	switch (result.type)
	{
		case GWBR_RESULT_OK:
			gwbo_DisplayMessage(env, "Ok");
			break;
		case GWBR_ERROR_TYPEMISMATCH:
			gwbo_DisplayMessage(env, "Type Mismatch");
			break;
		default:
			gwbo_DisplayMessage(env, "Uknown Error");
			break;
	}
}

void gwbo_DisplayCoreValue(GWBE_Environment* env, GWBC_Value *result)
{
	assert(env != NULL);
	assert(result != NULL);

	switch (result->type)
	{
		case GWBCT_INTEGER:
			printf("integer %d", result->int_val);		
			break;
		case GWBCT_SINGLE:
			printf("single %f", result->single_val);
			break;
		case GWBCT_DOUBLE:
			printf("double %lf", result->double_val);
			break;
		case GWBCT_STRING:
			assert(result->str_val != NULL);
			printf("%s", result->str_val);
			break;
		default:
			gwbo_DisplayMessage(env, "Unknown Value Type");
			break;
	}
}


void gwbo_DisplayLine(GWBE_Environment* env, GWBC_Line line)
{
	/* Does not supported */
	gwbo_DisplayMessage(env, "Terimal doesn't support graphics.");	
	gwbo_NextLine(env);
}

void gwbo_DisplayCircle(GWBE_Environment* env, GWBC_Circle circle)
{
	/* Circle */
	gwbo_DisplayMessage(env, "Terminal doesn't support graphics.");
	gwbo_NextLine(env);
}

void gwbo_Cls(GWBE_Environment* env)
{
	gwbo_DisplayMessage(env, "Terminal doesn't support Cls command.");
	gwbo_NextLine(env);
}
