#include <stdio.h>
#include <assert.h>

#include "inc/parser.h"
#include "inc/runtime.h"
#include "inc/env.h"
#include "handlers/interp/stmts/inc/stmts.h" 	/* To gwbr_RunProgram for statements handling */
/*
	Terminate GWBasic Shell
*/
void gwbr_TerminateShell(GWBE_Environment* env)
{
	exit(0);
}

/*
	Lexical And Syntax Parser
*/
GWBN_Interpreter* gwbr_Parse(char* sourceCode)
{
	return (GWBN_Interpreter*) gwbp_Parse(sourceCode);		
}

/*
	Main Function that runs interpreter
*/
void gwbr_Run(GWBE_Environment *env)
{
	assert(env != NULL);
	assert(env->input != NULL);

	/* Parse user request */
	assert(env->input->buffer != NULL);
	
	/*
		Нужно проверить тип запроса. 
		Пока проверка не осуществляется,
		и запрос всегда разбирается как
		пользовательский запрос к IDE.
	*/

	GWBN_Interpreter* interpreter = gwbr_Parse(env->input->buffer);
	
	/* Handle the received "GWBN_Interpreter*" */
	if (interpreter != NULL)
	{
		gwbh_Interpreter(env, interpreter);
	}
}

/*
	Run GWBasic Program
*/
GWBR_Result gwbr_RunProgram(GWBE_Environment* env)
{
	assert(env != NULL);

	gwbo_DisplayDebugMessage(env, "In \"RunProgram\" Handler"); 	
	
	GWBR_Result result;
	result.type = GWBR_RESULT_OK;
	/* Сброс индекса строки программы */
	env->ctx->current_line = 0;
	int current_line = env->ctx->current_line;
	while (current_line < GWBE_PROGRAM_MAXLINES && result.type == GWBR_RESULT_OK)
	{
		assert(env->program != NULL);
		assert(env->program->lines != NULL);
		
		if (env->program->lines[current_line] != NULL)
		{	
			/* строка присутствует, поэтому ее нужно обработать */
			result = gwbh_Statements(env, env->program->lines[current_line]->stmts);
		}
		
		/* Переход на следующую строку */	
		env->ctx->current_line++;
		current_line = env->ctx->current_line;	
	}	
	
	return result;	 
}
