/* GWBasic Functions for Expression AST Nodes */

#include "expr.h"
#include <stdlib.h>

GWBN_Expression* gwbn_NewExpression()
{
	GWBN_Expression* expr = (GWBN_Expression*) malloc(sizeof(GWBN_Expression));
	return expr;
}
