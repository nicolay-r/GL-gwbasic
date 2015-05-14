#include <stdio.h>

#include "inc/parser.h"
#include "inc/runtime.h"
#include "inc/env.h"
/* 
	Read user request
*/
void gwbr_ReadRequest(char* buffer)
{
	char** bufferPtr = &buffer;
	size_t nbytes = GWBR_LINE_LENGTH - 1;
	getline(&buffer, &nbytes, stdin);
}

/*
	Run GWBasic Shell
*/
void gwbr_RunShell(GWBE_Environment* env)
{
	GWBN_Interpreter* interpreter; 
	while (1)
	{
		gwbr_ReadRequest(env->line_buffer);
		/* Parse user request */
		interpreter = gwbr_Parse(env->line_buffer); 
		/* Handle the received "GWBN_Interpreter*" (Part 3) */
		if (interpreter != NULL)
		{
			gwbh_Interpreter(env, interpreter);
		}
	}	
}

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
