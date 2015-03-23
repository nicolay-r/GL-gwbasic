/* GWBasic Interpreter header */
#ifndef __GWBASIC_INTERPRETER__
#define __GWBASIC_INTERPRETER__

/*
	types.h содержит целочисленные константы, которые
	используются для установления типа вершины ast-де
	рева
*/
#include "types.h"

#include "cmds/commands.h"
#include "stmts/statements.h"

// их нужно объявить в других файлах, в частности 
// каталоге Stmts и Cmds соответственно.
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

typedef struct {	
	int type;
	union {
		DirectMode* direct;
		IndirectMode* indirect;
	};
} Mode;

typedef union {
	Mode* mode;
} GWBasicInterpreter;

#endif 
