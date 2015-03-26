/* 
	Contains implementation for AST Nodes, declared in "interp.h"
*/

#include "interp.h"
#include <stdio.h> 	/* printf */

Interpreter* gwbn_Interpreter(int type, union InterpreterMode mode)
{
	Interpreter* result = (Interpreter*) malloc (sizeof(Interpreter));
	result->type = type;
	result->mode = mode;
	return result;
}

IndirectMode* gwbn_IndirectMode(int lineNumber, Statements* statements)
{
	IndirectMode* result = (IndirectMode*) malloc(sizeof(IndirectMode));
	result->lineNumber = lineNumber;
	result->statements = statements;
	return result;
}
DirectMode* gwbn_DirectMode(int opType, union DirectModeOperation op)
{
	DirectMode* result = (DirectMode*) malloc(sizeof(DirectMode));
	result->opType = opType;
	result->op = op;
	return result;
}
