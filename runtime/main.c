#include <stdio.h>

#include "../parser/basic.tab.h"
#include "inc/runtime.h"	/* gwbr_* functions */
#include "inc/handlers.h"	/* gwbh_* functions */
#include "inc/env.h"		/* gwbe_* functions, GWBE_* types */

#define GWBR_LINE_LENGTH	255

int main(int argc, char** argv)
{
	/*
		Prepare runtime environment
	*/
	char* buffer = (char*) malloc(sizeof(GWBR_LINE_LENGTH));	
	GWBE_Environment* env = gwbe_Create();
	/* 
		Parse user request 
	*/
	char** bufferPtr = &buffer;
	size_t nbytes = GWBR_LINE_LENGTH - 1;
	getline(&buffer, &nbytes, stdin);

	Interpreter* interpreter = gwbr_Parse(buffer); 
	/*
		Handle the received "Interpreter*" 
	*/
	//gwbh_Interpreter(env, interpreter);

	printf("%d\n", interpreter->type);
	return 0;
}
