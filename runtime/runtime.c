#include <stdio.h>

#include "inc/parser.h"

Interpreter* gwbr_Parse(char* sourceCode)
{
	return (Interpreter*) gwbp_Parse(sourceCode);		
}
