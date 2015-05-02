/* GWBasic Evaluator */

#include "inc/eval.h"
#include "inc/arithm.h" 		/* ArithmeticOperations */
#include "inc/relational.h" 		/* RelationalOperations */
#include <string.h>			/* strcat() */
#include <assert.h>
#include <stdio.h>


GWBR_ExpressionResult gwbr_EvaluateExpression(GWBE_Environment* env, GWBN_Expression* node)
{
	GWBR_ExpressionResult result;
	switch (node->type)
	{
		case GWBNT_STRINGEXPRESSION:
			result = gwbr_EvaluateStringExpression(env, node->str_expr);
			break;
		case GWBNT_NUMERICEXPRESSION:
			result = gwbr_EvaluateNumericExpression(env, node->num_expr);
			break;
	}
	return result;
}

GWBR_ExpressionResult gwbr_EvaluateNumericExpression(GWBE_Environment* env, GWBN_NumericExpression* node)
{
	GWBR_ExpressionResult result;
	
	assert(node != NULL);

	switch (node->type)
	{
		case GWBNT_ARITHMETICOPERATOR:
			result = gwbr_EvaluateArithmeticOperator(env, node->arithm);
			break;
		case GWBNT_RELATIONALOPERATOR:
			result = gwbr_EvaluateRelationalOperator(env, node->rel);
			break;
		case GWBNT_LOGICALOPERATOR:
			result = gwbr_EvaluateLogicalOperator(env, node->log);
			break;
		case GWBNT_FUNCTIONALOPERATOR:
			result = gwbr_EvaluateFunctionalOperator(env, node->func);
			break;
	}
	return result;
}


GWBR_ExpressionResult gwbr_EvaluateArithmeticOperator(GWBE_Environment* env, GWBN_ArithmeticOperator *node)
{
	GWBR_ExpressionResult result;

	assert(node != NULL);

	switch (node->type)
	{
		case GWBBT_ADD:
		{
			GWBR_ExpressionResult a = gwbr_EvaluateNumericExpression(env, node->a);
			GWBR_ExpressionResult b = gwbr_EvaluateNumericExpression(env, node->b);
			result = gwbr_EvaluateAdd(a, b);
			break;
		}
		case GWBBT_SUB:
		{
			GWBR_ExpressionResult a = gwbr_EvaluateNumericExpression(env, node->a);
			GWBR_ExpressionResult b = gwbr_EvaluateNumericExpression(env, node->b);
			/* выполнить вычитание */
			break;
		}
		case GWBBT_MUL:
		{
			GWBR_ExpressionResult a = gwbr_EvaluateNumericExpression(env, node->a);
			GWBR_ExpressionResult b = gwbr_EvaluateNumericTerm(env, node->term_b);
			/* выполнить умножение */
			break;
		}
		case GWBBT_DIV:
		{
			GWBR_ExpressionResult a = gwbr_EvaluateNumericExpression(env, node->a);
			GWBR_ExpressionResult b = gwbr_EvaluateNumericTerm(env, node->term_b);
			/* выполнить деление */
			break;
		}
		case GWBNT_NUMERICTERM:
			result = gwbr_EvaluateNumericTerm(env, node->term);
			break;
	}

	return result;
}

GWBR_ExpressionResult gwbr_EvaluateNumericTerm(GWBE_Environment* env, GWBN_NumericTerm* node)
{
	GWBR_ExpressionResult result;

	assert(node != NULL);

	switch (node->type)
	{
		case GWBNT_NUMERICEXPRESSION:
			result = gwbr_EvaluateNumericExpression(env, node->num_expr);
			break;
		case GWBBT_UNARY_MINUS:
			result = gwbr_EvaluateNumericTerm(env, node->term);
			/* домножить на унарный минус */
			break;
		case GWBBT_POW:
		{
			GWBR_ExpressionResult a = gwbr_EvaluateNumericTerm(env, node->a);
			GWBR_ExpressionResult b = gwbr_EvaluateNumericTerm(env, node->b);
			
			break;
		}
		case GWBNT_NUMERICVARIABLE:
			result = gwbr_EvaluateNumericVariable(env, node->var);
			break;
		case GWBNT_NUMERICCONSTANT:
			result = gwbr_EvaluateNumericConstant(env, node->num_const);
			break;
	}

	return result;
}

