/* GWBasic Evaluator */

#include "inc/eval.h"
#include <string.h>	/* strcat() */

GWBR_ExpressionResult gwbr_EvaluateExpression(GWBE_Environment* env, GWBN_Expression* node)
{
	GWBR_ExpressionResult result;
	switch (node->type)
	{
		case GWBNT_STRINGEXPRESSION:
			result = gwbr_EvaluateStringExpression(env, node->str_expr);
			break;
		case GWBNT_NUMERICEXPRESSION:
			/* Evaluate NumericExpression */
			break;
	}
	return result;
}

GWBR_ExpressionResult gwbr_EvaluateStringExpression(GWBE_Environment* env, GWBN_StringExpression* node)
{
	return gwbr_EvaluateStringOperator(env, node->op);
}

GWBR_ExpressionResult gwbr_EvaluateStringOperator(GWBE_Environment* env, GWBN_StringOperator* node)
{
	GWBR_ExpressionResult result;
	switch (node->type)
	{
		case GWBBT_ADD:
		{
			/* Concatenate two strings */
			GWBR_ExpressionResult a = gwbr_EvaluateStringTerm(env, node->a);
			GWBR_ExpressionResult b = gwbr_EvaluateStringOperator(env, node->b);
			result.val_type = GWBCT_STRING;
			result.val.str_val = strcat(a.val.str_val, b.val.str_val);
			break;
		}
		case GWBNT_STRINGTERM:
		{
			result = gwbr_EvaluateStringTerm(env, node->term);
			break;
		}
	}
	return result;
}

GWBR_ExpressionResult gwbr_EvaluateStringTerm(GWBE_Environment* env, GWBN_StringTerm* node)
{
	GWBR_ExpressionResult result;
	switch (node->type)
	{
		case GWBNT_STRINGVARIABLE:
			/* Take a variable value by name*/
			break;
		case GWBBT_STRING:
			result.val_type = GWBCT_STRING; 
			result.val.str_val = node->str;	
			break;
	}
	return result;
}
