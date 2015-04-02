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
	char* buffer = (char*) malloc(sizeof(GWBR_LINE_LENGTH));	
	
	GWBE_Environment* env = gwbe_Create();
	gwbr_RunShell(env, buffer);	
	return 0;
}
