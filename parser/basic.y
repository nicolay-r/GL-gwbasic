%{
	#include <stdio.h>

	char* ne = "Not Implemented";
%}
/* command keywords*/
%token RUN SYSTEM AUTO BLOAD BSAVE MERGE CHDIR CLEAR CONT DELETE

%token DECLARATION
/* Arithmetic operations */
%token SUB
/* functional symbols */
%token COLON COMMA SHARP AMPERSANT PERCENT BANG DOLLAR EOLN

/* constants */
%token CONST_INTEGER CONST_FLOAT CONST_STRING

%%
GWBasicInterpreter: DirectMode			{ printf("-direct mode\n"); return 0; }
		| IndirectMode			{ printf("-indirect mode\n"); return 0; }
		;
IndirectMode: LineNumber Statements
DirectMode: Command EOLN
	| Statements EOLN
	;
Command: Run
	| System
	| Auto
	| BLoad
	| BSave
	| Merge
	| ChDir
	| Clear
	| Cont
	| Delete
	;
Statements: Statement COMMA Statements
	| Statement
	;
Statement: StringVariable  			{ printf("EXPR\n"); }
	
StringVariable: DECLARATION StringVarType 	{ printf("string var"); }

Run:	RUN
System:	SYSTEM					{ printf("bye!\n"); }
Auto:	AUTO LineNumber COMMA Increment		{ printf("AUTO Command %s\n", ne); }
BLoad: 	BLOAD FileName COMMA Offset		{ printf("BLOAD Command %s\n", ne); }
BSave:	BSAVE FileName COMMA Offset COMMA Length { printf("BSAVE Command %s\n", ne); }
Merge:	MERGE FileName				{ printf("CLEAR Command %s\n", ne); }
ChDir:	CHDIR					{ printf("CHDIR Command %s\n", ne); }
Clear:	CLEAR Expression			{ printf("CLEAR Command %s\n", ne); }
Cont:	CONT					{ printf("CONT Command %s\n", ne); }
Delete:	DELETE LineNumber Dash LineNumber	{ printf("DELETE command %s\n", ne); }
	| DELETE LineNumber Dash		{ printf("DELETE Command %s\n", ne); } 


Expression: CONST_INTEGER;

StringVarType: DOLLAR;
Dash: SUB

FileName: CONST_STRING;
LineNumber: CONST_INTEGER;
Increment: CONST_INTEGER;
Offset: CONST_INTEGER;
Length: CONST_INTEGER;
%%

int main(int argc, char **argv)
{
	while (1)
	{
		yyparse();	
	}
}

yyerror(char *s)
{
	fprintf(stderr, "error %s\n", s);
} 
