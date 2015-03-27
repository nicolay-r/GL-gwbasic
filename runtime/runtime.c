#include <stdio.h>

#include "../parser/basic.tab.h"
#include "../parser/ast/interp.h"

typedef struct yy_buffer_state * YY_BUFFER_STATE;
extern YY_BUFFER_STATE yy_scan_string(char *str);
extern void yy_delete_buffer(YY_BUFFER_STATE buffer);
/*
	Parse and Build AST for GWBasic Command/Statement/Function
*/
Interpreter* gwbr_Parse(char* toParse)
{
	Interpreter** interpreter = (Interpreter**) malloc (sizeof(Interpreter*));

	// вынести этот код в bison.y, чтобы избавиться от 
	// extern объявлений в этом коде	
	YY_BUFFER_STATE buffer = yy_scan_string(toParse);
	yyparse(interpreter);
	yy_delete_buffer(buffer);
	
	Interpreter* result = *interpreter;
	free(interpreter);
	return result;
}

