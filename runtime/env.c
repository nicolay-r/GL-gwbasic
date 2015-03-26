/* GWBasic Runtime Environment implementation */

#include "inc/env.h"
#include <stdlib.h>	/* malloc, free */

GWBE_Environment* gwbe_Create()
{
	GWBE_Environment* env = (GWBE_Environment*) malloc(sizeof(GWBE_Environment));
	return env;
}

void gwbe_Delete(GWBE_Environment* env)
{
	free(env);
}
