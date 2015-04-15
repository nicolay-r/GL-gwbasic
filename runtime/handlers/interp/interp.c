/* GWBasic Handler for Interpreter Mode Node in AST */

#include <stdio.h> 		/* printf */
#include "inc/interp.h"			

GWBR_Result gwbh_Interpreter(GWBE_Environment *env, GWBN_Interpreter* interp)
{
	GWBR_Result result;	
	printf("In gwbh_Interprer Handler\n");
	
	result.type = GWBR_RESULT_OK;
	return result;	
}

GWBR_Result gwbh_DirectMode(GWBE_Environment *env, GWBN_DirectMode* node) {
	GWBR_Result result;

	/* "DirectMode" handler implementation */
	printf("In \"DirectMode\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
GWBR_Result gwbh_IndirectMode(GWBE_Environment *env, GWBN_IndirectMode* node) {
	GWBR_Result result;

	/* "IndirectMode" handler implementation */
	printf("In \"IndirectMode\" Handler\n"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	
