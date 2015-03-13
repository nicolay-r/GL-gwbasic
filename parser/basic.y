%{
	#include <stdio.h>

	char* ne = "Not Implemented";
%}
/* command keywords*/
%token RUN SYSTEM AUTO BLOAD BSAVE MERGE CHDIR CLEAR CONT DELETE EDIT FILES KILL LIST LLIST LOAD MKDIR NAME TRON TROFF

%token AS

%token DECLARATION
/* Arithmetic operations */
%token SUB
/* functional symbols */
%token COLON COMMA SHARP AMPERSANT PERCENT BANG DOLLAR DOT EOLN

/* constants */
%token CONST_INTEGER CONST_FLOAT CONST_STRING

%%
GWBasicInterpreter: DirectMode			{ printf("-direct mode\n"); return 0; }
		| IndirectMode			{ printf("-indirect mode\n"); return 0; }
		;
IndirectMode: LineNumber Statements
DirectMode: Command EOLN			{ printf("-command\n"); }
	| Statements EOLN
	;
Command: Run
	| System				{ printf("SYSTEM %s\n", ne); }
	| Auto					{ printf("AUTO  %s\n", ne); }
	| BLoad					{ printf("BLOAD %s\n", ne); }
	| BSave					{ printf("BSAVE %s\n", ne); }
	| Merge					{ printf("MERGE %s\n", ne); }
	| ChDir					{ printf("CHDIR %s\n", ne); }
	| Clear					{ printf("CLEAR %s\n", ne); }
	| Cont					{ printf("CONT %s\n", ne); }
	| Delete				{ printf("DELETE %s\n", ne); }
	| Edit					{ printf("EDIT %s\n", ne); }
	| Files					{ printf("FILES %s\n", ne); }
	| Kill					{ printf("KILL %s\n", ne); }
	| List					{ printf("LIST %s\n", ne); }
	| LList					{ printf("LLIST %s\n", ne); }
	| Load					{ printf("LOAD %s\n", ne); }
	| MkDir					{ printf("MKDIR %s\n", ne); }
	| Name					{ printf("NAME %s\n", ne); }
	| TrOn					{ printf("TRON %s\n", ne); }
	| TrOff					{ printf("TROFF %s\n", ne); }
;
Statements: Statement COMMA Statements
	| Statement
	;
Statement: StringVariable  			{ printf("EXPR\n"); }
	
StringVariable: DECLARATION StringVarType 	{ printf("string var"); }

Run:	RUN
System:	SYSTEM
Auto:	AUTO LineNumber COMMA Increment
BLoad: 	BLOAD FileName COMMA Offset
BSave:	BSAVE FileName COMMA Offset COMMA Length
Merge:	MERGE FileName
ChDir:	CHDIR
Clear:	CLEAR Expression			
Cont:	CONT					
Delete:	DELETE LineNumber Dash LineNumber	
	| DELETE LineNumber Dash	
Edit: 	EDIT LineNumber
	| EDIT DOT
Files:	FILES FilePath
	| FILES					
Kill: 	KILL FileName
List:	LineNumber Dash LineNumber COMMA FileName
	| LineNumber Dash COMMA FileName
	| LineNumber Dash LineNumber
	| LineNumber Dash			
LList:	LLIST LineNumber Dash LineNumber
	| LLIST LineNumber Dash
Load:	LOAD FileName COMMA LoadOption
	| LOAD FileName
MkDir: MKDIR PathName
Name: NAME OldFileName AS NewFileName
TrOn:	TRON
TrOff:	TROFF

Expression: CONST_INTEGER;

StringVarType: DOLLAR;
Dash: SUB

LoadOption: DECLARATION;
FilePath: CONST_STRING;
PathName: CONST_STRING;
FileName: CONST_STRING;
OldFileName: CONST_STRING;
NewFileName: CONST_STRING;
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
