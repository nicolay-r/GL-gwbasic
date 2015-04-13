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
#include "../cmds/inc/cmds.h"	 	/* Command typedef */
#include "../stmts/inc/stmts.h"		/* Statement typedef */

typedef struct Statements {
	GWBN_Statement* statement;
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
Interpreter* gwbn_Interpreter(int type, union InterpreterMode mode);
IndirectMode* gwbn_IndirectMode(int lineNumber, Statements* statements);
DirectMode* gwbn_DirectMode(int opType, union DirectModeOperation operation);

#endif 
