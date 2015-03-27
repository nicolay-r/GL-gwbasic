#include <stdio.h>

#include "../parser/basic.tab.h"
#include "../parser/ast/interp.h"

Interpreter* gwbr_Parse(char* sourceCode)
{
	return (Interpreter*) gwbp_Parse(sourceCode);		
}
