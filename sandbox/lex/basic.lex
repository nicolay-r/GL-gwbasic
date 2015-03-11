%option noyywrap

%{
	#include "basic.lex.h"

	union TokenValues {
		int number;
		char* str;
	};
	union TokenValues yylval;
%}

%%

helloworld	{
			yylval.number = -1;
			printf("TOKEN: helloworld!\n");
			return HELLOWORLD;
		}
[0-9]+		{
			yylval.number = atoi(yytext);
			printf("TOKEN: number\n");
			return NUMBER;
		}

%%

main (int argc, char ** argv)
{
	int tok;
	while (tok = yylex())
	{
		printf("token: %d\n", tok);
	}
}

