/* GWBasic Relational Operator Implementation */

#include "inc/relational.h"
#include <stdio.h>

GWBR_ExpressionResult gwbr_EvaluateEqual(GWBR_ExpressionResult a, GWBR_ExpressionResult b)
{
	GWBR_ExpressionResult result;	
	switch (a.val_type)
	{
		case GWBCT_INTEGER:
		{
			switch (b.val_type)
			{
				case GWBCT_INTEGER:
					printf("a.val = %d\n", a.val.int_val);
					printf("b.val = %d\n", b.val.int_val);
					result.val_type = GWBCT_INTEGER;
					result.val.int_val = (a.val.int_val == b.val.int_val);
					break;
				case GWBCT_SINGLE:
					break;
				case GWBCT_DOUBLE:

					break;
				default:
					/* error! */
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

				default:
					/* error */
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
GWBR_ExpressionResult gwbr_EvaluateInequal(GWBR_ExpressionResult a, GWBR_ExpressionResult b)
{
	GWBR_ExpressionResult result;

	return result;
}
GWBR_ExpressionResult gwbr_EvaluateGT(GWBR_ExpressionResult a, GWBR_ExpressionResult b)
{
	GWBR_ExpressionResult result;

	return result;
}
GWBR_ExpressionResult gwbr_EvaluateLT(GWBR_ExpressionResult a, GWBR_ExpressionResult b)
{
	GWBR_ExpressionResult result;

	return result;

}
GWBR_ExpressionResult gwbr_EvaluateGTE(GWBR_ExpressionResult a, GWBR_ExpressionResult b)
{
	GWBR_ExpressionResult result;

	return result;
}
GWBR_ExpressionResult gwbr_EvaluateLTE(GWBR_ExpressionResult a, GWBR_ExpressionResult b)
{
	GWBR_ExpressionResult result;

	return result;
}
