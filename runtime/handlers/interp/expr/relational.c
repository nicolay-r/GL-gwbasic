/* GWBasic Relational Operator Implementation */

#include "inc/relational.h"
#include <stdio.h>
#include <string.h>		/* strcmp() */

GWBR_ExpressionResult gwbr_EvaluateEqual(GWBR_ExpressionResult a, GWBR_ExpressionResult b)
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
					result.val.int_val = (a.val.int_val == b.val.int_val);
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.int_val == b.val.single_val);
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.int_val == b.val.double_val);
					break;
				default:
					/* error! */
					break;
			}
			break;
		}
		case GWBCT_SINGLE:
		{
			switch (b.val.type)
			{
				case GWBCT_INTEGER:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.single_val == b.val.int_val);
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.single_val == b.val.single_val);
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.single_val == b.val.double_val);
					break;
				default:
					/* error */
					break;
			}
			break;		
		}
		case GWBCT_DOUBLE:
		{
			switch (b.val.type)
			{
				case GWBCT_INTEGER:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.double_val == b.val.int_val);
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.double_val == b.val.single_val);
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.double_val == b.val.double_val);
					break;
				default:
					/* error */
					break;
			}
			break;
		}
		case GWBCT_STRING:
		{
			switch (b.val.type)
			{
				case GWBCT_STRING:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = strcmp(a.val.str_val, b.val.str_val) == 0 ? 1 : 0;
					break;
				default:
					/* error */
					break;
			}
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
switch (a.val.type)
	{
		case GWBCT_INTEGER:
		{
			switch (b.val.type)
			{
				case GWBCT_INTEGER:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.int_val != b.val.int_val);
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.int_val != b.val.single_val);
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.int_val != b.val.double_val);
					break;
				default:
					/* error! */
					break;
			}
			break;
		}
		case GWBCT_SINGLE:
		{
			switch (b.val.type)
			{
				case GWBCT_INTEGER:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.single_val != b.val.int_val);
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.single_val != b.val.single_val);
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.single_val != b.val.double_val);
					break;
				default:
					/* error */
					break;
			}
			break;		
		}
		case GWBCT_DOUBLE:
		{
			switch (b.val.type)
			{
				case GWBCT_INTEGER:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.double_val != b.val.int_val);
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.double_val != b.val.single_val);
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.double_val != b.val.double_val);
					break;
				default:
					/* error */
					break;
			}
			break;
		}
		case GWBCT_STRING:
		{
			switch (b.val.type)
			{
				case GWBCT_STRING:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = strcmp(a.val.str_val, b.val.str_val) != 0 ? 1 : 0;
					break;
				default:
					/* error */
					break;
			}
		}
		default:
			/* предусмотреть ошибки */
			break;
	}

	return result;
}
GWBR_ExpressionResult gwbr_EvaluateGT(GWBR_ExpressionResult a, GWBR_ExpressionResult b)
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
					result.val.int_val = (a.val.int_val > b.val.int_val);
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.int_val > b.val.single_val);
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.int_val > b.val.double_val);
					break;
				default:
					/* error! */
					break;
			}
			break;
		}
		case GWBCT_SINGLE:
		{
			switch (b.val.type)
			{
				case GWBCT_INTEGER:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.single_val > b.val.int_val);
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.single_val > b.val.single_val);
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.single_val > b.val.double_val);
					break;
				default:
					/* error */
					break;
			}
			break;		
		}
		case GWBCT_DOUBLE:
		{
			switch (b.val.type)
			{
				case GWBCT_INTEGER:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.double_val > b.val.int_val);
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.double_val > b.val.single_val);
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.double_val > b.val.double_val);
					break;
				default:
					/* error */
					break;
			}
			break;
		}
		case GWBCT_STRING:
		{
			switch (b.val.type)
			{
				case GWBCT_STRING:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = strcmp(a.val.str_val, b.val.str_val) > 0 ? 1 : 0;
					break;
				default:
					/* error */
					break;
			}
		}
		default:
			/* предусмотреть ошибки */
			break;
	}

	return result;
}
GWBR_ExpressionResult gwbr_EvaluateLT(GWBR_ExpressionResult a, GWBR_ExpressionResult b)
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
					result.val.int_val = (a.val.int_val < b.val.int_val);
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.int_val < b.val.single_val);
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.int_val < b.val.double_val);
					break;
				default:
					/* error! */
					break;
			}
			break;
		}
		case GWBCT_SINGLE:
		{
			switch (b.val.type)
			{
				case GWBCT_INTEGER:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.single_val < b.val.int_val);
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.single_val < b.val.single_val);
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.single_val < b.val.double_val);
					break;
				default:
					/* error */
					break;
			}
			break;		
		}
		case GWBCT_DOUBLE:
		{
			switch (b.val.type)
			{
				case GWBCT_INTEGER:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.double_val < b.val.int_val);
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.double_val < b.val.single_val);
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.double_val < b.val.double_val);
					break;
				default:
					/* error */
					break;
			}
			break;
		}
		case GWBCT_STRING:
		{
			switch (b.val.type)
			{
				case GWBCT_STRING:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = strcmp(a.val.str_val, b.val.str_val) < 0 ? 1 : 0;
					break;
				default:
					/* error */
					break;
			}
		}
		default:
			/* предусмотреть ошибки */
			break;
	}

	return result;

}
GWBR_ExpressionResult gwbr_EvaluateGTE(GWBR_ExpressionResult a, GWBR_ExpressionResult b)
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
					result.val.int_val = (a.val.int_val >= b.val.int_val);
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.int_val >= b.val.single_val);
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.int_val >= b.val.double_val);
					break;
				default:
					/* error! */
					break;
			}
			break;
		}
		case GWBCT_SINGLE:
		{
			switch (b.val.type)
			{
				case GWBCT_INTEGER:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.single_val >= b.val.int_val);
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.single_val >= b.val.single_val);
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.single_val >= b.val.double_val);
					break;
				default:
					/* error */
					break;
			}
			break;		
		}
		case GWBCT_DOUBLE:
		{
			switch (b.val.type)
			{
				case GWBCT_INTEGER:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.double_val >= b.val.int_val);
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.double_val >= b.val.single_val);
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.double_val >= b.val.double_val);
					break;
				default:
					/* error */
					break;
			}
			break;
		}
		case GWBCT_STRING:
		{
			switch (b.val.type)
			{
				case GWBCT_STRING:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = strcmp(a.val.str_val, b.val.str_val) >= 0 ? 1 : 0;
					break;
				default:
					/* error */
					break;
			}
		}	
		default:
			/* предусмотреть ошибки */
			break;
	}

	return result;
}
GWBR_ExpressionResult gwbr_EvaluateLTE(GWBR_ExpressionResult a, GWBR_ExpressionResult b)
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
					result.val.int_val = (a.val.int_val <= b.val.int_val);
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.int_val <= b.val.single_val);
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.int_val <= b.val.double_val);
					break;
				default:
					/* error! */
					break;
			}
			break;
		}
		case GWBCT_SINGLE:
		{
			switch (b.val.type)
			{
				case GWBCT_INTEGER:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.single_val <= b.val.int_val);
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.single_val <= b.val.single_val);
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.single_val <= b.val.double_val);
					break;
				default:
					/* error */
					break;
			}
			break;		
		}
		case GWBCT_DOUBLE:
		{
			switch (b.val.type)
			{
				case GWBCT_INTEGER:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.double_val <= b.val.int_val);
					break;
				case GWBCT_SINGLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.double_val <= b.val.single_val);
					break;
				case GWBCT_DOUBLE:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = (a.val.double_val <= b.val.double_val);
					break;
				default:
					/* error */
					break;
			}
			break;
		}
		case GWBCT_STRING:
		{
			switch (b.val.type)
			{
				case GWBCT_STRING:
					result.val.type = GWBCT_INTEGER;
					result.val.int_val = strcmp(a.val.str_val, b.val.str_val) <= 0 ? 1 : 0;
					break;
				default:
					/* error */
					break;
			}
		}
		default:
			/* предусмотреть ошибки */
			break;
	}

	return result;
}
