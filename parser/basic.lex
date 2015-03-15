%option noyywrap

%{
	#include <stdio.h>
	#include "basic.lex.h"
	#include "basic.tab.h"
%}

LETTER		[a-zA-Z]
NUMBER		[0-9]+
DECLARATION	{LETTER}({LETTER}|{NUMBER}|\.)*

%%

[\t\r ]+

\n			{ return EOLN;	}

RUN			{ return RUN; }
SYSTEM			{ return SYSTEM; }
AUTO			{ return AUTO; }
BLOAD			{ return BLOAD; }
BSAVE			{ return BSAVE; }
MERGE			{ return MERGE; }
CHDIR			{ return CHDIR; }
CLEAR			{ return CLEAR; }
CONT			{ return CONT; }
DELETE			{ return DELETE; }
EDIT			{ return EDIT; }
FILES			{ return FILES; }
KILL			{ return KILL; }
LIST			{ return LIST; }
LLIST			{ return LLIST; }
LOAD			{ return LOAD; }
NAME			{ return NAME; }
MKDIR			{ return MKDIR; }
TRON			{ return TRON; }
TROFF			{ return TROFF; }

BEEP			{ return BEEP; }
CALL			{ return CALL; }
DIM			{ return DIM; }

=			{ return EQUAL; }
\<\>			{ return INEQUAL; }
\<			{ return LT; }
\>			{ return GT; }
\<=			{ return LTE; }
\>=			{ return GTE; }

NOT			{ return NOT; }
AND			{ return AND; }
OR			{ return OR; }
XOR			{ return XOR; }
EQV			{ return EQV; }


SIN			{ return SIN; }

AS			{ return AS; }

\. |
,  |	
:  |
&  |
#  |
%  |
!  |
\$ |
\( |
\) |
-  |
\+ |
\* |
\/ |
\^ 			{ return yytext[0]; }

{NUMBER}\.{NUMBER}*	{ return CONST_FLOAT; }
{NUMBER}+		{
				yylval.int_number = atoi(yytext);	 
				return CONST_INTEGER; 
			}

\"[^\"]+\"		{ return CONST_STRING; }
	
{DECLARATION}		{ return DECLARATION; /* ref. 6.2.1 */ }	

%%

/*
// for debug purposes
int main(int argc, char **argv)
{
	yylex();
}
*/
