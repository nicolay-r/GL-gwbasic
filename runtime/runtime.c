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
	Interpreter* interpreter; 
	while (1)
	{
		gwbr_ReadRequest(env->line_buffer);
		/* Parse user request */
		interpreter = gwbr_Parse(env->line_buffer); 
		/* Handle the received "Interpreter*" (Part 3) */
		//gwbh_Interpreter(env, interpreter);
	}	
}

/*
	Lexical And Syntax Parser
*/
Interpreter* gwbr_Parse(char* sourceCode)
{
	return (Interpreter*) gwbp_Parse(sourceCode);		
}
