/* GWBasic Runtime Expression evaluator */

#ifndef _GWBR_EVAL_H_
#define _GWBR_EVAL_H_

#include "../../../../inc/env.h"	/* GWBE_Environment */
#include "../../../../inc/core.h"	/* GWBC_Value */
#include "../../../../inc/parser.h"	/* GWBN_* */
#include <output.h>			/* GWB0_* */

typedef struct GWBR_ExpressionResult GWBR_ExpressionResult;

/*
	Structures
*/
struct GWBR_ExpressionResult {
	/* int val_type;	*//* GWBCT_INTEGER, GWBCT_SINGLE, GWBCT_DOUBLE, GWBCT_STRING */
	GWBC_Value val;
};

/*
	Prototypes
*/
GWBR_ExpressionResult gwbr_EvaluateExpression(GWBE_Environment* env, GWBN_Expression* node);

GWBR_ExpressionResult gwbr_EvaluateNumericExpression(GWBE_Environment* env, GWBN_NumericExpression* node);
GWBR_ExpressionResult gwbr_EvaluateArithmeticOperator(GWBE_Environment* env, GWBN_ArithmeticOperator* node);
GWBR_ExpressionResult gwbr_EvaluateRelationalOperator(GWBE_Environment* env, GWBN_RelationalOperator* node);
GWBR_ExpressionResult gwbr_EvaluateLogicalOperator(GWBE_Environment* env, GWBN_LogicalOperator* node);
GWBR_ExpressionResult gwbr_EvaluateFunctionalOperator(GWBE_Environment* env, GWBN_FunctionalOperator* node);
GWBR_ExpressionResult gwbr_EvaluateNumericTerm(GWBE_Environment* env, GWBN_NumericTerm* node);
GWBR_ExpressionResult gwbr_EvaluateNumericConstant(GWBE_Environment *env, GWBN_NumericConstant *node);
GWBR_ExpressionResult gwbr_EvaluateNumericVariable(GWBE_Environment *env, GWBN_NumericVariable *node);

GWBR_ExpressionResult gwbr_EvaluateStringExpression(GWBE_Environment* env, GWBN_StringExpression* node);
GWBR_ExpressionResult gwbr_EvaluateStringOperator(GWBE_Environment* env, GWBN_StringOperator* node);
GWBR_ExpressionResult gwbr_EvaluateStringTerm(GWBE_Environment* env, GWBN_StringTerm* node);

GWBR_ExpressionResult gwbr_EvaluateMathFunction(GWBE_Environment* env, GWBN_MathFunction* node);

#endif
