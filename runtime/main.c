
#include "inc/runtime.h"	/* gwbr_* functions */
#include "inc/env.h"		/* gwbe_* functions, GWBE_* types */

int main(int argc, char** argv)
{
	/*
		Prepare runtime environment
	*/
	GWBE_Environment* env = gwbe_NewEnvironment();
	gwbr_RunShell(env);	
	return 0;
}
