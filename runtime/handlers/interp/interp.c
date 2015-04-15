/* GWBasic Handler for Interpreter Mode Node in AST */

#include <stdio.h> 		/* printf */
#include "inc/interp.h"			

GWBR_Result* gwbh_Interpreter(GWBE_Environment *env, GWBN_Interpreter* interp)
{
	/*
		Interpreter Handler for Interpreter AST node
	*/
	printf("In gwbh_Interprer Handler\n");
	return;
}

GWBR_Result* gwbh_DirectMode(GWBE_Environment *env, GWBN_DirectMode* node) {
	/* "DirectMode" handler implementation */
	printf("In \"DirectMode\" Handler\n"); 
} 
	
GWBR_Result* gwbh_IndirectMode(GWBE_Environment *env, GWBN_IndirectMode* node) {
	/* "IndirectMode" handler implementation */
	printf("In \"IndirectMode\" Handler\n"); 
}
