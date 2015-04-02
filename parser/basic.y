%{
	#include <stdio.h>

	char* ne = "Not Implemented";

	/*
		Connection with the yylex structures:
		yy_scan_string, and yy_delete_buffer
	*/	
	typedef struct yy_buffer_state * YY_BUFFER_STATE;
	extern YY_BUFFER_STATE yy_scan_string(char *str);
	extern void yy_delete_buffer(YY_BUFFER_STATE buffer);
%}
/* command keywords*/
%token RUN SYSTEM AUTO BLOAD BSAVE MERGE CHDIR CLEAR CONT DELETE EDIT FILES KILL LIST LLIST LOAD MKDIR NAME TRON TROFF

%token BEEP CALL DIM OPTION BASE LET DEF FN CIRCLE SCREEN LINE

%token AS

%token DECLARATION

%token GT LT GTE LTE EQUAL INEQUAL
%token NOT AND OR XOR IMP EQV

/* Math functions*/
%token SIN
/* Specific Symbols */
%token EOLN

/* constants */
%token CONST_INTEGER CONST_FLOAT CONST_STRING

/* Arithmetic precedence */
%left GT LT GTE LTE EQUEAL INEQUAL
%left IMP EQV
%left XOR
%left OR
%left AND
%nonassoc NOT
%left '+' '-'
%left '*' '/'
%left '^'
%nonassoc UMINUS

/* Type declaration */
%code requires {
	#include "ast/interp.h"	
	#include "ast/expr.h"
}

%parse-param {Interpreter** interpreter}

%union {
	Interpreter* 			interpreter;
	DirectMode*			directMode;
	IndirectMode* 			indirectMode;
	Command*			command;
	
	Auto*				_auto;

	/* expressions */	
	GWBN_Expression*		expr;
	//GWBN_NumericExpression*	num_expr;
	//GWBN_StringOperator*		str_op;


	/* integer constant */
	int 				int_number;
	
	/* fractional constants */
	float 				float_number;
	double 				double_number;
	
	/* keywords, commands, constant string, etc.*/ 
	char *str;
}

%type <interpreter> Interpreter
%type <directMode> DirectMode
%type <indirectMode> IndirectMode
%type <command> Command
%type <_auto> Auto

%type <expr> Expression
/*
%type <num_expr> NumericExpression
%type <str_op> StringOperator
*/
%type <int_number> LineNumber Increment CONST_INTEGER

%%

Interpreter: DirectMode				{
							union InterpreterMode mode; mode.direct = $1;
							$$ = gwbn_Interpreter(GWBNT_DIRECT_MODE, mode);
							*interpreter = $$;
							return 0;							
						}
	| IndirectMode				{
							union InterpreterMode mode; mode.indirect = $1;
							$$ = gwbn_Interpreter(GWBNT_INDIRECT_MODE, mode);
							*interpreter = $$;
							return 0; 
						}
IndirectMode: LineNumber Statements		{	printf("-IndirectMode");
							$$ = gwbn_IndirectMode($1, NULL);	
						}
DirectMode: Command EOLN			{ 	printf("-DirectMode\n");
							union DirectModeOperation op; op.command = NULL;	
							$$ = gwbn_DirectMode(GWBNT_COMMAND, op);
						}
	| Statements EOLN			{	printf("-Statements\n");
							union DirectModeOperation op; op.statements = NULL;
							$$ = gwbn_DirectMode(GWBNT_STATEMENT, op);
						}
Command: Run
	| System				{ printf("SYSTEM %s\n", ne); }
	| Auto					{ 
							union Commands cmds; cmds._auto = $1;
							$$ = gwbn_Command(GWBNT_AUTO, cmds); 
						}
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

Statements: Statement ':' Statements		{ }
	| Statement				{ printf("-Statement\n"); }

Statement: Beep					{ printf("BEEP %s\n", ne); }
	| Call					{ printf("CALL %s\n", ne); }	
	| Dim					{ printf("DIM %s\n", ne); }
	| Let					{ printf("LET %s\n", ne); }
	| OptionBase				{ printf("OPTION BASE %s\n", ne); }
	| DefFn					{ printf("DEF FN %s\n", ne); }
	| Circle				{ printf("CIRCLE %s\n", ne); }
	| Screen				{ printf("SCREEN %s\n", ne); }
	| Line					{ printf("LINE %s\n", ne); }

