/* GWBasic Interpreter header */
#ifndef __GWBASIC_INTERPRETER__
#define __GWBASIC_INTERPRETER__

/*
	types.h содержит целочисленные константы, которые
	используются для установления типа вершины ast-де
	рева
*/
#include "stdlib.h"

#include "types.h"			/* Defined AST node types */
#include "cmds/commands.h" 		/* Command typedef */
#include "stmts/statements.h"		/* Statement typedef */

typedef struct Statements {
	Statement* statement;
	struct Statements* next;
} Statements;

typedef struct {
	int opType;
	union DirectModeOperation {
		Command* command;
		Statements* statements;
	} op;
} DirectMode;

typedef struct {
	int lineNumber;
	Statements* statements;
} IndirectMode;

typedef struct {
	int type;
	union InterpreterMode {
		DirectMode* direct;
		IndirectMode* indirect;
	} mode;
} Interpreter;

/* 
	GWBasicInterpreter Ctor 
	будет перенесено в отдельный файл, а также будут
	передваваться дополнительные  параметры инициализации
*/
Interpreter* AstNode_Interpreter(int type, union InterpreterMode mode);
IndirectMode* AstNode_IndirectMode(int lineNumber, Statements* statements);
DirectMode* AstNode_DirectMode(int opType, union DirectModeOperation operation);

#endif 
