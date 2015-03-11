%option noyywrap

%{
	#include "basic.lex.h"
	#include "basic.tab.h"
%}

%%

helloworld	{
			yylval.str = "HELLOWORLD";
			printf("TOKEN: helloworld!\n");
			return HELLOWORLD;
		}
[0-9]+		{
			yylval.number = atoi(yytext);
			printf("TOKEN: number\n");
			return NUMBER;
		}

%%
/*
main (int argc, char ** argv)
{
	int tok;
	while (tok = yylex())
	{
		printf("token: %d\n", tok);
	}
}
*/
