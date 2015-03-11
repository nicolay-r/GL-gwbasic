%{
	#include <stdio.h>
	#include "basic.lex.h"
%}
%token HELLOWORLD
%token NUMBER

%%
helloAndNumber: HELLOWORLD NUMBER	{
						printf("RULE: You use %s with number %d", $1.str, $2.number);
					}
		;

%%

main (int argc, char** argv)
{
	yyparse();
}

yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
}
