/* GWBasic Runtime Expression evaluator */

#include "../../../../inc/env.h"	/* GWBE_Environment */
#include "../../../../inc/core.h"	/* GWBC_Value */
#include "../../../../inc/parser.h"	/* GWBN_* */

typedef struct GWBR_ExpressionResult GWBR_ExpressionResult;

/*
	Structures
*/
struct GWBR_ExpressionResult {
	int val_type;
	GWBC_Value val;
};

/*
	Prototypes
*/
GWBR_ExpressionResult gwbr_EvaluateExpression(GWBE_Environment* env, GWBN_Expression* node);
GWBR_ExpressionResult gwbr_EvaluateNumericExpression(GWBE_Environment* env, GWBN_NumericExpression* node);
GWBR_ExpressionResult gwbr_EvaluateStringExpression(GWBE_Environment* env, GWBN_StringExpression* node);
GWBR_ExpressionResult gwbr_EvaluateStringOperator(GWBE_Environment* env, GWBN_StringOperator* node);
GWBR_ExpressionResult gwbr_EvaluateStringTerm(GWBE_Environment* env, GWBN_StringTerm* node);
