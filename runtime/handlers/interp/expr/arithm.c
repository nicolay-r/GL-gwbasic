/* GWBasic Arithm operations implementation */

#include "inc/arithm.h"
#include <stdio.h>
GWBR_ExpressionResult gwbr_EvaluateAdd(GWBR_ExpressionResult a, GWBR_ExpressionResult b)
{
	GWBR_ExpressionResult result;

	switch (a.val.type)
	{
		case GWBCT_INTEGER:
		{
			switch (b.val.type)
			{
				case GWBCT_INTEGER:	
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = a.val.int_val + b.val.int_val;
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_SINGLE;
					result.val.single_val = a.val.int_val + b.val.single_val;
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_DOUBLE;
					result.val.double_val = a.val.int_val + b.val.double_val;
					break;
			}
			break;
		}
		case GWBCT_SINGLE:
		{
			switch (b.val.type)
			{
				case GWBCT_INTEGER:
					result.val.type = GWBCT_SINGLE;
					result.val.single_val = a.val.single_val + b.val.int_val;
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_SINGLE;
					result.val.single_val = a.val.single_val + b.val.single_val;
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_DOUBLE;
					result.val.double_val = a.val.single_val + b.val.double_val;
					break;
			}
			break;		
		}
		case GWBCT_DOUBLE:
		{
			switch (b.val.type)
			{
				case GWBCT_INTEGER:
					result.val.type = GWBCT_DOUBLE;
					result.val.double_val = a.val.double_val + b.val.int_val;
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_DOUBLE;
					result.val.double_val = a.val.double_val + b.val.single_val;
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_DOUBLE;
					result.val.double_val = a.val.double_val + b.val.double_val;
					break;
			}
			break;
		}
		default:
			/* предусмотреть ошибки */
			break;
	}

	return result;
}
GWBR_ExpressionResult gwbr_EvaluateSub(GWBR_ExpressionResult a, GWBR_ExpressionResult b)
{
	GWBR_ExpressionResult result;

	switch (a.val.type)
	{
		case GWBCT_INTEGER:
		{
			switch (b.val.type)
			{
				case GWBCT_INTEGER:	
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = a.val.int_val - b.val.int_val;
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_SINGLE;
					result.val.single_val = a.val.int_val - b.val.single_val;
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_DOUBLE;
					result.val.double_val = a.val.int_val - b.val.double_val;
					break;
			}
			break;
		}
		case GWBCT_SINGLE:
		{
			switch (b.val.type)
			{
				case GWBCT_INTEGER:
					result.val.type = GWBCT_SINGLE;
					result.val.single_val = a.val.single_val - b.val.int_val;
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_SINGLE;
					result.val.single_val = a.val.single_val - b.val.single_val;
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_DOUBLE;
					result.val.double_val = a.val.single_val - b.val.double_val;
					break;
			}
			break;		
		}
		case GWBCT_DOUBLE:
		{
			switch (b.val.type)
			{
				case GWBCT_INTEGER:
					result.val.type = GWBCT_DOUBLE;
					result.val.double_val = a.val.double_val - b.val.int_val;
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_DOUBLE;
					result.val.double_val = a.val.double_val - b.val.single_val;
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_DOUBLE;
					result.val.double_val = a.val.double_val - b.val.double_val;
					break;
			}
			break;
		}
		default:
			/* предусмотреть ошибки */
			break;
	}



	return result;
}
GWBR_ExpressionResult gwbr_EvaluateMul(GWBR_ExpressionResult a, GWBR_ExpressionResult b)
{
	GWBR_ExpressionResult result;

	switch (a.val.type)
	{
		case GWBCT_INTEGER:
		{
			switch (b.val.type)
			{
				case GWBCT_INTEGER:	
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = a.val.int_val * b.val.int_val;
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_SINGLE;
					result.val.single_val = a.val.int_val * b.val.single_val;
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_DOUBLE;
					result.val.double_val = a.val.int_val * b.val.double_val;
					break;
			}
			break;
		}
		case GWBCT_SINGLE:
		{
			switch (b.val.type)
			{
				case GWBCT_INTEGER:
					result.val.type = GWBCT_SINGLE;
					result.val.single_val = a.val.single_val * b.val.int_val;
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_SINGLE;
					result.val.single_val = a.val.single_val * b.val.single_val;
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_DOUBLE;
					result.val.double_val = a.val.single_val * b.val.double_val;
					break;
			}
			break;		
		}
		case GWBCT_DOUBLE:
		{
			switch (b.val.type)
			{
				case GWBCT_INTEGER:
					result.val.type = GWBCT_DOUBLE;
					result.val.double_val = a.val.double_val * b.val.int_val;
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_DOUBLE;
					result.val.double_val = a.val.double_val * b.val.single_val;
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_DOUBLE;
					result.val.double_val = a.val.double_val * b.val.double_val;
					break;
			}
			break;
		}
		default:
			/* предусмотреть ошибки */
			break;
	}



	return result;
}
GWBR_ExpressionResult gwbr_EvaluateDiv(GWBR_ExpressionResult a, GWBR_ExpressionResult b)
{
	GWBR_ExpressionResult result;

	switch (a.val.type)
	{
		case GWBCT_INTEGER:
		{
			switch (b.val.type)
			{
				case GWBCT_INTEGER:	
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = a.val.int_val / b.val.int_val;
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_SINGLE;
					result.val.single_val = a.val.int_val / b.val.single_val;
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_DOUBLE;
					result.val.double_val = a.val.int_val / b.val.double_val;
					break;
			}
			break;
		}
		case GWBCT_SINGLE:
		{
			switch (b.val.type)
			{
				case GWBCT_INTEGER:
					result.val.type = GWBCT_SINGLE;
					result.val.single_val = a.val.single_val / b.val.int_val;
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_SINGLE;
					result.val.single_val = a.val.single_val / b.val.single_val;
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_DOUBLE;
					result.val.double_val = a.val.single_val / b.val.double_val;
					break;
			}
			break;		
		}
		case GWBCT_DOUBLE:
		{
			switch (b.val.type)
			{
				case GWBCT_INTEGER:
					result.val.type = GWBCT_DOUBLE;
					result.val.double_val = a.val.double_val / b.val.int_val;
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_DOUBLE;
					result.val.double_val = a.val.double_val / b.val.single_val;
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_DOUBLE;
					result.val.double_val = a.val.double_val / b.val.double_val;
					break;
			}
			break;
		}
		default:
			/* предусмотреть ошибки */
			break;
	}


	return result;
}
