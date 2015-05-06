%{
	#include <stdio.h>
	#include <string.h>

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

%token BEEP CALL DIM OPTION BASE LET DEF FN CIRCLE SCREEN LINE PAINT PSET PRESET CLS FOR NEXT GOSUB RETURN GOTO IF THEN ELSE INPUT PRINT
%token LOCATE MID

%token ABS ASC 
%token CINT COS EXP EXTERR FIX INT LEN LOG SGN TAN
%token LEFT_STR MID_STR RIGHT_STR RND

%token TO STEP AS ON ERROR

%token DECLARATION

%token '$'

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
	
	/*	
		AST Node Types 
	*/
	#include "ast/inc/types.h"
	#include "ast/interp/inc/interp.h"
	#include "ast/interp/funcs/inc/funcs.h"
	#include "ast/interp/funcs/inc/math.h"	
	#include "ast/interp/vars/inc/vars.h"
	#include "ast/interp/expr/inc/expr.h"
	#include "ast/interp/stmts/inc/stmts.h"
	#include "ast/interp/stmts/inc/print.h"

	/*
		Main Parser Prototype (Runtime Requires)	
	*/
	GWBN_Interpreter* gwbp_Parse(char* sourceCode);

}

%parse-param {GWBN_Interpreter** interpreter}

%union {
	/* Interpreter */
	GWBN_Interpreter* 		interpreter;
	GWBN_DirectMode*		directMode;
	GWBN_IndirectMode* 		indirectMode;
	
	/* Commands */
	GWBN_Command*			command;	
	GWBN_Run*			run;
	Auto*				_auto;

	/* Statements */
	GWBN_Statements*		statements;
	GWBN_Statement*			statement;
	//GWBN_Beep*			beep;
	GWBN_Let*			let;
	GWBN_Print*			print;
	GWBN_PrintExpressions*		print_exprs;
	GWBN_Input*			input;
	GWBN_InputPrompt*		input_prompt;
	GWBN_Goto*			_goto;	
	GWBN_IfThenElse*		if_then_else;
	GWBN_Then*			then;
	GWBN_Else*			_else;	
	GWBN_For*			_for;
	GWBN_Next*			next;

	/* Expressions */	
	GWBN_Expression*		expr;
	GWBN_NumericExpression*		num_expr;
	GWBN_ArithmeticOperator*	arithm_op;
	GWBN_NumericTerm*		num_term;
	GWBN_StringExpression*		str_expr;
	GWBN_StringOperator*		str_op;
	GWBN_StringTerm*		str_term;
	GWBN_RelationalOperator*	rel_op;
	GWBN_LogicalOperator*		log_op;
	GWBN_FunctionalOperator*	func_op;
	GWBN_GoSub*			gosub;
	GWBN_Return*			_return;

	/* Variable */
	GWBN_Variables*			variables;
	GWBN_Variable*			variable;
	GWBN_NumericVariable*		num_var;
	GWBN_StringVariable*		str_var;
	GWBN_ArrayVariable*		arr_var;

	/* Functions */
	GWBN_MathFunction*		math_func;
	GWBN_Abs*			abs;
	GWBN_Sin*			sin;
	GWBN_Cos*			cos;
	GWBN_Exp*			exp;
	GWBN_Tan*			tan;
	GWBN_Log*			log;
	GWBN_Fix*			fix;
	GWBN_Int*			_int;
	GWBN_CInt*			cint;
	GWBN_Sgn*			sgn;	
	GWBN_Rnd*			rnd;
	/* Constants */
	GWBN_NumericConstant*		num_const;
	int 				int_num;
	float 				float_num;
	double 				double_num;
	char*				str;
	int				term_type;
}

%type <interpreter> Interpreter
%type <directMode> DirectMode
%type <indirectMode> IndirectMode
%type <command> Command

/*
	Commands
*/
%type <_auto> Auto
%type <run> Run

