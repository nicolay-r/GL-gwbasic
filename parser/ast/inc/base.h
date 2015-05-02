/* GWBasic base types */

#ifndef _GWBN_BASE_H_
#define _GWBN_BASE_H_

/*
	Types
*/
#define GWBBT_INTEGER			1
#define GWBBT_SINGLE			2
#define GWBBT_DOUBLE			3
#define GWBBT_STRING			4

#define GWBBT_ADD			100
#define GWBBT_SUB			101
#define GWBBT_MUL			102
#define GWBBT_DIV			103
#define GWBBT_POW			104
#define GWBBT_UNARY_MINUS		105
#define GWBBT_EQUAL			106
#define GWBBT_INEQUAL			107
#define GWBBT_LT			108
#define GWBBT_GT			109
#define GWBBT_GTE			110
#define GWBBT_LTE			111

#define GWBBT_COMMA			200
#define GWBBT_SEMICOLON			201
/*
	Typedefs
*/
typedef short GWBB_Integer;
typedef float GWBB_Single;
typedef double GWBB_Double;
typedef char* GWBB_String;

#endif
