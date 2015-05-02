/* GWBasic Arithm operations implementation */

#include "inc/arithm.h"

GWBR_ExpressionResult gwbr_EvaluateAdd(GWBR_ExpressionResult a, GWBR_ExpressionResult b)
{
	GWBR_ExpressionResult result;

	switch (a.val_type)
	{
		case GWBCT_INTEGER:
		{
			switch (b.val_type)
			{
				case GWBCT_INTEGER:
					result.val_type = GWBCT_INTEGER;
					result.val.int_val = a.val.int_val + b.val.int_val;
					break;
				case GWBCT_SINGLE:

					break;
				case GWBCT_DOUBLE:

					break;
			}
			break;
		}
		case GWBCT_SINGLE:
		{
			switch (b.val_type)
			{
				case GWBCT_INTEGER:
					
					break;
				case GWBCT_SINGLE:

					break;
				case GWBCT_DOUBLE:

					break;
			}
			break;		
		}
		case GWBCT_DOUBLE:
		{
			switch (b.val_type)
			{
				case GWBCT_INTEGER:
					
					break;
				case GWBCT_SINGLE:

					break;
				case GWBCT_DOUBLE:

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


	return result;
}
GWBR_ExpressionResult gwbr_EvaluateMul(GWBR_ExpressionResult a, GWBR_ExpressionResult b)
{
	GWBR_ExpressionResult result;


	return result;
}
GWBR_ExpressionResult gwbr_EvaluateDiv(GWBR_ExpressionResult a, GWBR_ExpressionResult b)
{
	GWBR_ExpressionResult result;

	return result;
}
