/* GWBasic Math Function Evaluation */

#include "inc/math.h"
#include <math.h>

#include <stdio.h>

GWBR_ExpressionResult gwbr_EvaluateMathAbs(GWBR_ExpressionResult a)
{
	GWBR_ExpressionResult result;
	
	switch (a.val.type)
	{		
		case GWBCT_INTEGER:	
			result.val.type = GWBCT_INTEGER;
			result.val.int_val =  a.val.int_val < 0 ? - a.val.int_val : a.val.int_val;
			break;
		case GWBCT_SINGLE:
			result.val.type = GWBCT_SINGLE;
			result.val.single_val =  a.val.single_val < 0 ? - a.val.single_val : a.val.single_val;
			break;
		case GWBCT_DOUBLE:
			result.val.type = GWBCT_DOUBLE;
			result.val.double_val =  a.val.double_val < 0 ? - a.val.double_val : a.val.double_val;
			break;
	}

	return result;
}
