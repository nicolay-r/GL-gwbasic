%option noyywrap

%{
	#include <stdio.h>
	#include "basic.tab.h"
%}

LETTER		[a-zA-Z]
NUMBER		[0-9]+
DECLARATION	{LETTER}({LETTER}|{NUMBER}|\.)*

%%

[\t\r ]+

\n			{ return EOLN;	}

(?i:RUN)		{ return RUN; }
(?i:SYSTEM)		{ return SYSTEM; }
(?i:AUTO)		{ return AUTO; }
(?i:BLOAD)		{ return BLOAD; }
(?i:BSAVE)		{ return BSAVE; }
(?i:MERGE)		{ return MERGE; }
(?i:CHDIR)		{ return CHDIR; }
(?i:CLEAR)		{ return CLEAR; }
(?i:CONT)		{ return CONT; }
(?i:DELETE)		{ return DELETE; }
(?i:EDIT)		{ return EDIT; }
(?i:FILES)		{ return FILES; }
(?i:KILL)		{ return KILL; }
(?i:LIST)		{ return LIST; }
(?i:LLIST)		{ return LLIST; }
(?i:LOAD)		{ return LOAD; }
(?i:NAME)		{ return NAME; }
(?i:MKDIR)		{ return MKDIR; }
(?i:TRON)		{ return TRON; }
(?i:TROFF)		{ return TROFF; }

(?i:BEEP)		{ return BEEP; }
(?i:CALL)		{ return CALL; }
(?i:DIM)		{ return DIM; }
(?i:LET)		{ return LET; }
(?i:OPTION)		{ return OPTION; }
(?i:BASE)		{ return BASE; }
(?i:DEF)		{ return DEF; }
(?i:FN)			{ return FN; }
(?i:CIRCLE)		{ return CIRCLE; }
(?i:LINE)		{ return LINE; }
(?i:PAINT)		{ return PAINT; }
(?i:SCREEN)		{ return SCREEN; }
(?i:PSET)		{ return PSET; }
(?i:PRESET)		{ return PRESET; }
(?i:CLS)		{ return CLS; }

(?i:FOR)		{ return FOR; }
(?i:NEXT)		{ return NEXT; }
(?i:GOSUB)		{ return GOSUB; }
(?i:RETURN)		{ return RETURN; }
(?i:GOTO)		{ return GOTO; }
(?i:IF)			{ return IF; }
(?i:THEN)		{ return THEN; }
(?i:ELSE)		{ return ELSE; }
(?i:INPUT)		{ return INPUT; }
(?i:PRINT)		{ return PRINT; }
(?i:LOCATE)		{ return LOCATE; }
(?i:MID)		{ return MID; }

(?i:LEFT$)		{ return LEFT_STR; }
(?i:MID$)		{ return MID_STR; }
(?i:RIGHT$)		{ return RIGHT_STR; }

=			{ return EQUAL; }
\<\>			{ return INEQUAL; }
\<			{ return LT; }
\>			{ return GT; }
\<=			{ return LTE; }
\>=			{ return GTE; }

(?i:NOT)		{ return NOT; }
(?i:AND)		{ return AND; }
(?i:OR)			{ return OR; }
(?i:XOR)		{ return XOR; }
(?i:EQV)		{ return EQV; }

(?i:ABS)		{ return ABS; }
(?i:EXP)		{ return EXP; }
(?i:TAN)		{ return TAN; }
(?i:SIN)		{ return SIN; }
(?i:COS)		{ return COS; }
(?i:LOG)		{ return LOG; }
(?i:FIX)		{ return FIX; }
(?i:INT)		{ return INT; }
(?i:CINT)		{ return CINT; }
(?i:SGN)		{ return SGN; }
(?i:SQR)		{ return SQR; }
(?i:RND)		{ return RND; }

(?i:ASC)		{ return ASC; }
(?i:LEN)		{ return LEN; }

(?i:EXTERR)		{ return EXTERR; }

(?i:AS)			{ return AS; }
(?i:TO)			{ return TO; }
(?i:STEP)		{ return STEP; }
(?i:ON)			{ return ON; }
(?i:ERROR)		{ return ERROR; }

\? |
;  |
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
\^ 			{
				return yytext[0]; 
			}

{NUMBER}\.{NUMBER}*	{ 
				yylval.float_num = atof(yytext);
				return CONST_FLOAT; 
			}
{NUMBER}+		{
				yylval.int_num = atoi(yytext);	 
				return CONST_INTEGER; 
			}

\"[^\"]*\"		{ 
				yytext[strlen(yytext)-1] = 0;
				yylval.str = strdup(&yytext[1]);
				return CONST_STRING; 
			}
	
{DECLARATION}		{ 
				yylval.str = strdup(yytext);
				return DECLARATION; 	/* ref. 6.2.1 */ 
			}	

%%

/*
// for debug purposes
int main(int argc, char **argv)
{
	yylex();
}
*/
