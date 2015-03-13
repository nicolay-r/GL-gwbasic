%{
	#include <stdio.h>

	char* ne = "Not Implemented";
%}
/* command keywords*/
%token RUN SYSTEM AUTO BLOAD BSAVE MERGE CHDIR CLEAR CONT DELETE EDIT FILES KILL LIST LLIST LOAD MKDIR NAME

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
	| System
	| Auto
	| BLoad
	| BSave
	| Merge
	| ChDir
	| Clear
	| Cont
	| Delete
	| Edit					{ printf("EDIT %s\n", ne); }
	| Files					{ printf("FILES %s\n", ne); }
	| Kill					{ printf("KILL %s\n", ne); }
	| List					{ printf("LIST %s\n", ne); }
	| LList
	| Load
	| MkDir
	| Name
;
Statements: Statement COMMA Statements
	| Statement
	;
Statement: StringVariable  			{ printf("EXPR\n"); }
	
StringVariable: DECLARATION StringVarType 	{ printf("string var"); }

Run:	RUN
System:	SYSTEM					{ printf("bye!\n"); }
Auto:	AUTO LineNumber COMMA Increment		{ printf("AUTO %s\n", ne); }
BLoad: 	BLOAD FileName COMMA Offset		{ printf("BLOAD %s\n", ne); }
BSave:	BSAVE FileName COMMA Offset COMMA Length { printf("BSAVE %s\n", ne); }
Merge:	MERGE FileName				{ printf("CLEAR %s\n", ne); }
ChDir:	CHDIR					{ printf("CHDIR %s\n", ne); }
Clear:	CLEAR Expression			{ printf("CLEAR %s\n", ne); }
Cont:	CONT					{ printf("CONT %s\n", ne); }
Delete:	DELETE LineNumber Dash LineNumber	{ printf("DELETE %s\n", ne); }
	| DELETE LineNumber Dash		{ printf("DELETE %s\n", ne); } 
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
