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
	int operationType;
	union {
		Command* command;
		Statements* statements;
	};
} DirectMode;

typedef struct {
	int lineNumber;
	Statements* statements;
} IndirectMode;

typedef union {
	int type;
	union {
		DirectMode* direct;
		IndirectMode* indirect;
	};
} GWBasicInterpreter;

/* 
	GWBasicInterpreter Ctor 
	будет перенесено в отдельный файл, а также будут
	передваваться дополнительные  параметры инициализации
*/
GWBasicInterpreter* AstNode_GWBasicInterpreter(int type);

#endif 
