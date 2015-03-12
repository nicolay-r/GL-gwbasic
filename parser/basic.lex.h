#ifndef __BASIC_LEX_H__
#define __BASIC_LEX_H__

#define YYSTYPE TokenTypes

typedef union {
	// integer constants
	int int_number;
	
	// fractional constants
	float float_number;
	double double_number;
	
	// keywords, commands, 
	// constant strings, etc.
	char *str;
} TokenTypes;

#endif