GWBR_ExpressionResult gwbr_EvaluateNumericVariable(GWBE_Environment *env, GWBN_NumericVariable *node)
{
	GWBR_ExpressionResult result;
	
	assert(node != NULL);

	GWBC_Variable* var = gwbe_Context_GetVariable(env, node->name);
	
	if (var != NULL)
	{
		switch (var->type)
		{
			case GWBCT_VALUE:
			{
				result.val_type = var->val->type;
				switch(var->val->type)
				{
					case GWBCT_INTEGER:
					{
						result.val.int_val = var->val->int_val;
						break;
					}

					case GWBCT_SINGLE:
					{
						result.val.single_val = var->val->single_val;
						break;
					}

					case GWBCT_DOUBLE:
					{
						result.val.double_val = var->val->single_val;
						break;
					}
				}
			}
			case GWBCT_ARRAY:
				/* Not supported */
				break;
		}
	}
	else 
	{
		/* Variable wasn't founded */
	}

	return result;
}

GWBR_ExpressionResult gwbr_EvaluateNumericConstant(GWBE_Environment *env, GWBN_NumericConstant *node)
{
	GWBR_ExpressionResult result;
	assert(node != NULL);

	switch (node->type)
	{
		case GWBBT_INTEGER:
			result.val_type = GWBCT_INTEGER;
			result.val.int_val = node->const_int;
			break;
		case GWBBT_SINGLE:
			result.val_type = GWBCT_SINGLE;
			result.val.single_val = node->const_float;
			break;
		case GWBBT_DOUBLE:
			/* Not Implemented */
			break;
	}

	return result;
}


GWBR_ExpressionResult gwbr_EvaluateRelationalOperator(GWBE_Environment *env, GWBN_RelationalOperator *node)
{
	GWBR_ExpressionResult result;
	
	assert(node != NULL);

	GWBR_ExpressionResult a, b;
	switch (node->args_type)
	{
		case GWBNT_ARITHMETICOPERATOR:
		{
			a = gwbr_EvaluateArithmeticOperator(env, node->a);
			b = gwbr_EvaluateArithmeticOperator(env, node->b);
		}
		case GWBNT_STRINGOPERATOR:
		{
			a = gwbr_EvaluateStringOperator(env, node->s1);
			b = gwbr_EvaluateStringOperator(env, node->s2);
		}
	}
	
	/*
		Выполнение операций сравнения
	*/
	switch (node->op_type)
	{
		case GWBBT_EQUAL:
			/* equal */
			break;
		case GWBBT_INEQUAL:
			/* inequal */
			break;
		case GWBBT_LT:
			/* lt */
			break;
		case GWBBT_GT:
			/* gt */
			break;
		case GWBBT_GTE:
			/* gte */
			break;
	}

	return result;
}
GWBR_ExpressionResult gwbr_EvaluateLogicalOperator(GWBE_Environment *env, GWBN_LogicalOperator *node)
{
	GWBR_ExpressionResult result;
	return result;
}
GWBR_ExpressionResult gwbr_EvaluateFunctionalOperator(GWBE_Environment *env, GWBN_FunctionalOperator *node)
{
	GWBR_ExpressionResult result;
	return result;
}

GWBR_ExpressionResult gwbr_EvaluateStringExpression(GWBE_Environment* env, GWBN_StringExpression* node)
{
	assert(node != NULL);
	return gwbr_EvaluateStringOperator(env, node->op);
}

GWBR_ExpressionResult gwbr_EvaluateStringOperator(GWBE_Environment* env, GWBN_StringOperator* node)
{
	GWBR_ExpressionResult result;
	
	assert(node != NULL);

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
		{	
			GWBC_Variable* var = gwbe_Context_GetVariable(env, node->var->name);
			if (var->type == GWBCT_VALUE)
			{
				assert(var->val != NULL);

				result.val_type = GWBCT_STRING;
				result.val.str_val = strdup(var->val->str_val);
			}
			else 
			{
				/* error */
			}
			break;
		}
		case GWBBT_STRING:
		{
			result.val_type = GWBCT_STRING; 
			result.val.str_val = strdup(node->str);	
			break;
		}
	}
	return result;
}
