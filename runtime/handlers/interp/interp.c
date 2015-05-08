/* GWBasic Handler for Interpreter Mode Node in AST */

#include <stdio.h> 		/* printf */
#include "inc/interp.h"	
#include "stmts/inc/stmts.h"	/* GWBasic Statements AST Node Handlers */
#include "cmds/inc/cmds.h"	/* GWBasic Commands AST Node Handlers */
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

	if (node->type == GWBNT_COMMAND)
	{
		result = gwbh_Command(env, node->command);
	}
	else if (node->type == GWBNT_STATEMENTS) 
	{
		result = gwbh_Statements(env, node->statements);
	}
	else
	{
		printf("Undefined type");	
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
