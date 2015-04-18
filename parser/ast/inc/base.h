/* GWBasic base types */

#ifndef _GWBN_BASE_H_
#define _GWBN_BASE_H_

/*
	Types
*/
#define GWBB_INTEGER	1
#define GWBB_SINGLE	2
#define GWBB_DOUBLE	3
#define GWBB_STRING	4

#define GWBB_ADD			100
#define GWBB_SUB			101
#define GWBB_MUL			102
#define GWBB_DIV			103
#define GWBB_POW			104
#define GWBB_UNARY_MINUS		105

/*
	Typedefs
*/
typedef short GWBB_Integer;
typedef float GWBB_Single;
typedef double GWBB_Double;
typedef char* GWBB_String;

#endif
