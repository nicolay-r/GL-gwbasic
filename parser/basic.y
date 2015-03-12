%{
	#include <stdio.h>
%}

%token KEYWORD DECLARATION

/* functional symbols */
%token COLON COMMA SHARP AMPERSANT PERCENT BANG DOLLAR EOLN

/* constants */
%token CONST_INTEGER CONST_FLOAT CONST_STRING

%%
StringVariable: DECLARATION StringVarType { printf("string var"); }
	;
StringVarType: DOLLAR;
%%

int main(int argc, char **argv)
{
	yyparse();	
}

yyerror(char *s)
{
	fprintf(stderr, "error %s\n", s);
} 