/*
	Statements
*/
%type <statements> Statements
%type <statement> Statement
%type <let> Let
%type <print> Print
%type <print_exprs> PrintExpressions
%type <term_type> PrintSeparator
%type <input> Input
%type <input_prompt> InputPrompt
%type <str> InputPromptString
%type <term_type> InputPromptEndType
%type <_goto> Goto
%type <if_then_else> IfThenElse
%type <then> Then
%type <_else> Else
%type <_for> For
%type <next> Next
%type <gosub> GoSub
%type <_return> Return
/*
	Expressions
*/
%type <expr> Expression
%type <num_expr> NumericExpression
%type <arithm_op> ArithmeticOperator
%type <num_term> NumericTerm
%type <str_expr> StringExpression
%type <str_op> StringOperator
%type <str_term> StringTerm
%type <rel_op> RelationalOperator
%type <log_op> LogicalOperator
/*
	%type <func_op> FunctionalOperator
*/
/*
	Variables
*/
%type <variables> Variables;
%type <variable> Variable;
%type <num_var> NumericVariable;
%type <str_var> StringVariable;
%type <arr_var> ArrayVariable;

/*
	Functions
*/
%type <math_func> MathFunction;
%type <abs> Abs;
%type <sin> Sin;
%type <cos> Cos;
%type <exp> Exp;
%type <tan> Tan;
%type <log> Log;
%type <fix> Fix;
%type <_int> Int;
%type <cint> CInt;
%type <sgn> Sgn;
%type <rnd> Rnd;

/*
	Constants
*/
%type <str> DECLARATION CONST_STRING;
%type <float_num> CONST_FLOAT;
%type <num_const> NumericConstant;
/*
%type <num_expr> NumericExpression
%type <str_op> StringOperator
*/
%type <int_num> LineNumber Increment CONST_INTEGER
%%

Interpreter: DirectMode				{
							$$ = gwbn_NewInterpreter();
							$$->type = GWBNT_DIRECT_MODE;
							$$->direct = $1;
							*interpreter = $$;	
							return 0;							
						}
	| IndirectMode				{
							$$ = gwbn_NewInterpreter();
							$$->type = GWBNT_INDIRECT_MODE;
							$$->indirect = $1;
							*interpreter = $$;								
							return 0; 
						}
IndirectMode: LineNumber Statements		{	printf("-IndirectMode\n");
							$$ = gwbn_NewIndirectMode();	
							$$->line_number = $1;
							$$->statements = $2;
						}
DirectMode: Command EOLN			{ 	printf("-DirectMode\n");
							$$ = gwbn_NewDirectMode();
							$$->type = GWBNT_COMMAND;
							$$->command = $1;
						}
	| Statements EOLN			{	printf("-Statements\n");
							$$ = gwbn_NewDirectMode();
							$$->type = GWBNT_STATEMENT;
							$$->statements = $1;
						}
	| Function				{	
							$$ = gwbn_NewDirectMode();
						}