Run:	RUN
System:	SYSTEM
Auto:	AUTO LineNumber ',' Increment		{ $$ = gwbn_Auto($2, $4); }
BLoad: 	BLOAD FileName ',' Offset
	| BLOAD FileName
BSave:	BSAVE FileName ',' Offset ',' Length
Merge:	MERGE FileName
ChDir:	CHDIR
Clear:	CLEAR Expression			
Cont:	CONT					
Delete:	DELETE LineNumber Dash LineNumber	
	| DELETE LineNumber Dash	
Edit: 	EDIT LineNumber
	| EDIT '.'
Files:	FILES FilePath
	| FILES					
Kill: 	KILL FileName
List:	LineNumber Dash LineNumber ',' FileName
	| LineNumber Dash ',' FileName
	| LineNumber Dash LineNumber
	| LineNumber Dash			
LList:	LLIST LineNumber Dash LineNumber
	| LLIST LineNumber Dash
Load:	LOAD FileName ',' LoadOption
	| LOAD FileName
MkDir: 	MKDIR PathName
Name:	NAME OldFileName AS NewFileName
TrOn:	TRON
TrOff:	TROFF

Beep:	BEEP
Call:	CALL '('  Variables ')'
Dim:	DIM ArrayVariables
OptionBase: OPTION BASE NumericConstant
Let: 	LET Variable EQUAL Expression
	| Variable EQUAL Expression
DefFn:	DEF FN VariableName '(' FunctionArguments ')' EQUAL Expression
	| DEF FN VariableName EQUAL Expression
Circle:	CIRCLE '(' ScreenCoord ',' ScreenCoord ')' CircleRadius CircleOptions 
CircleOptions: 
	| ',' CircleColor
	| ',' CircleColor ',' CircleStart
	| ',' ',' CircleStart
	| ',' CircleColor ',' CircleStart ',' CircleEnd
	| ',' ',' CircleStart ',' CircleEnd
	| ',' ',' ',' CircleEnd 
	| ',' CircleColor ',' CircleStart ',' CircleEnd ',' CircleAspect
	| ',' ',' CircleStart ',' CircleEnd ',' CircleAspect
	| ',' ',' ',' CircleEnd ',' CircleAspect
	| ',' ',' ',' ',' CircleAspect
CircleRadius: VariableName
	| NumericConstant
CircleColor: VariableName
	| NumericConstant
CircleStart: VariableName
	| NumericConstant
CircleEnd: VariableName
	| NumericConstant
CircleAspect: VariableName
	| NumericConstant

Screen: SCREEN ScreenMode
ScreenMode: CONST_INTEGER

Line: LINE '(' ScreenCoord ',' ScreenCoord ')' '-' '(' ScreenCoord ',' ScreenCoord ')' LineOptions
	| LINE '-' '(' ScreenCoord ',' ScreenCoord ')' LineOptions
LineOptions: 
	| ',' LineColor
	| ',' LineColor ',' FillingFormat 
	| ',' ',' FillingFormat
FillingFormat: DECLARATION 
LineColor: Expression



ScreenCoord: VariableName
	| NumericConstant


FunctionArguments: VariableName ',' FunctionArguments
	| VariableName

ArrayVariables: ArrayVariable ',' ArrayVariables
	| ArrayVariable

Variables: Variable ',' Variables
	| Variable

Variable: StringVariable
	| NumericVariable
	| ArrayVariable

StringVariable: VariableName '$'				{ printf("-String decl\n");}
NumericVariable: IntegerVariable
	| SinglePrecisionVariable
	| DoublePrecisionVariable
ArrayVariable: DECLARATION '(' ConstIntegers ')'		{ printf("-Array decl\n"); }
IntegerVariable: DECLARATION '%'				{ printf("-Integer decl\n"); }
SinglePrecisionVariable: DECLARATION '!'			{ printf("-Single var decl\n"); }
DoublePrecisionVariable: DECLARATION '#'			{ printf("-Double var decl\n");}

