/* GWBasic Interpreter Types */

#ifndef _GWBASIC_INTERPRETER_TYPES_H_
#define _GwBASIC_INTERPRETER_TYPES_H_

/* 
	Interpreter 
*/
#define GWBNT_INTERPRETER		1001
#define GWBNT_DIRECT_MODE		1002	
#define GWBNT_INDIRECT_MODE		1003
#define GWBNT_COMMAND			1004
#define GWBNT_STATEMENT			1005

/*
	Statements
*/
#define GWBNT_LET			1100

/*
	Variables
*/
#define GWBNT_STRINGVARIABLE		1200
#define GWBNT_NUMERICVARIABLE		1201
#define GWBNT_ARRAYVARIABLE		1202
#define GWBNT_INTEGERVARIABLE		1203
#define GWBNT_SINGLEPRECISIONVARIABLE 	1204
#define	GWBNT_DOUBLEPRECISIONVARIABLE 	1205

#endif
