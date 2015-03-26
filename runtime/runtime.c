#include <stdio.h>

#include "../parser/basic.tab.h"
#include "../parser/ast/interp.h"

/*
	Parse and Build AST for GWBasic Command/Statement/Function
*/
Interpreter* gwbr_Parse()
{
	Interpreter** interpreter = (Interpreter**) malloc (sizeof(Interpreter*));

	yyparse(interpreter);
	Interpreter* result = *interpreter;

	free(interpreter);
	return result;
}

