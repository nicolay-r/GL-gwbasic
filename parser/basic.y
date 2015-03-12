%{
	#include <stdio.h>
%}
/* command keywords*/
%token RUN SYSTEM

%token DECLARATION

/* functional symbols */
%token COLON COMMA SHARP AMPERSANT PERCENT BANG DOLLAR EOLN

/* constants */
%token CONST_INTEGER CONST_FLOAT CONST_STRING

%%
GWBasicInterpreter: DirectMode
		| IndirectMode
		;
IndirectMode: LineNumber Statements		{ printf("indirect mode"); }
DirectMode: Command EOLN			{ printf("direct mode"); }
	| Statements EOLN
	;
Command: RUN
	| SYSTEM				{ printf("bye!\n"); return 0; }
	;
Statements: Statement COMMA Statements
	| Statement
	;
Statement: StringVariable  			{ printf("EXPR\n"); }
	
StringVariable: DECLARATION StringVarType 	{ printf("string var"); }
	;

StringVarType: DOLLAR;
LineNumber: CONST_INTEGER
%%

int main(int argc, char **argv)
{
	yyparse();	
}

yyerror(char *s)
{
	fprintf(stderr, "error %s\n", s);
} 
