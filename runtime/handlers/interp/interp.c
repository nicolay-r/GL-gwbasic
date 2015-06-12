/* GWBasic Handler for Interpreter Mode Node in AST */

#include <stdio.h> 		/* printf */
#include "inc/interp.h"	

#include "stmts/inc/stmts.h"	/* GWBasic Statements AST Node Handlers */
#include "cmds/inc/cmds.h"	/* GWBasic Commands AST Node Handlers */
#include "funcs/inc/funcs.h"	/* GWBasic Functions AST Node Handlers */

#include <output.h>		/* gwbo_* */

#include <string.h>		/* strdup */
#include <assert.h>		/* assert() */

GWBR_Result gwbh_Interpreter(GWBE_Environment *env, GWBN_Interpreter* node)
{
	GWBR_Result result;	
	result.type = GWBR_RESULT_OK;
	
	gwbo_DisplayDebugMessage(env, "In \"Interprer\" Handler");
	
	assert(env != NULL);
	assert(node != NULL);

	/* Defines thr type of subnode */
	switch (node->type)
	{
		case GWBNT_DIRECT_MODE:
			result = gwbh_DirectMode(env, node->direct);
			break;
		case GWBNT_INDIRECT_MODE:
			result = gwbh_IndirectMode(env, node->indirect);
			break;
	}
	
	/* Display Result */
	if (env->runtime_mode == GWBE_RUNTIMEMODE_INTERPRETER)
	{ 
		gwbo_DisplayResult(env, result);
		gwbo_NextLine(env);
	}

	return result;	
}

GWBR_Result gwbh_DirectMode(GWBE_Environment *env, GWBN_DirectMode* node) {
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;

	gwbo_DisplayDebugMessage(env, "In \"DirectMode\" Handler"); 
	
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
			gwbo_DisplayMessage(env, "Undefined type\n");	
			break;
	}
	return result;
} 
	
GWBR_Result gwbh_IndirectMode(GWBE_Environment *env, GWBN_IndirectMode* node) {
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;

	gwbo_DisplayDebugMessage(env, "In \"IndirectMode\" Handler"); 
		
	assert(env->program != NULL);
	assert(env->program->lines != NULL);
	assert(node != NULL);

	if (node->statements != NULL)
	{ /* Add New Line */
		/* Build Line Struct */
		GWBE_ProgramLine *line = malloc(sizeof(GWBE_ProgramLine));
		line->number = node->line_number;
		line->source = strdup((const char*) env->input->buffer);
		line->stmts = node->statements;
		/* Add Line */	
		env->program->lines[line->number] = line;
	}
	else 
	{ /* Remove Existed Line */
		/* Remove Line*/
		env->program->lines[node->line_number] = NULL;
	}
	return result;	 
} 	
