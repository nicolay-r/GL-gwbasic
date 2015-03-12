%option noyywrap

%{
	#include <stdio.h>
	#include "basic.tab.h"
%}

LETTER		[a-zA-Z]
NUMBER		[0-9]+
DECLARATION	{LETTER}({LETTER}|{NUMBER}|\.)*

%%
[\n ]+

\t			{ return EOLN;	}

,			{ return COMMA;	}
:			{ return COLON; }
&			{ return AMPERSANT; }
#			{ return SHARP; }
%			{ return PERCENT; }
!			{ return BANG;	}
\$			{ return DOLLAR; }

{NUMBER}\.{NUMBER}*	{ return CONST_FLOAT; }
{NUMBER}+		{ return CONST_INTEGER; }

\"[^\"]\"		{ return CONST_STRING; }
	
{DECLARATION}		{ return DECLARATION; /* ref. 6.2.1 */ }	
%%

/*
// for debug purposes
int main(int argc, char **argv)
{
	yylex();
}
*/
