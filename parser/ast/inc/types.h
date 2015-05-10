/* GWBasic Interpreter Types */

#ifndef _GWBASIC_INTERPRETER_TYPES_H_
#define _GwBASIC_INTERPRETER_TYPES_H_

/* 
	Interpreter 
*/
#define GWBNT_INTERPRETER		1001
#define GWBNT_DIRECT_MODE		1002	
#define GWBNT_INDIRECT_MODE		1003
#define GWBNT_STATEMENTS		1004
#define GWBNT_STATEMENT			1005

/*
	Statements
*/
#define GWBNT_LET			1100
#define GWBNT_PRINT			1101
#define GWBNT_IFTHENELSE		1102
#define GWBNT_GOTO			1103
#define GWBNT_INPUT			1104
#define GWBNT_LINENUMBER		1105
#define GWBNT_RETURN			1106
#define GWBNT_FOR			1107
#define GWBNT_NEXT			1108

/*
	Variables
*/
#define GWBNT_STRINGVARIABLE		1200
#define GWBNT_NUMERICVARIABLE		1201
#define GWBNT_ARRAYVARIABLE		1202
#define GWBNT_INTEGERVARIABLE		1203
#define GWBNT_SINGLEPRECISIONVARIABLE 	1204
#define	GWBNT_DOUBLEPRECISIONVARIABLE 	1205

/*
	Expressions
*/
#define GWBNT_TEXPRESSION			1301
#define GWBNT_NUMERICEXPRESSION			1302
#define GWBNT_ARITHMETICOPERATOR		1303
#define GWBNT_NUMERICTERM			1304
#define GWBNT_STRINGEXPRESSION			1305
#define GWBNT_STRINGOPERATOR			1306
#define GWBNT_STRINGTERM			1307
#define GWBNT_RELATIONALOPERATOR		1308
#define GWBNT_LOGICALOPERATOR			1309
#define GWBNT_FUNCTIONALOPERATOR		1310
/*
	CONSTANTS
*/
#define GWBNT_NUMERICCONSTANT			1500

/*	
	Commands
*/
#define GWBNT_COMMAND				1700
#define GWBNT_SYSTEM				1701
#define GWBNT_AUTO				1702
#define GWBNT_RUN				1703
#define GWBNT_BLOAD				1704

/*
	Functions
*/
#define GWBNT_ABS				1801
#define GWBNT_EXP				1802
#define GWBNT_SIN				1803
#define GWBNT_COS				1804
#define GWBNT_TAN				1805
#define GWBNT_LOG				1806
#define GWBNT_FIX				1807
#define GWBNT_INT				1808
#define GWBNT_CINT				1809
#define GWBNT_SGN				1810
#define GWBNT_SQR				1811
#define GWBNT_RND				1812

#define GWBNT_MATHFUNCTION			1850
#define GWBNT_STRINGFUNCTION			1851
#define GWBNT_SYSTEMFUNCTION			1852
#define GWBNT_FUNCTION				1853
#endif
