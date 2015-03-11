#ifndef __BASIC_LEX_H__

#define __BASIC_LEX_H__

#define YYSTYPE TokenValues

// for yyval
typedef union {
	int number;
	char* str;
} TokenValues;

#endif