Command: Run					{ $$ = gwbn_NewCommand(); $$->type = GWBNT_RUN; $$->run = $1;}
	| System				{
							$$ = gwbn_NewCommand();
							$$->type = GWBNT_SYSTEM;
							/* NULL AST subnode */
						}
	| Auto					{ 
							$$ = gwbn_NewCommand();
							$$->type = GWBNT_AUTO;
							$$->_auto = $1;
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

Statements: Statement ':' Statements		{
							$$ = gwbn_NewStatements();
							$$->stmt = $1;
							$$->next = $3;
						}
	| Statement				{
							$$ = gwbn_NewStatements();
							$$->stmt = $1;
							$$->next = NULL;
						}

Statement: Beep					{ printf("BEEP %s\n", ne); }
	| Call					{ printf("CALL %s\n", ne); }	
	| Dim					{ 
							printf("DIM %s\n", ne); 
						}
	| Let					{ $$ = gwbn_NewStatement(); $$->type = GWBNT_LET; $$->let = $1; }
	| OptionBase				{ printf("OPTION BASE %s\n", ne); }
	| DefFn					{ printf("DEF FN %s\n", ne); }
	| Circle				{ printf("CIRCLE %s\n", ne); }
	| Screen				{ printf("SCREEN %s\n", ne); }
	| Line					{ printf("LINE %s\n", ne); }
	| Paint					{ printf("PAINT %s\n", ne); }
	| Pset					{ printf("PSET %s\n", ne); }
	| Preset				{ printf("PRESET %s\n", ne); }
	| Cls					{ printf("CLS %s\n", ne); }
	| For					{ $$ = gwbn_NewStatement(); $$->type = GWBNT_FOR; $$->_for = $1; }
	| Next					{ $$ = gwbn_NewStatement(); $$->type = GWBNT_NEXT; $$->next = $1; }
	| GoSub					{ printf("GOSUB %s\n", ne); }
	| Return				{ printf("RETURN %s\n", ne); }
	| Goto					{ $$ = gwbn_NewStatement(); $$->type = GWBNT_GOTO; $$->_goto = $1; }
	| IfThenElse				{ $$ = gwbn_NewStatement(); $$->type = GWBNT_IFTHENELSE; $$->if_then_else = $1; }
	| Input					{ $$ = gwbn_NewStatement(); $$->type = GWBNT_INPUT; $$->input = $1; }
	| Print					{ $$ = gwbn_NewStatement(); $$->type = GWBNT_PRINT; $$->print = $1; }
	| LineInput				{ printf("LINE INPUT %s\n", ne); }		
	| Locate				{ printf("LOCATE %s\n", ne); }
	| Mid					{ printf("MID$ %s\n", ne); }
	| OnErrorGoto				{ printf("ON ERROR GOTO %s\n", ne); }
	| OnGosub				{ printf("ON .. GOSUB ..%s\n", ne); }
	| OnGoto				{ printf("ON .. GOTO .. %s\n", ne); }
Run:	RUN					{ $$ = gwbn_NewRun(); }
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
Let: 	LET Variable EQUAL Expression			{ $$ = gwbn_NewLet(); $$->var = $2; $$->expr = $4; }
	| Variable EQUAL Expression			{ $$ = gwbn_NewLet(); $$->var = $1; $$->expr = $3; }
DefFn:	DEF FN VariableName '(' FunctionArguments ')' EQUAL Expression
	| DEF FN VariableName EQUAL Expression
Circle:	CIRCLE '(' ScreenCoord ',' ScreenCoord ')' '-' '(' ScreenCoord ',' ScreenCoord ')' CircleRadius CircleOptions 
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
Paint: PAINT '(' ScreenCoord ',' ScreenCoord ')' PaintOptions
PaintOptions:
	| ',' PaintAttribute
	| ',' PaintAttribute ',' BorderAttribute
	| ',' PaintAttribute ',' BorderAttribute ',' BckgrndAttribute
PaintAttribute: NumericConstant
BorderAttribute: NumericConstant
BckgrndAttribute: NumericConstant


Preset: PRESET '(' ScreenCoord ',' ScreenCoord ')' PresetOption
PresetOption:
	| ',' PresetColor
PresetColor: VariableName
	| NumericConstant
Pset: PSET '(' ScreenCoord ',' ScreenCoord ')' PsetOption
PsetOption:
	| ',' PsetColor
PsetColor: VariableName
	| NumericConstant

ScreenCoord: VariableName
	| NumericConstant

Cls: CLS

For: FOR NumericVariable EQUAL NumericExpression TO NumericExpression 			{ $$ = gwbn_NewFor(); $$->num_var = $2; $$->from_num_expr = $4; $$->to_num_expr = $6; $$->step = NULL; }
Next: NEXT Variables									{ $$ = gwbn_NewNext(); $$->vars = $2; }							
GoSub: GOSUB LineNumber									{ $$ = gwbn_NewGoSub(); $$->line = $2; }
Return: RETURN										{ $$ = gwbn_NewReturn(); $$->type = GWBNT_RETURN;/* нужно в runtime реализовать стек возврата */}
	| RETURN LineNumber								{ $$ = gwbn_NewReturn(); $$->line = GWBNT_LINENUMBER; $$->line = $2; }

Goto: GOTO LineNumber							{ $$ = gwbn_NewGoto(); $$->line = $2; }

IfThenElse: IF Expression Then Else					{ $$ = gwbn_NewIfThenElse(); $$->expr = $2; $$->then = $3; $$->_else = $4; } 
Then: THEN Statements 							{ $$ = gwbn_NewThen(); $$->type = GWBNT_STATEMENTS; $$->stmts = $2; }
	| Goto								{ $$ = gwbn_NewThen(); $$->type = GWBNT_GOTO; $$->_goto = $1; }
Else:									{ $$ = gwbn_NewElse(); $$->stmts = NULL; }
	| ELSE Statements						{ $$ = gwbn_NewElse(); $$->stmts = $2; }

Input: INPUT InputPrompt Variables					{ $$ = gwbn_NewInput(); $$->prompt = $2; $$->vars = $3; }	
Input: INPUT Variables							{ $$ = gwbn_NewInput(); $$->prompt = NULL; $$->vars = $2; }
InputPrompt: InputPromptString InputPromptEndType			{ $$ = gwbn_NewInputPrompt(); $$->str = $1; $$->end_type = $2; }
InputPromptString:							{ $$ = NULL; }
	| CONST_STRING							{ $$ = $1; }
InputPromptEndType: ','							{ $$ = GWBBT_COMMA; }
	| ';'								{ $$ = GWBBT_SEMICOLON; }

Print: PrintOperator PrintExpressions					{ $$ = gwbn_NewPrint(); $$->exprs = $2; }		
PrintOperator: PRINT	
	| '?'
PrintExpressions: Expression PrintSeparator PrintExpressions		{ $$ = gwbn_NewPrintExpressions(); $$->expr = $1; $$->sep_type = $2; $$->next = $3; }
	| Expression							{ $$ = gwbn_NewPrintExpressions(); $$->expr = $1; }
	| PrintSeparator						{ $$ = gwbn_NewPrintExpressions(); $$->sep_type = $1; $$->next = NULL; }
PrintSeparator:								{ /* дополнить */ }
	| ','								{ $$ = GWBBT_COMMA; }
	| ';'								{ $$ = GWBBT_SEMICOLON; }

LineInput: LINE INPUT InputPromptString StringVariable

Locate: LOCATE LocateRow LocateColumn LocateCursor LocateStart LocateStop
LocateRow: ','
	| NumericConstant
LocateColumn: ','
	| NumericConstant
LocateCursor: ','
	| NumericConstant
LocateStart: ','
	| NumericConstant
LocateStop: ','
	| NumericConstant

Mid: MID'$' '(' StringExpression ',' MidFrom  MidTo ')' EQUAL StringExpression
MidFrom: NumericExpression
MidTo:
	| ',' NumericExpression

OnErrorGoto: ON ERROR GOTO LineNumber
OnGosub: ON Expression GOSUB LineNumbers
OnGoto: ON Expression GOTO LineNumbers
LineNumbers: LineNumber ',' LineNumbers
	| LineNumber


FunctionArguments: VariableName ',' FunctionArguments
	| VariableName

ArrayVariables: ArrayVariable ',' ArrayVariables
	| ArrayVariable

Variables: Variable ',' Variables				{ $$ = gwbn_NewVariables(); $$->var = $1; $$->next = $3; }
	| Variable						{ $$ = gwbn_NewVariables(); $$->var = $1; $$->next = NULL; }

Variable: StringVariable					{ $$ = gwbn_NewVariable(); $$->type = GWBNT_STRINGVARIABLE; $$->str = $1;}
	| NumericVariable					{ $$ = gwbn_NewVariable(); $$->type = GWBNT_NUMERICVARIABLE; $$->num = $1;}
	| ArrayVariable						{ $$ = gwbn_NewVariable(); $$->type = GWBNT_ARRAYVARIABLE; $$->arr = $1; }

StringVariable: DECLARATION '$'					{ $$ = gwbn_NewStringVariable(); $$->name = $1; }

NumericVariable: DECLARATION '%'				{ $$ = gwbn_NewNumericVariable(); $$->type = GWBNT_INTEGERVARIABLE; $$->name = $1; }
	| DECLARATION '!'					{ $$ = gwbn_NewNumericVariable(); $$->type = GWBNT_SINGLEPRECISIONVARIABLE; $$->name = $1; }
	| DECLARATION '#'					{ $$ = gwbn_NewNumericVariable(); $$->type = GWBNT_DOUBLEPRECISIONVARIABLE; $$->name = $1; }

ArrayVariable: DECLARATION '(' ConstIntegers ')'		{ $$ = gwbn_NewArrayVariable(); $$->name = $1; }

ConstIntegers: CONST_INTEGER ',' ConstIntegers
	| CONST_INTEGER

Expression: NumericExpression					{ $$ = gwbn_NewExpression(); $$->type = GWBNT_NUMERICEXPRESSION; $$->num_expr = $1; }
	| StringExpression					{ $$ = gwbn_NewExpression(); $$->type = GWBNT_STRINGEXPRESSION; $$->str_expr = $1; }

NumericExpression : ArithmeticOperator				{ $$ = gwbn_NewNumericExpression(); $$->type = GWBNT_ARITHMETICOPERATOR; $$->arithm = $1;}
	| RelationalOperator					{ $$ = gwbn_NewNumericExpression(); $$->type = GWBNT_RELATIONALOPERATOR; $$->rel = $1; }
	| LogicalOperator					{ $$ = gwbn_NewNumericExpression(); $$->type = GWBNT_LOGICALOPERATOR; $$->log = $1; }
	| FunctionalOperator					{ $$ = gwbn_NewNumericExpression(); $$->type = GWBNT_FUNCTIONALOPERATOR; /*$$->func = $1;*/ }

ArithmeticOperator: NumericExpression '+' NumericExpression	{ $$ = gwbn_NewArithmeticOperator(); $$->type = GWBBT_ADD; $$->a = $1;  $$->b = $3; }
	| NumericExpression '-' NumericExpression		{ $$ = gwbn_NewArithmeticOperator(); $$->type = GWBBT_SUB; $$->a = $1;  $$->b = $3; }
	| NumericExpression '*' NumericTerm			{ $$ = gwbn_NewArithmeticOperator(); $$->type = GWBBT_MUL; $$->a = $1;  $$->term_b = $3; }
	| NumericExpression '/' NumericTerm			{ $$ = gwbn_NewArithmeticOperator(); $$->type = GWBBT_DIV; $$->a = $1;  $$->term_b = $3; }
	| NumericTerm						{ $$ = gwbn_NewArithmeticOperator(); $$->type = GWBNT_NUMERICTERM; $$->term = $1; }

NumericTerm: '(' NumericExpression ')'				{ $$ = gwbn_NewNumericTerm(); $$->num_expr = $2; $$->type = GWBNT_NUMERICEXPRESSION; } 
	| '-' NumericTerm %prec UMINUS				{ $$ = gwbn_NewNumericTerm(); $$->term = $2; $$->type = GWBBT_UNARY_MINUS; }	
	| NumericTerm '^' NumericTerm				{ $$ = gwbn_NewNumericTerm(); $$->a = $1; $$->b = $3; $$->type = GWBBT_POW; }
	| NumericVariable					{ $$ = gwbn_NewNumericTerm(); $$->var = $1; $$->type = GWBNT_NUMERICVARIABLE; }
	| NumericConstant 					{ $$ = gwbn_NewNumericTerm(); $$->num_const = $1; $$->type = GWBNT_NUMERICCONSTANT; }

StringExpression: StringOperator				{ $$ = gwbn_NewStringExpression(); $$->op = $1; }
StringOperator:	StringTerm '+' StringOperator			{ $$ = gwbn_NewStringOperator(); $$->type = GWBBT_ADD; $$->a =$1; $$->b = $3; }
	| StringTerm						{ $$ = gwbn_NewStringOperator(); $$->type = GWBNT_STRINGTERM; $$->term = $1; } 
StringTerm: StringVariable					{ $$ = gwbn_NewStringTerm(); $$->type = GWBNT_STRINGVARIABLE; $$->var = $1; }
	| CONST_STRING						{ $$ = gwbn_NewStringTerm(); $$->type = GWBBT_STRING; $$->str = $1; }

NumericConstant: CONST_INTEGER					{ $$ = gwbn_NewNumericConstant(); $$->type = GWBBT_INTEGER; $$->const_int = $1; }
	| CONST_FLOAT						{ $$ = gwbn_NewNumericConstant(); $$->type = GWBBT_SINGLE; $$->const_float = $1; }	

RelationalOperator: ArithmeticOperator EQUAL ArithmeticOperator	{ $$ = gwbn_NewRelationalOperator(); $$->args_type = GWBNT_ARITHMETICOPERATOR; 
								  $$->op_type = GWBBT_EQUAL; $$->a = $1; $$->b = $3; }
	| ArithmeticOperator INEQUAL ArithmeticOperator		{ $$ = gwbn_NewRelationalOperator(); $$->args_type = GWBNT_ARITHMETICOPERATOR; 
								  $$->op_type = GWBBT_INEQUAL; $$->a = $1; $$->b = $3; }
	| ArithmeticOperator LT	ArithmeticOperator		{ $$ = gwbn_NewRelationalOperator(); $$->args_type = GWBNT_ARITHMETICOPERATOR; 
								  $$->op_type = GWBBT_LT; $$->a = $1; $$->b = $3; }
	| ArithmeticOperator GT ArithmeticOperator 		{ $$ = gwbn_NewRelationalOperator(); $$->args_type = GWBNT_ARITHMETICOPERATOR; 
 								  $$->op_type = GWBBT_GT; $$->a = $1; $$->b = $3; }	
	| ArithmeticOperator LTE ArithmeticOperator		{ $$ = gwbn_NewRelationalOperator(); $$->args_type = GWBNT_ARITHMETICOPERATOR; 
 								  $$->op_type = GWBBT_GTE; $$->a = $1; $$->b = $3; }	 
	| StringOperator EQUAL StringOperator			{ $$ = gwbn_NewRelationalOperator(); $$->args_type = GWBNT_STRINGOPERATOR; 
								  $$->op_type = GWBBT_EQUAL; $$->s1 = $1; $$->s2 = $3; }
	| StringOperator INEQUAL StringOperator			{ $$ = gwbn_NewRelationalOperator(); $$->args_type = GWBNT_STRINGOPERATOR; 
								  $$->op_type = GWBBT_INEQUAL; $$->s1 = $1; $$->s2 = $3; }
	| StringOperator LT StringOperator			{ $$ = gwbn_NewRelationalOperator(); $$->args_type = GWBNT_STRINGOPERATOR; 
								  $$->op_type = GWBBT_LT; $$->s1 = $1; $$->s2 = $3; }
	| StringOperator GT StringOperator			{ $$ = gwbn_NewRelationalOperator(); $$->args_type = GWBNT_STRINGOPERATOR; 
								  $$->op_type = GWBBT_GT; $$->s1 = $1; $$->s2 = $3; }
	| StringOperator LTE StringOperator			{ $$ = gwbn_NewRelationalOperator(); $$->args_type = GWBNT_STRINGOPERATOR; 
								  $$->op_type = GWBBT_LTE; $$->s1 = $1; $$->s2 = $3; } 
	| StringOperator GTE StringOperator			{ $$ = gwbn_NewRelationalOperator(); $$->args_type = GWBNT_STRINGOPERATOR; 
								  $$->op_type = GWBBT_GTE; $$->s1 = $1; $$->s2 = $3; }

LogicalOperator: NOT RelationalOperator				{ $$ = gwbn_NewLogicalOperator(); } 
	| RelationalOperator AND RelationalOperator		{ printf("A AND B\n"); } 
	| RelationalOperator OR RelationalOperator		{ printf("A OR B\n"); } 
	| RelationalOperator XOR RelationalOperator		{ printf("A XOR B\n"); } 
	| RelationalOperator EQV RelationalOperator		{ printf("A EQV B\n"); } 
	| RelationalOperator IMP RelationalOperator		{ printf("A IMP B\n"); } 

FunctionalOperator: MathFunction
	| StringFunction

Function: StringFunction
	| MathFunction
	| SystemFunction

StringFunction:  Asc
	| Len
	| Left_Str
	| Mid_Str
	| Right_Str

Asc: ASC '(' StringExpression ')'
Len: LEN '(' StringExpression ')'
Left_Str: LEFT_STR '(' StringExpression ',' NumericExpression ')'
Mid_Str: MID_STR '(' StringExpression ',' NumericExpression ',' NumericExpression ')'
Right_Str: RIGHT_STR '(' StringExpression ',' NumericExpression ')'

MathFunction: Abs			{ $$ = gwbn_NewMathFunction(); }					
	| Exp				{ $$ = gwbn_NewMathFunction(); }
	| Sin				{ $$ = gwbn_NewMathFunction(); }
	| Cos				{ $$ = gwbn_NewMathFunction(); }
	| Tan				{ $$ = gwbn_NewMathFunction(); }
	| Log				{ $$ = gwbn_NewMathFunction(); }
	| Fix				{ $$ = gwbn_NewMathFunction(); } 
	| Int				{ $$ = gwbn_NewMathFunction(); }
	| CInt				{ $$ = gwbn_NewMathFunction(); }
	| Sgn				{ $$ = gwbn_NewMathFunction(); }
	| Rnd				{ $$ = gwbn_NewMathFunction(); }

Abs: ABS '(' NumericExpression ')'	{ $$ = gwbn_NewAbs(); }
Exp: EXP '(' NumericExpression ')'	{ $$ = gwbn_NewExp(); }
Sin: SIN '(' NumericExpression ')'	{ $$ = gwbn_NewSin(); }
Cos: COS '(' NumericExpression ')'	{ $$ = gwbn_NewCos(); }			
Tan: TAN '(' NumericExpression ')'	{ $$ = gwbn_NewTan(); }
Log: LOG '(' NumericExpression ')'	{ $$ = gwbn_NewLog(); }
Fix: FIX '(' NumericExpression ')'	{ $$ = gwbn_NewFix(); }
Int: INT '(' NumericExpression ')'	{ $$ = gwbn_NewInt(); }
CInt: CINT'(' NumericExpression ')'	{ $$ = gwbn_NewCInt(); }
Sgn: SGN '(' NumericExpression ')'	{ $$ = gwbn_NewSgn(); }
Rnd: RND 				{ $$ = gwbn_NewRnd(); }

SystemFunction: EXTERR '(' CONST_INTEGER ')'

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
GWBN_Interpreter* gwbp_Parse(char* sourceCode)
{
	GWBN_Interpreter** interpreter = (GWBN_Interpreter**) malloc (sizeof(GWBN_Interpreter*));

	YY_BUFFER_STATE buffer = yy_scan_string(sourceCode);
	yyparse(interpreter);
	yy_delete_buffer(buffer);
	
	GWBN_Interpreter* result = *interpreter;
	free(interpreter);
	return result; 
}	
