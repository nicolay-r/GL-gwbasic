/* GWBasic handler for math functions */

#ifndef _GWBR_MATH_H_
#define _GWBR_MATH_H_

#include "../../../../inc/parser.h"
#include "eval.h"

GWBR_ExpressionResult gwbr_EvaluateMathAbs(GWBR_ExpressionResult a);
GWBR_ExpressionResult gwbr_EvaluateMathExp(GWBR_ExpressionResult a);
GWBR_ExpressionResult gwbr_EvaluateMathSin(GWBR_ExpressionResult a);
GWBR_ExpressionResult gwbr_EvaluateMathCos(GWBR_ExpressionResult a);
GWBR_ExpressionResult gwbr_EvaluateMathTan(GWBR_ExpressionResult a);
GWBR_ExpressionResult gwbr_EvaluateMathLog(GWBR_ExpressionResult a);
GWBR_ExpressionResult gwbr_EvaluateMathFix(GWBR_ExpressionResult a);
GWBR_ExpressionResult gwbr_EvaluateMathSgn(GWBR_ExpressionResult a);
GWBR_ExpressionResult gwbr_EvaluateMathInt(GWBR_ExpressionResult a);
GWBR_ExpressionResult gwbr_EvaluateMathCInt(GWBR_ExpressionResult a);
GWBR_ExpressionResult gwbr_EvaluateMathRnd();

#endif
