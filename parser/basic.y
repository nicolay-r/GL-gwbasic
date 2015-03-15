%{
	#include <stdio.h>
	#include "basic.lex.h"		// for YYTYPE structure
	char* ne = "Not Implemented";
%}
/* command keywords*/
%token RUN SYSTEM AUTO BLOAD BSAVE MERGE CHDIR CLEAR CONT DELETE EDIT FILES KILL LIST LLIST LOAD MKDIR NAME TRON TROFF

%token BEEP CALL DIM

%token AS

%token DECLARATION

%token GT LT GTE LTE EQUAL INEQUAL
%token NOT AND OR XOR IMP EQV

/* Math functions*/
%token SIN
/* functional symbols */
%token COLON COMMA SHARP AMPERSANT PERCENT BANG DOLLAR DOT EOLN

/* constants */
%token CONST_INTEGER CONST_FLOAT CONST_STRING

/* Arithmetic precedence */
%left '+' '-'
%left '*' '/'
%left '^'
%nonassoc UMINUS
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

Statements: Statement COMMA Statements		{ printf("-List Of Statements\n"); }
	| Statement				{ printf("-Statement\n"); }

Statement: Beep					{ printf("BEEP %s\n", ne); }
	| Call					{ printf("CALL %s\n", ne); }
	| Expression				{ printf("Expression\n"); }	
	| Dim					{ printf("DIM %s\n", ne); }

Run:	RUN
System:	SYSTEM
Auto:	AUTO LineNumber COMMA Increment
BLoad: 	BLOAD FileName COMMA Offset
	| BLOAD FileName
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


Beep:	BEEP
Call:	CALL '('  Variables ')'
Dim:	DIM ArrayVariables



ArrayVariables: ArrayVariable COMMA ArrayVariables
	| ArrayVariable
Variables: Variable COMMA Variables
	| Variable

Variable: StringVariable
	| NumericVariable
	| ArrayVariable

StringVariable: DECLARATION DOLLAR

NumericVariable: IntegerVariable
	| SinglePrecisionVariable
	| DoublePrecisionVariable

ArrayVariable: DECLARATION '(' ConstIntegers ')'
IntegerVariable: DECLARATION PERCENT
SinglePrecisionVariable: DECLARATION BANG
DoublePrecisionVariable: DECLARATION SHARP

ConstIntegers: CONST_INTEGER COMMA ConstIntegers
	| CONST_INTEGER

Expression: Operator

StringConstant:	CONST_STRING
NumericConstant: CONST_INTEGER
	| CONST_FLOAT

Operator: ArithmeticOperator
	| RelationalOperator
	| LogicalOperator
	| FunctionalOperator
	| StringOperator

ArithmeticOperator: ArithmeticOperator Add ArithmeticOperator	{ printf("A + B\n"); }
	| ArithmeticOperator Sub ArithmeticOperator		{ printf("A - B\n"); }
	| ArithmeticOperator Mul ArithmeticTerm			{ printf("A * B\n"); }
	| ArithmeticOperator Divide ArithmeticTerm		{ printf("A / B\n"); }
	| ArithmeticOperator Exponent ArithmeticTerm		{ printf("A ^ B\n"); }
	| ArithmeticTerm

ArithmeticTerm: '(' ArithmeticOperator ')'			{ printf("(Exp)\n"); } 
	| Negation ArithmeticOperator %prec UMINUS		{ printf("Unary minus\n"); }	
	| NumericVariable					{ printf("%s\n", $1.str); }
	| NumericConstant 					{ printf("%d\n", $1.int_number); }

StringOperator:	StringOperator Add StringOperator
	| StringVariable
	| StringConstant

RelationalOperator: ArithmeticOperator EQUAL ArithmeticOperator
	| ArithmeticOperator INEQUAL ArithmeticOperator
	| ArithmeticOperator LT	ArithmeticOperator
	| ArithmeticOperator GT ArithmeticOperator  
	| ArithmeticOperator LTE ArithmeticOperator
	| ArithmeticOperator GTE ArithmeticOperator   
	| StringOperator EQUAL StringOperator
	| StringOperator INEQUAL StringOperator
	| StringOperator LT StringOperator
	| StringOperator LTE StringOperator
	| StringOperator GTE StringOperator

LogicalOperator: NOT RelationalOperator
	| RelationalOperator AND RelationalOperator
	| RelationalOperator OR RelationalOperator
	| RelationalOperator XOR RelationalOperator
	| RelationalOperator EQV RelationalOperator
	| RelationalOperator IMP RelationalOperator

FunctionalOperator: SIN '(' ArithmeticOperator ')'

Negation: '-';
Exponent: '^';
Dash: '-';
Mul: '*';
Divide: '/';
Add: '+';
Sub: '-';
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
