#include <stdio.h>

#include "../parser/basic.tab.h"
#include "inc/runtime.h"	/* gwbr_* functions */
#include "inc/handlers.h"	/* gwbh_* functions */
#include "inc/env.h"		/* gwbe_* functions, GWBE_* types */

int main(int argc, char** argv)
{
	/*
		Prepare runtime environment
	*/
	GWBE_Environment* env = gwbe_Create();
	/* 
		Parse user request 
	*/
	Interpreter* interpreter = gwbr_Parse(); 
	/*
		Handle the received "Interpreter*" 
	*/
	gwbh_Interpreter(env, interpreter);

	printf("%d\n", interpreter->type);
	return 0;
}
