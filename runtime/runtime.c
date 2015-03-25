#include <stdio.h>

#include "../parser/basic.tab.h"
#include "../parser/ast/interp.h"

/*
	Parse and Build AST for GWBasic Command/Statement/Function
*/
Interpreter* GWBSyntax_Interpretate()
{
	Interpreter** interpreter = (Interpreter**) malloc (sizeof(Interpreter*));

	yyparse(interpreter);
	Interpreter* result = *interpreter;

	free(interpreter);
	return result;
}

int main(int argc, char** argv)
{
	Interpreter* interpreter; 
	interpreter = GWBSyntax_Interpretate();
	printf("%d\n", interpreter->type);
	return 0;
}
