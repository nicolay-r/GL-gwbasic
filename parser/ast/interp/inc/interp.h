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
#include "../stmts/inc/stmts.h"		/* GWBN_Statements typedef */

typedef struct GWBN_DirectMode GWBN_DirectMode;
typedef struct GWBN_IndirectMode GWBN_IndirectMode;
typedef struct GWBN_Interpreter GWBN_Interpreter;

struct GWBN_DirectMode {
	int type;
	union {
		struct GWBN_Command* command;
		struct GWBN_Statements* statements;
	};
};

struct GWBN_IndirectMode{
	int line_number;
	GWBN_Statements* statements;
};

struct GWBN_Interpreter{
	int type;
	union {
		struct GWBN_DirectMode* direct;
		struct GWBN_IndirectMode* indirect;
	};
};

/* 
	Prototypes	
*/
GWBN_DirectMode* gwbn_NewDirectMode();
void gwbn_DeleteDirectMode(GWBN_DirectMode* ptr);
GWBN_IndirectMode* gwbn_NewIndirectMode();
void gwbn_DeleteIndirectMode(GWBN_IndirectMode* ptr);
GWBN_Interpreter* gwbn_NewInterpreter();
void gwbn_DeleteInterpreter(GWBN_Interpreter* ptr);

#endif 
