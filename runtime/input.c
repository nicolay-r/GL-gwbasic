/* GWBasic Runtime input module */

#include "inc/env.h"
#include "inc/input.h"
#include <stdio.h>	/* getline() */

void GWBI_GetString(GWBE_Environment* env)
{
	assert(env->input != NULL);
	assert(env->input->buffer != NULL);
	assert(env->input->buffer_len > 0);
	
	char** ptr = &env->input->buffer;
	size_n* size = &env->input->buffer_len;

	/*
		Read string from console
	*/
	getline(ptr, size, stdin);
}
