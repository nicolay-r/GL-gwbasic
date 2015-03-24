/* 
	Contains implementation for AST Nodes, declared in "interp.h"
*/

#include "interp.h"

GWBasicInterpreter* AstNode_GWBasicInterpreter(int type)
{
	GWBasicInterpreter* result = (GWBasicInterpreter*) malloc(sizeof(GWBasicInterpreter));
	result->type = type;
	return result;
}
