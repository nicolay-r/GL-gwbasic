#include <stdio.h>		/* getline() */
#include <assert.h>		/* assert() */

#include "inc/runtime.h"	/* gwbr_* functions */
#include "inc/env.h"		/* gwbe_* functions, GWBE_* types */

/* 
	Read user request
*/
void ReadRequest(GWBI_Input* input)
{
	assert(input != NULL);
	assert(input->buffer != NULL);

	getline(&input->buffer, &input->buffer_len, stdin);
}


/*
	Run GWBasic Shell
*/
void RunShell(GWBE_Environment* env)
{
	assert(env != NULL);

	while (1)
	{
		ReadRequest(env->input);
		/* Interpretate user request */
		gwbr_Run(env);
	}	
}


int main(int argc, char** argv)
{
	/*
		Prepare runtime environment
	*/
	GWBE_Environment* env = gwbe_NewEnvironment();
	RunShell(env);	
	return 0;
}
