/* GWBasic Evaluator */

#include "inc/eval.h"

#include <output.h>			/* gwbo_DisplayMessage */

#include "inc/arithm.h" 		/* ArithmeticOperations */
#include "inc/relational.h" 		/* RelationalOperations */
#include "inc/math.h"			/* MathFunctions */

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
			result = gwbr_EvaluateSub(a, b);
			break;
		}
		case GWBBT_MUL:
		{
			GWBR_ExpressionResult a = gwbr_EvaluateNumericExpression(env, node->a);
			GWBR_ExpressionResult b = gwbr_EvaluateNumericTerm(env, node->term_b);
			result = gwbr_EvaluateMul(a, b);
			break;
		}
		case GWBBT_DIV:
		{
			GWBR_ExpressionResult a = gwbr_EvaluateNumericExpression(env, node->a);
			GWBR_ExpressionResult b = gwbr_EvaluateNumericTerm(env, node->term_b);
			result = gwbr_EvaluateDiv(a, b);
			break;
		}
		case GWBNT_NUMERICTERM:
		{
			result = gwbr_EvaluateNumericTerm(env, node->term);
			break;
		}
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
			
			GWBR_ExpressionResult b;
			b.val.type = GWBCT_INTEGER;
			b.val.int_val = -1;
			
			result = gwbr_EvaluateMul(result, b);
			break;
		case GWBNT_FUNCTIONALOPERATOR:
			result = gwbr_EvaluateFunctionalOperator(env, node->func_op);
			break;
		case GWBBT_POW:
		{
			GWBR_ExpressionResult a = gwbr_EvaluateNumericTerm(env, node->a);
			GWBR_ExpressionResult b = gwbr_EvaluateNumericTerm(env, node->b);
			result = gwbr_EvaluatePow(a, b);
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
				result.val.type = var->val->type;
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
						result.val.double_val = var->val->double_val;
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
			result.val.type = GWBCT_INTEGER;
			result.val.int_val = node->const_int;
			break;
		case GWBBT_SINGLE:
			result.val.type = GWBCT_SINGLE;
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
			break;
		}
		case GWBNT_STRINGOPERATOR:
		{
			a = gwbr_EvaluateStringOperator(env, node->s1);
			b = gwbr_EvaluateStringOperator(env, node->s2);
			break;
		}
	}
	
	/*
		Выполнение операций сравнения
	*/
	switch (node->op_type)
	{
		case GWBBT_EQUAL:
			/* equal */
			result = gwbr_EvaluateEqual(a, b);
			break;
		case GWBBT_INEQUAL:
			/* inequal */
			result = gwbr_EvaluateInequal(a, b);
			break;
		case GWBBT_LT:
			/* lt */
			result = gwbr_EvaluateLT(a, b);
			break;
		case GWBBT_GT:
			/* gt */
			result = gwbr_EvaluateGT(a, b);
			break;
		case GWBBT_GTE:
			/* gte */
			result = gwbr_EvaluateGTE(a, b);
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
	
	assert(env != NULL);
	assert(node != NULL);

	switch (node->type)
	{
		case GWBNT_MATHFUNCTION:
			result = gwbr_EvaluateMathFunction(env, node->math_func);
			break;
		case GWBNT_STRINGFUNCTION:
			/* Not Implemented */
			gwbo_DisplayMessage(env, "String functional Operator not implemented");
			break;
	}

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
			result.val.type = GWBCT_STRING;

			result.val.str_val = calloc(strlen(a.val.str_val) + strlen(b.val.str_val), sizeof(char));
			strcat(result.val.str_val, a.val.str_val);
			strcat(result.val.str_val, b.val.str_val);
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

				result.val.type = GWBCT_STRING;
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
			result.val.type = GWBCT_STRING; 
			result.val.str_val = strdup(node->str);	
			break;
		}
	}
	return result;
}

GWBR_ExpressionResult gwbr_EvaluateMathFunction(GWBE_Environment* env, GWBN_MathFunction* node)
{
	GWBR_ExpressionResult result;

	assert(env != NULL);
	assert(node != NULL);
	
	switch (node->type)
	{
		case GWBNT_ABS:
		{
			GWBR_ExpressionResult expr_result = gwbr_EvaluateNumericExpression(env, node->abs->expr);
			result = gwbr_EvaluateMathAbs(expr_result);
			break;
		}
		case GWBNT_EXP:
		{
			GWBR_ExpressionResult expr_result = gwbr_EvaluateNumericExpression(env, node->exp->expr);
			result = gwbr_EvaluateMathExp(expr_result);
			break;			
		}
		case GWBNT_SIN:
		{
			GWBR_ExpressionResult expr_result = gwbr_EvaluateNumericExpression(env, node->sin->expr);
			result = gwbr_EvaluateMathSin(expr_result);
			break;
		}
		case GWBNT_COS:
		{
			GWBR_ExpressionResult expr_result = gwbr_EvaluateNumericExpression(env, node->cos->expr);
			result = gwbr_EvaluateMathCos(expr_result);
			break;
		}
		case GWBNT_TAN:
		{
			GWBR_ExpressionResult expr_result = gwbr_EvaluateNumericExpression(env, node->tan->expr);
			result = gwbr_EvaluateMathTan(expr_result);
			break;
		}
		case GWBNT_LOG:
		{
			GWBR_ExpressionResult expr_result = gwbr_EvaluateNumericExpression(env, node->log->expr);
			result = gwbr_EvaluateMathLog(expr_result);
			break;
		}
		case GWBNT_FIX:
		{
			GWBR_ExpressionResult expr_result = gwbr_EvaluateNumericExpression(env, node->fix->expr);
			result = gwbr_EvaluateMathFix(expr_result);
			break;
		}
		case GWBNT_INT:
		{
			GWBR_ExpressionResult expr_result = gwbr_EvaluateNumericExpression(env, node->_int->expr);
			result = gwbr_EvaluateMathInt(expr_result);
			break;
		}
		case GWBNT_CINT:
		{
			GWBR_ExpressionResult expr_result = gwbr_EvaluateNumericExpression(env, node->cint->expr);
			result = gwbr_EvaluateMathCInt(expr_result);
			break;
		}
		case GWBNT_SGN:
		{
			GWBR_ExpressionResult expr_result = gwbr_EvaluateNumericExpression(env, node->sgn->expr);
			result = gwbr_EvaluateMathSgn(expr_result);
			break;
		}
		case GWBNT_SQR:
		{
			GWBR_ExpressionResult expr_result = gwbr_EvaluateNumericExpression(env, node->sqr->expr);
			result = gwbr_EvaluateMathSqr(expr_result);
			break;
		}
		case GWBNT_RND:
			result = gwbr_EvaluateMathRnd();
			break;
	}
	return result;
}
