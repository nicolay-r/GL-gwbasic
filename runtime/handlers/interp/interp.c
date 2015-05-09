/* GWBasic Handler for Interpreter Mode Node in AST */

#include <stdio.h> 		/* printf */
#include "inc/interp.h"	

#include "stmts/inc/stmts.h"	/* GWBasic Statements AST Node Handlers */
#include "cmds/inc/cmds.h"	/* GWBasic Commands AST Node Handlers */
#include "funcs/inc/funcs.h"	/* GWBasic Functions AST Node Handlers */

#include <assert.h>		/* assert() */

GWBR_Result gwbh_Interpreter(GWBE_Environment *env, GWBN_Interpreter* node)
{
	GWBR_Result result;	
	result.type = GWBR_RESULT_OK;
	
	gwbo_DisplayMessage(env, "In \"Interprer\" Handler\n");
	
	assert(env != NULL);
	assert(node != NULL);

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
	result.type = GWBR_RESULT_OK;

	gwbo_DisplayMessage(env, "In \"DirectMode\" Handler\n"); 
	
	assert(node != NULL);

	switch(node->type)
	{
		case GWBNT_COMMAND:
			result = gwbh_Command(env, node->command);
			break;
		case GWBNT_STATEMENTS:
			result = gwbh_Statements(env, node->statements);
			break;
		case  GWBNT_FUNCTION:
			result = gwbh_Function(env, node->function);
			break;
		default:
			printf("Undefined type\n");	
			break;
	}
	return result;
} 
	
GWBR_Result gwbh_IndirectMode(GWBE_Environment *env, GWBN_IndirectMode* node) {
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;

	gwbo_DisplayMessage(env, "In \"IndirectMode\" Handler\n"); 
		
	assert(env->program != NULL);
	assert(env->program->lines != NULL);
	assert(node != NULL);

	GWBE_ProgramLine *line = malloc(sizeof(GWBE_ProgramLine));
	line->number = node->line_number;
	line->source = env->line_buffer;
	line->stmts = node->statements;
	
	env->program->lines[line->number] = line;
	
	return result;	 
} 	