ConstIntegers: CONST_INTEGER ',' ConstIntegers
	| CONST_INTEGER

Expression: NumericExpression					{ 
									printf("-Numeric Expression\n"); 
									$$ = gwbn_NewExpression();
								}
	| StringOperator					{ 
									printf("-String Operator\n"); 
									$$ = gwbn_NewExpression();
								}

NumericExpression : ArithmeticOperator
	| RelationalOperator
	| LogicalOperator
	| FunctionalOperator

ArithmeticOperator: NumericExpression '+' NumericExpression	{ printf("A + B\n"); }
	| NumericExpression '-' NumericExpression		{ printf("A - B\n"); }
	| NumericExpression '*' NumericTerm			{ printf("A * B\n"); }
	| NumericExpression '/' NumericTerm			{ printf("A / B\n"); }
	| NumericTerm

NumericTerm: '(' NumericExpression ')'				{ printf("(Exp)\n"); } 
	| '-' NumericTerm %prec UMINUS				{ printf("Unary minus\n"); }	
	| NumericTerm '^' NumericTerm				{ printf("A ^ B\n"); }
	| NumericVariable					{ /*printf("%s\n", $1.str);*/ }
	| NumericConstant 					{ /*printf("%d\n", $1.int_number);*/ }

StringOperator:	StringOperator '+' StringOperator		{ printf("S1 + S2\n"); }
	| StringVariable					{ printf("String Variable\n"); }
	| StringConstant					{ printf("String Constant\n"); }

StringConstant:	CONST_STRING
NumericConstant: CONST_INTEGER
	| CONST_FLOAT

RelationalOperator: ArithmeticOperator EQUAL ArithmeticOperator	{ printf("A = B\n"); }
	| ArithmeticOperator INEQUAL ArithmeticOperator		{ printf("A <> B\n"); }
	| ArithmeticOperator LT	ArithmeticOperator		{ printf("A < B\n"); } 
	| ArithmeticOperator GT ArithmeticOperator 		{ printf("A > B\n"); } 
	| ArithmeticOperator LTE ArithmeticOperator		{ printf("A <= B\n"); } 
	| ArithmeticOperator GTE ArithmeticOperator  		{ printf("A >= B\n"); } 
	| StringOperator EQUAL StringOperator			{ printf("S1 = S2\n"); } 
	| StringOperator INEQUAL StringOperator			{ printf("S1 <> S2\n"); } 
	| StringOperator LT StringOperator			{ printf("S1 < S2\n"); } 
	| StringOperator LTE StringOperator			{ printf("S1 <= S2\n"); } 
	| StringOperator GTE StringOperator			{ printf("S1 >= S2\n"); } 

LogicalOperator: NOT RelationalOperator				{ printf("NOT A\n"); } 
	| RelationalOperator AND RelationalOperator		{ printf("A AND B\n"); } 
	| RelationalOperator OR RelationalOperator		{ printf("A OR B\n"); } 
	| RelationalOperator XOR RelationalOperator		{ printf("A XOR B\n"); } 
	| RelationalOperator EQV RelationalOperator		{ printf("A EQV B\n"); } 
	| RelationalOperator IMP RelationalOperator		{ printf("A IMP B\n"); } 

FunctionalOperator: SIN '(' ArithmeticOperator ')'


Dash: '-';
VariableName: DECLARATION;
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

/*
	GWBasic syntax Analyzer
*/
yyerror(char *s)
{
	fprintf(stderr, "error %s\n", s);
}

/*
	GWBasic program parser from char* buffer
*/
Interpreter* gwbp_Parse(char* sourceCode)
{
	Interpreter** interpreter = (Interpreter**) malloc (sizeof(Interpreter*));

	YY_BUFFER_STATE buffer = yy_scan_string(sourceCode);
	yyparse(interpreter);
	yy_delete_buffer(buffer);
	
	Interpreter* result = *interpreter;
	free(interpreter);
	return result; 
}	
