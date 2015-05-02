/* GWBasic arithm operataions */

#ifndef _GWBR_ARITHM_H_
#define _GWBR_ARITHM_H_

#include "eval.h"

GWBR_ExpressionResult gwbr_EvaluateAdd(GWBR_ExpressionResult a, GWBR_ExpressionResult b);
GWBR_ExpressionResult gwbr_EvaluateSub(GWBR_ExpressionResult a, GWBR_ExpressionResult b);
GWBR_ExpressionResult gwbr_EvaluateMul(GWBR_ExpressionResult a, GWBR_ExpressionResult b);
GWBR_ExpressionResult gwbr_EvaluateDiv(GWBR_ExpressionResult a, GWBR_ExpressionResult b);

#endif
