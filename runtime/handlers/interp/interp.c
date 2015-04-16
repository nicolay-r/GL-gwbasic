/* GWBasic Handler for Interpreter Mode Node in AST */

#include <stdio.h> 		/* printf */
#include "inc/interp.h"	
#include "stmts/inc/stmts.h"	/* GWBasic Statements AST Nodes */

GWBR_Result gwbh_Interpreter(GWBE_Environment *env, GWBN_Interpreter* node)
{
	GWBR_Result result;	
	result.type = GWBR_RESULT_OK;
	
	printf("In \"Interprer\" Handler\n");
	
	switch (node->type)
	{
		case GWBNT_DIRECT_MODE:
			result = gwbh_DirectMode(env, node->direct);
			break;
		case GWBNT_INDIRECT_MODE:
			result = gwbh_IndirectMode(env, node->indirect);
			break;
	}
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
	
