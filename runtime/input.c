/* GWBasic Runtime input module */

#include "inc/env.h"
#include <string.h>	/* strlen() */
#include <stdio.h>	/* getline() */
#include <assert.h>	/* assert() */
#include <ctype.h>	/* isspace() */

GWBI_Input* gwbi_NewInput()
{	
	assert(GWBE_INPUT_BUFFERLENGTH > 0);

	GWBI_Input* input = (GWBI_Input*) malloc(sizeof(GWBI_Input));

	input->buffer = (char*) malloc(sizeof(char)*GWBE_INPUT_BUFFERLENGTH);
	input->buffer_len = 0;
	input->buffer[0] = 0;		
	input->input_request.var_index = 0;

	return input;	
}

void trimwhitespace(char *str)
{
	char *end;
	// Trim leading space
	while(isspace(*str)) str++;
        	if(*str == 0)  // All spaces?
	    		return;
	
	// Trim trailing space
	end = str + strlen(str) - 1;
	while(end > str && isspace(*end)) end--;
	
	// Write new null terminator
	*(end+1) = 0;
}
void gwbi_GetString(GWBE_Environment* env)
{
	assert(env->input != NULL);
	assert(env->input->buffer != NULL);
	assert(env->input->buffer_len > 0);
	
	char* ptr = env->input->buffer;
	size_t *size = &env->input->buffer_len;

	/* trim whitespaces */
	trimwhitespace(ptr);
	*size = strlen(ptr);
}

int gwbi_GetInteger(GWBE_Environment* env)
{
	assert(env->input != NULL);

	char* ptr = env->input->buffer;

	return atoi(ptr);  
}

float gwbi_GetFloat(GWBE_Environment* env)
{
	assert(env->input != NULL);

	char* ptr = env->input->buffer;

	return atof(ptr);

}

double gwbi_GetDouble(GWBE_Environment* env)
{
	assert(env->input != NULL);

	char* ptr = env->input->buffer;

	return atof(ptr);
}
