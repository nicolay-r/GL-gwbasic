/* GWBasic Runtime Output implementation */

#include "inc/output.h"
#include <stdio.h>

void gwbo_DisplayMessage(GWBE_Environment* env, char* msg)
{
	printf("%s", msg);	
}
void gwbo_DisplayResult(GWBE_Environment* env, GWBR_Result *result)
{
	/* Not Implemented */		
}
