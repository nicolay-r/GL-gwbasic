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
GWBR_ExpressionResult gwbr_EvaluateMathExp(GWBR_ExpressionResult a)
{
	GWBR_ExpressionResult result;
	
	switch (a.val.type)
	{		
		case GWBCT_INTEGER:	
			result.val.type = GWBCT_DOUBLE;
			result.val.double_val = exp(a.val.int_val * 1.0);
			break;
		case GWBCT_SINGLE:
			result.val.type = GWBCT_DOUBLE;
			result.val.double_val = expf(a.val.single_val);
			break;
		case GWBCT_DOUBLE:
			result.val.type = GWBCT_DOUBLE;
			result.val.double_val = exp(a.val.double_val);
			break;
	}

	return result;
}
GWBR_ExpressionResult gwbr_EvaluateMathSin(GWBR_ExpressionResult a)
{
	GWBR_ExpressionResult result;
	
	switch (a.val.type)
	{		
		case GWBCT_INTEGER:	
			result.val.type = GWBCT_SINGLE;
			result.val.single_val = sinf(a.val.int_val*((float)(1.0))); 
			break;
		case GWBCT_SINGLE:
			result.val.type = GWBCT_SINGLE;
			result.val.single_val = sinf(a.val.single_val); 
			break;
		case GWBCT_DOUBLE:
			result.val.type = GWBCT_DOUBLE;
			result.val.double_val = sin(a.val.double_val);
			break;
	}

	return result;
}

GWBR_ExpressionResult gwbr_EvaluateMathCos(GWBR_ExpressionResult a)
{
	GWBR_ExpressionResult result;
	
	switch (a.val.type)
	{		
		case GWBCT_INTEGER:	
			result.val.type = GWBCT_SINGLE;
			result.val.single_val = cosf(a.val.int_val*((float)(1.0))); 
			break;
		case GWBCT_SINGLE:
			result.val.type = GWBCT_SINGLE;
			result.val.single_val = cosf(a.val.single_val); 
			break;
		case GWBCT_DOUBLE:
			result.val.type = GWBCT_DOUBLE;
			result.val.double_val = cos(a.val.double_val);
			break;
	}

	return result;
}
GWBR_ExpressionResult gwbr_EvaluateMathTan(GWBR_ExpressionResult a)
{
	GWBR_ExpressionResult result;
	
	switch (a.val.type)
	{		
		case GWBCT_INTEGER:	
			result.val.type = GWBCT_SINGLE;
			result.val.single_val = tanf(a.val.int_val*((float)(1.0))); 
			break;
		case GWBCT_SINGLE:
			result.val.type = GWBCT_SINGLE;
			result.val.single_val = tanf(a.val.single_val); 
			break;
		case GWBCT_DOUBLE:
			result.val.type = GWBCT_DOUBLE;
			result.val.double_val = tan(a.val.double_val);
			break;
	}

	return result;
}
GWBR_ExpressionResult gwbr_EvaluateMathInt(GWBR_ExpressionResult a)
{
	GWBR_ExpressionResult result;
	
	switch (a.val.type)
	{		
		case GWBCT_INTEGER:	
			result.val.type = GWBCT_INTEGER;
			result.val.int_val =  (int) floor(a.val.int_val);
			break;
		case GWBCT_SINGLE:
			result.val.type = GWBCT_INTEGER;
			result.val.int_val = (int) floor(a.val.single_val); 
			break;
		case GWBCT_DOUBLE:
			result.val.type = GWBCT_INTEGER;
			result.val.int_val = (int) floor(a.val.double_val); 
			break;
	}

	return result;
}
GWBR_ExpressionResult gwbr_EvaluateMathCInt(GWBR_ExpressionResult a)
{
	GWBR_ExpressionResult result;
	
	switch (a.val.type)
	{		
		case GWBCT_INTEGER:	
			result.val.type = GWBCT_INTEGER;
			result.val.int_val =  a.val.int_val;
			break;
		case GWBCT_SINGLE:
			result.val.type = GWBCT_INTEGER;
			result.val.int_val = (int) lroundf(a.val.single_val);
			break;
		case GWBCT_DOUBLE:
			result.val.type = GWBCT_INTEGER;
			result.val.int_val = (int) llround(a.val.double_val); 
			break;
	}

	return result;
}
GWBR_ExpressionResult gwbr_EvaluateMathLog(GWBR_ExpressionResult a)
{
	GWBR_ExpressionResult result;
	
	switch (a.val.type)
	{		
		case GWBCT_INTEGER:	
			result.val.type = GWBCT_SINGLE;
			result.val.single_val = log(a.val.int_val*((float)(1.0))); 
			break;
		case GWBCT_SINGLE:
			result.val.type = GWBCT_SINGLE;
			result.val.single_val = logf(a.val.single_val); 
			break;
		case GWBCT_DOUBLE:
			result.val.type = GWBCT_DOUBLE;
			result.val.double_val = log(a.val.double_val);
			break;
	}

	return result;
}
GWBR_ExpressionResult gwbr_EvaluateMathSgn(GWBR_ExpressionResult a)
{
	GWBR_ExpressionResult result;
	
	switch (a.val.type)
	{		
		case GWBCT_INTEGER:	
			result.val.type = GWBCT_INTEGER;
			result.val.int_val =  a.val.int_val < 0 ? 1 : 0;
			break;
		case GWBCT_SINGLE:
			result.val.type = GWBCT_SINGLE;
			result.val.single_val =  a.val.single_val < 0 ? 1 : 0;
			break;
		case GWBCT_DOUBLE:
			result.val.type = GWBCT_DOUBLE;
			result.val.double_val =  a.val.double_val < 0 ? 1 : 0;
			break;
	}

	return result;
}
GWBR_ExpressionResult gwbr_EvaluateMathFix(GWBR_ExpressionResult a)
{
	GWBR_ExpressionResult result;
	
	switch (a.val.type)
	{		
		case GWBCT_INTEGER:	
			result.val.type = GWBCT_INTEGER;
			result.val.int_val = (int) a.val.int_val;
			break;
		case GWBCT_SINGLE:
			result.val.type = GWBCT_INTEGER;
			result.val.int_val = (int) a.val.single_val;
			break;
		case GWBCT_DOUBLE:
			result.val.type = GWBCT_INTEGER;
			result.val.int_val = (int) a.val.double_val;
			break;
	}

	return result;
}
GWBR_ExpressionResult gwbr_EvaluateMathRnd()
{
	GWBR_ExpressionResult result;
	
	result.val.type = GWBCT_SINGLE;
	result.val.single_val = (float)rand()/(float)RAND_MAX;
	
	return result;
}

