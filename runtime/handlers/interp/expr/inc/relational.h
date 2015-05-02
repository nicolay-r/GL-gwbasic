/* GWBasic Relational Operator handlers */

#ifndef _GWBN_RELATIONAL_H_
#define _GWBN_RELATIONAL_H_

#include "eval.h"

GWBR_ExpressionResult gwbr_EvaluateEqual(GWBR_ExpressionResult a, GWBR_ExpressionResult b);
GWBR_ExpressionResult gwbr_EvaluateInequal(GWBR_ExpressionResult a, GWBR_ExpressionResult b);
GWBR_ExpressionResult gwbr_EvaluateGT(GWBR_ExpressionResult a, GWBR_ExpressionResult b);
GWBR_ExpressionResult gwbr_EvaluateLT(GWBR_ExpressionResult a, GWBR_ExpressionResult b);
GWBR_ExpressionResult gwbr_EvaluateGTE(GWBR_ExpressionResult a, GWBR_ExpressionResult b);
GWBR_ExpressionResult gwbr_EvaluateLTE(GWBR_ExpressionResult a, GWBR_ExpressionResult b);

#endif
