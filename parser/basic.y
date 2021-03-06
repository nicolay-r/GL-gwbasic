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

%token BEEP CALL DIM OPTION BASE LET DEF FN CIRCLE SCREEN LINE PAINT PSET PRESET CLS FOR NEXT GOSUB RETURN GOTO IF THEN ELSE INPUT PRINT END WHILE WEND
%token LOCATE MID

%token ABS ASC
%token CINT COS EXP EXTERR FIX INT LEN LOG SGN TAN RND SQR
%token LEFT_STR MID_STR RIGHT_STR

%token INKEY_STR

%token TO STEP AS ON ERROR

%token DECLARATION

%token '$'

%token GT LT GTE LTE EQUAL INEQUAL
%token NOT AND OR XOR IMP EQV

/* Math functions*/
%token SIN
/* Specific Symbols */
%token EOLN _EOF

/* constants */
%token CONST_INTEGER CONST_FLOAT CONST_STRING

/* Arithmetic precedence */
%nonassoc NORELATION
%left GT LT GTE LTE EQUAL INEQUAL
%nonassoc NOLOGIC

%left '+' '-'
%left '*' '/'
%left '^'
%nonassoc UMINUS

%left IMP EQV
%left XOR
%left OR
%left AND
%nonassoc NOT

/* Type declaration */
%code requires {

	/*
		AST Node Types
	*/
	#include "ast/inc/types.h"
	#include "ast/interp/inc/interp.h"
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
	GWBN_TrOn*			tron;
	GWBN_TrOff*			troff;
	GWBN_Load*			load;
	GWBN_List*			list;

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
	GWBN_ScreenCoordinate*		scr_coord;
	GWBN_Line*			line;
	GWBN_LineOptions*		line_opts;
	GWBN_Circle*			circle;
	GWBN_CircleOptions*		circle_opts;
	GWBN_Cls*			cls;
	GWBN_Screen*			screen;
	GWBN_Dim*			dim;
	GWBN_ArrayVariables*		arr_vars;
	GWBN_Indexes*			inds;
	GWBN_End*			end;
	GWBN_While*			_while;
	GWBN_Wend*			wend;

	/* Expressions */
	GWBN_Expression*		expr;
	GWBN_NumericExpression*		num_expr;
	GWBN_ArithmeticOperator*	arithm_op;
	GWBN_NumericTerm*		num_term;
	GWBN_StringExpression*		str_expr;
	GWBN_StringOperator*		str_op;
	GWBN_StringTerm*		str_term;
	GWBN_FunctionalOperator*	func_op;
	GWBN_GoSub*			gosub;
	GWBN_Return*			_return;

	/* Variable */
	GWBN_Variables*			variables;
	GWBN_Variable*			variable;
	GWBN_NumericVariable*		num_var;
	GWBN_StringVariable*		str_var;
	GWBN_ArrayVariable*		arr_var;
	GWBN_SystemVariable*		sys_var;

	/* Functions */
	GWBN_Function*			func;

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
	GWBN_Sqr*			sqr;
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
%type <tron> TrOn
%type <troff> TrOff
%type <load> Load
%type <list> List
/*
	Statements
*/
%type <statements> Statements NextStatements
%type <statement> Statement
%type <let> Let
%type <print> Print
%type <print_exprs> PrintExpressions
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
%type <scr_coord> ScreenCoordinate
%type <line> Line
%type <line_opts> LineOptions
%type <circle> Circle
%type <circle_opts> CircleOptions
%type <cls> Cls
%type <screen> Screen
%type <dim> Dim
%type <arr_vars> ArrayVariables
%type <inds> Indexes
%type <end> End
%type <_while> While
%type <wend> Wend

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
%type <func_op> FunctionalOperator

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
%type <sys_var> SystemVariable;

/*
	Functions
*/
%type <func> Function;

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
%type <sqr> Sqr;
%type <rnd> Rnd;

/*
	Constants
*/
%type <str> DECLARATION CONST_STRING FileName;
%type <float_num> CONST_FLOAT;
%type <num_const> NumericConstant;
/*
%type <num_expr> NumericExpression
%type <str_op> StringOperator
*/
%type <int_num> ScreenMode LineNumber Increment CONST_INTEGER
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

IndirectMode: LineNumber			{ $$ = gwbn_NewIndirectMode(); $$->line_number = $1; $$->statements = NULL; }
	| LineNumber Statements			{ $$ = gwbn_NewIndirectMode(); $$->line_number = $1; $$->statements = $2; }

DirectMode: Command EOLN			{ $$ = gwbn_NewDirectMode(); $$->type = GWBNT_COMMAND; $$->command = $1; }
	| Statements				{ $$ = gwbn_NewDirectMode(); $$->type = GWBNT_STATEMENTS; $$->statements = $1; }
	| Function EOLN				{ $$ = gwbn_NewDirectMode(); $$->type = GWBNT_FUNCTION; $$->function = $1; }

Command: Run					{ $$ = gwbn_NewCommand(); $$->type = GWBNT_RUN; $$->run = $1;}
	| System				{ $$ = gwbn_NewCommand(); $$->type = GWBNT_SYSTEM; /* NULL AST subnode */ }
	| Auto					{ $$ = gwbn_NewCommand(); $$->type = GWBNT_AUTO; $$->_auto = $1; }
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
	| List					{ $$ = gwbn_NewCommand(); $$->type = GWBNT_LIST; $$->list = $1; }
	| LList					{ printf("LLIST %s\n", ne); }
	| Load					{ $$ = gwbn_NewCommand(); $$->type = GWBNT_LOAD; $$->load = $1; }
	| MkDir					{ printf("MKDIR %s\n", ne); }
	| Name					{ printf("NAME %s\n", ne); }
	| TrOn					{ $$ = gwbn_NewCommand(); $$->type = GWBNT_TRON; $$->tron = $1; }
	| TrOff					{ $$ = gwbn_NewCommand(); $$->type = GWBNT_TROFF; $$->troff = $1; }

Statements: Statement NextStatements		{ $$ = gwbn_NewStatements(); $$->stmt = $1; $$->next = $2; }
NextStatements: EOLN				{ $$ = NULL; }
	| _EOF					{ $$ = NULL; }
	| ':' Statements			{ $$ = $2; }

Statement: Beep					{ printf("BEEP %s\n", ne); }
	| Call					{ printf("CALL %s\n", ne); }
	| Dim					{ $$ = gwbn_NewStatement();  $$->type = GWBNT_DIM; $$->dim = $1; }
	| Let					{ $$ = gwbn_NewStatement(); $$->type = GWBNT_LET; $$->let = $1; }
	| OptionBase				{ printf("OPTION BASE %s\n", ne); }
	| DefFn					{ printf("DEF FN %s\n", ne); }
	| Circle				{ $$ = gwbn_NewStatement(); $$->type = GWBNT_CIRCLE; $$->circle = $1; }
	| Screen				{ $$ = gwbn_NewStatement(); $$->type = GWBNT_SCREEN; $$->screen = $1; }
	| Line					{ $$ = gwbn_NewStatement(); $$->type = GWBNT_LINE; $$->line = $1; }
	| Paint					{ printf("PAINT %s\n", ne); }
	| Pset					{ printf("PSET %s\n", ne); }
	| Preset				{ printf("PRESET %s\n", ne); }
	| Cls					{ $$ = gwbn_NewStatement(); $$->type = GWBNT_CLS; $$->cls = $1; }
	| For					{ $$ = gwbn_NewStatement(); $$->type = GWBNT_FOR; $$->_for = $1; }
	| While					{ $$ = gwbn_NewStatement(); $$->type = GWBNT_WHILE; $$->_while = $1; }
	| Wend					{ $$ = gwbn_NewStatement(); $$->type = GWBNT_WEND; $$->wend = $1; }
	| Next					{ $$ = gwbn_NewStatement(); $$->type = GWBNT_NEXT; $$->next = $1; }
	| GoSub					{ $$ = gwbn_NewStatement(); $$->type = GWBNT_GOSUB; $$->gosub = $1; }
	| Return				{ $$ = gwbn_NewStatement(); $$->type = GWBNT_RETURN; $$->ret = $1; }
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
	| End					{ $$ = gwbn_NewStatement(); $$->type = GWBNT_END; $$->end = $1; }

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
List:	LIST LineNumber Dash LineNumber ',' FileName { $$ = gwbn_NewList(); $$->line_from = $2; $$->line_to = $4; $$->file_name = $6; }
	| LIST LineNumber Dash ',' FileName		{ $$ = gwbn_NewList(); $$->line_from = $2; $$->line_to = -1; $$->file_name = $5; }
	| LIST LineNumber Dash LineNumber		{ $$ = gwbn_NewList(); $$->line_from = $2; $$->line_to = $4; $$->file_name = NULL; }
	| LIST LineNumber Dash			{ $$ = gwbn_NewList(); $$->line_from = $2; $$->line_to = -1; $$->file_name = NULL; }
LList:	LLIST LineNumber Dash LineNumber
	| LLIST LineNumber Dash
Load:	LOAD FileName ',' LoadOption		{ $$ = gwbn_NewLoad(); $$->file_path = $2; /* $$->load_options Not Implemented */}
	| LOAD CONST_STRING			{ $$ = gwbn_NewLoad(); $$->file_path = $2; }
MkDir: 	MKDIR PathName
Name:	NAME OldFileName AS NewFileName
TrOn:	TRON									{ $$ = gwbn_NewTrOn(); }
TrOff:	TROFF									{ $$ = gwbn_NewTrOff(); }

Beep:	BEEP
Call:	CALL '('  Variables ')'
Dim:	DIM ArrayVariables							{ $$ = gwbn_NewDim(); $$->arr_vars = $2; }
OptionBase: OPTION BASE NumericConstant
Let: 	LET Variable EQUAL Expression						{ $$ = gwbn_NewLet(); $$->var = $2; $$->expr = $4; }
	| Variable EQUAL Expression						{ $$ = gwbn_NewLet(); $$->var = $1; $$->expr = $3; }
DefFn:	DEF FN VariableName '(' FunctionArguments ')' EQUAL Expression
	| DEF FN VariableName EQUAL Expression

Circle:	CIRCLE ScreenCoordinate ',' NumericExpression CircleOptions /* Radius */{ $$ = gwbn_NewCircle(); $$->coord = $2; $$->r = $4; $$->opts = $5; }
CircleOptions: 									{ $$ = gwbn_NewCircleOptions(); $$->color = NULL; }
	| ',' NumericExpression /* Color */					{ $$ = gwbn_NewCircleOptions(); $$->color = $2; }
	| ',' NumericExpression ',' NumericExpression /* Color, Start */							{ /* Not implemented */ }
	| ',' ',' NumericExpression /* Start */											{ /* Not implemented */ }
	| ',' NumericExpression ',' NumericExpression ',' NumericExpression /* Color, Start, End */				{ /* Not implemented */ }
	| ',' ',' NumericExpression ',' NumericExpression /* Start, End */							{ /* Not implemented */ }
	| ',' ',' ',' NumericExpression /* End */										{ /* Not implemented */ }
	| ',' NumericExpression ',' NumericExpression ',' NumericExpression ',' NumericExpression /* Color, Start, End, Aspect */	{ /* Not implemented */ }
	| ',' ',' NumericExpression ',' NumericExpression ',' NumericExpression /* Start, End, Aspect */			{ /* Not implemented */ }
	| ',' ',' ',' NumericExpression ',' NumericExpression /* End, Aspect */							{ /* Not implemented */}
	| ',' ',' ',' ',' NumericExpression /* Aspect */									{ /* Not implemented */}

Screen: SCREEN ScreenMode							{ $$ = gwbn_NewScreen(); $$->mode = $2; }
ScreenMode: CONST_INTEGER							{ $$ = $1; }

Line: LINE ScreenCoordinate '-' ScreenCoordinate LineOptions			{ $$ = gwbn_NewLine(); $$->coord_a = $2; $$->coord_b = $4; $$->opts = $5; }
	| LINE '-' ScreenCoordinate LineOptions					{ $$ = gwbn_NewLine(); $$->coord_a = NULL; $$->coord_b = $3; $$->opts = $4; }
LineOptions: 									{ $$ = gwbn_NewLineOptions(); $$->color = NULL; }
	| ',' NumericExpression	/* LineColor */					{ $$ = gwbn_NewLineOptions(); $$->color = $2; }
	| ',' NumericExpression ',' DECLARATION /* + FillingFormat */		{ /* Not Supported */ }
	| ',' ',' DECLARATION /* FillingFormat */				{ /* Not Supported */ }

Paint: PAINT ScreenCoordinate PaintOptions
PaintOptions:
	| ',' NumericExpression	/* PaintAttr */
	| ',' NumericExpression ',' NumericExpression /* +  BorderAttr */
	| ',' NumericExpression ',' NumericExpression ',' NumericExpression /* + BckgrndAttr */

Preset: PRESET ScreenCoordinate PresetOption
PresetOption:
	| ',' NumericExpression	/* presetColor */

Pset: PSET ScreenCoordinate PsetOption
PsetOption:
	| ',' NumericExpression	/* psetColor */

ScreenCoordinate: '(' NumericExpression ',' NumericExpression ')'		{ $$ = gwbn_NewScreenCoordinate(); $$->x = $2; $$->y = $4; }

Cls: CLS									{ $$ = gwbn_NewCls(); }

For: FOR NumericVariable EQUAL NumericExpression TO NumericExpression 			{ $$ = gwbn_NewFor(); $$->num_var = $2; $$->from_num_expr = $4; $$->to_num_expr = $6; $$->step = NULL; }
Next: NEXT Variables									{ $$ = gwbn_NewNext(); $$->vars = $2; }
While: WHILE NumericExpression								{ $$ = gwbn_NewWhile(); $$->num_expr = $2; }
Wend: WEND										{ $$ = gwbn_NewWend(); }
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
PrintExpressions: Expression ',' PrintExpressions			{ $$ = gwbn_NewPrintExpressions(); $$->expr = $1; $$->sep_type = GWBBT_COMMA; $$->next = $3; }
	| Expression ';' PrintExpressions				{ $$ = gwbn_NewPrintExpressions(); $$->expr = $1; $$->sep_type = GWBBT_SEMICOLON; $$->next = $3; }
	| Expression							{ $$ = gwbn_NewPrintExpressions(); $$->expr = $1; $$->sep_type = GWBBT_NONE; $$->next = NULL; }
	| ','								{ $$ = gwbn_NewPrintExpressions(); $$->expr = NULL; $$->sep_type = GWBBT_COMMA; $$->next = NULL; }
	| ';'								{ $$ = gwbn_NewPrintExpressions(); $$->expr = NULL; $$->sep_type = GWBBT_SEMICOLON; $$->next = NULL; }
	|								{ $$ = gwbn_NewPrintExpressions(); $$->expr = NULL; $$->sep_type = GWBBT_NONE; $$->next = NULL; }

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
End: END							{ $$ = gwbn_NewEnd(); }

LineNumbers: LineNumber ',' LineNumbers
	| LineNumber


FunctionArguments: VariableName ',' FunctionArguments
	| VariableName

ArrayVariables: ArrayVariable ',' ArrayVariables		{ $$ = gwbn_NewArrayVariables(); $$->var = $1; $$->next = $3; }
	| ArrayVariable						{ $$ = gwbn_NewArrayVariables(); $$->var = $1; $$->next = NULL; }

Variables: Variable ',' Variables				{ $$ = gwbn_NewVariables(); $$->var = $1; $$->next = $3; }
	| Variable						{ $$ = gwbn_NewVariables(); $$->var = $1; $$->next = NULL; }

Variable: StringVariable					{ $$ = gwbn_NewVariable(); $$->type = GWBNT_STRINGVARIABLE; $$->str = $1;}
	| NumericVariable					{ $$ = gwbn_NewVariable(); $$->type = GWBNT_NUMERICVARIABLE; $$->num = $1;}
	| ArrayVariable						{ $$ = gwbn_NewVariable(); $$->type = GWBNT_ARRAYVARIABLE; $$->arr = $1; }
	| SystemVariable					{ $$ = gwbn_NewVariable(); $$->type = GWBNT_SYSTEMVARIABLE; $$->sys = $1; }

NumericVariable: DECLARATION '%'				{ $$ = gwbn_NewNumericVariable(); $$->type = GWBNT_INTEGERVARIABLE; $$->name = $1; }
	| DECLARATION '!'					{ $$ = gwbn_NewNumericVariable(); $$->type = GWBNT_SINGLEPRECISIONVARIABLE; $$->name = $1; }
	| DECLARATION '#'					{ $$ = gwbn_NewNumericVariable(); $$->type = GWBNT_DOUBLEPRECISIONVARIABLE; $$->name = $1; }

ArrayVariable: StringVariable '(' Indexes ')'			{ $$ = gwbn_NewArrayVariable(); $$->type = GWBNT_STRINGVARIABLE; $$->str = $1; $$->dims = $3; }
	| NumericVariable '(' Indexes ')'			{ $$ = gwbn_NewArrayVariable(); $$->type = GWBNT_NUMERICVARIABLE; $$->num = $1; $$->dims = $3; }

StringVariable: DECLARATION '$'					{ $$ = gwbn_NewStringVariable(); $$->name = $1; }

SystemVariable:	INKEY_STR	/* INKEY$ */			{ $$ = gwbn_NewSystemVariable(); $$->var_type = GWBNT_SYSTEMVARIABLE_INKEY; $$->val_type = GWBNT_STRINGVARIABLE; }

Indexes: NumericExpression ',' Indexes				{ $$ = gwbn_NewIndexes(); $$->num = $1; $$->next = $3; }
	| NumericExpression					{ $$ = gwbn_NewIndexes(); $$->num = $1; $$->next = NULL; }

Expression: NumericExpression					{ $$ = gwbn_NewExpression(); $$->type = GWBNT_NUMERICEXPRESSION; $$->num_expr = $1; }
	| StringExpression					{ $$ = gwbn_NewExpression(); $$->type = GWBNT_STRINGEXPRESSION; $$->str_expr = $1; }

NumericExpression: ArithmeticOperator				{ $$ = gwbn_NewNumericExpression(); $$->type = GWBNT_ARITHMETICOPERATOR; $$->arithm = $1;}

ArithmeticOperator: ArithmeticOperator '+' ArithmeticOperator	{ $$ = gwbn_NewArithmeticOperator(); $$->type = GWBBT_ADD; $$->a = $1; $$->b = $3; }
	| ArithmeticOperator '-' ArithmeticOperator		{ $$ = gwbn_NewArithmeticOperator(); $$->type = GWBBT_SUB; $$->a = $1; $$->b = $3; }
	| ArithmeticOperator '*' ArithmeticOperator		{ $$ = gwbn_NewArithmeticOperator(); $$->type = GWBBT_MUL; $$->a = $1; $$->b = $3; }
	| ArithmeticOperator '/' ArithmeticOperator		{ $$ = gwbn_NewArithmeticOperator(); $$->type = GWBBT_DIV; $$->a = $1; $$->b = $3; }
	| ArithmeticOperator '^' ArithmeticOperator		{ $$ = gwbn_NewArithmeticOperator(); $$->type = GWBBT_POW; $$->a = $1; $$->b = $3; }

	/* logical operators */
	|  NOT ArithmeticOperator				{ $$ = gwbn_NewArithmeticOperator(); $$->type = GWBBT_NOT; $$->a = $2; }
	|  ArithmeticOperator AND ArithmeticOperator 		{ $$ = gwbn_NewArithmeticOperator(); $$->type = GWBBT_AND; $$->a = $1; $$->b = $3; }
	|  ArithmeticOperator OR ArithmeticOperator		{ $$ = gwbn_NewArithmeticOperator(); $$->type = GWBBT_OR; $$->a = $1; $$->b = $3; }
	|  ArithmeticOperator XOR ArithmeticOperator		{ $$ = gwbn_NewArithmeticOperator(); $$->type = GWBBT_XOR; $$->a = $1; $$->b = $3; }
	|  ArithmeticOperator EQV ArithmeticOperator		{ $$ = gwbn_NewArithmeticOperator(); $$->type = GWBBT_EQV; $$->a = $1; $$->b = $3; }
	|  ArithmeticOperator IMP ArithmeticOperator		{ $$ = gwbn_NewArithmeticOperator(); $$->type = GWBBT_IMP; $$->a = $1; $$->b = $3; }

	/* Relatinals operations */
	| ArithmeticOperator EQUAL ArithmeticOperator		{ $$ = gwbn_NewArithmeticOperator(); $$->type = GWBBT_EQUAL; $$->a = $1; $$->b = $3; }
	| ArithmeticOperator INEQUAL ArithmeticOperator		{ $$ = gwbn_NewArithmeticOperator(); $$->type = GWBBT_INEQUAL; $$->a = $1; $$->b = $3; }
	| ArithmeticOperator LT	ArithmeticOperator		{ $$ = gwbn_NewArithmeticOperator(); $$->type = GWBBT_LT; $$->a = $1; $$->b = $3; }
	| ArithmeticOperator GT ArithmeticOperator 		{ $$ = gwbn_NewArithmeticOperator(); $$->type = GWBBT_GT; $$->a = $1; $$->b = $3; }
	| ArithmeticOperator LTE ArithmeticOperator		{ $$ = gwbn_NewArithmeticOperator(); $$->type = GWBBT_LTE; $$->a = $1; $$->b = $3; }

	/* bitwise operators can be implemented here */

	/* Unary operators */
	| '(' ArithmeticOperator ')'				{ $$ = gwbn_NewArithmeticOperator(); $$->type = GWBNT_ARITHMETICOPERATOR; $$->a = $2; }
	| '-' ArithmeticOperator %prec UMINUS			{ $$ = gwbn_NewArithmeticOperator(); $$->type = GWBBT_UNARY_MINUS; $$->a = $2; }
	| NumericTerm						{ $$ = gwbn_NewArithmeticOperator(); $$->type = GWBNT_NUMERICTERM; $$->term = $1; }

NumericTerm: FunctionalOperator					{ $$ = gwbn_NewNumericTerm(); $$->func_op = $1; $$->type = GWBNT_FUNCTIONALOPERATOR; }
	| NumericVariable					{ $$ = gwbn_NewNumericTerm(); $$->var = $1; $$->type = GWBNT_NUMERICVARIABLE; }
	| ArrayVariable						{ $$ = gwbn_NewNumericTerm(); $$->arr = $1; $$->type = GWBNT_ARRAYVARIABLE; }
	| NumericConstant 					{ $$ = gwbn_NewNumericTerm(); $$->num_const = $1; $$->type = GWBNT_NUMERICCONSTANT; }
	| SystemVariable					{ $$ = gwbn_NewNumericTerm(); $$->sys = $1; $$->type = GWBNT_SYSTEMVARIABLE; }

StringExpression: StringOperator				{ $$ = gwbn_NewStringExpression(); $$->op = $1; }
StringOperator:	StringTerm '+' StringOperator			{ $$ = gwbn_NewStringOperator(); $$->type = GWBBT_ADD; $$->a =$1; $$->b = $3; }
	| StringTerm						{ $$ = gwbn_NewStringOperator(); $$->type = GWBNT_STRINGTERM; $$->term = $1; }
StringTerm: StringVariable					{ $$ = gwbn_NewStringTerm(); $$->type = GWBNT_STRINGVARIABLE; $$->var = $1; }
	| CONST_STRING						{ $$ = gwbn_NewStringTerm(); $$->type = GWBBT_STRING; $$->str = $1; }

NumericConstant: CONST_INTEGER					{ $$ = gwbn_NewNumericConstant(); $$->type = GWBBT_INTEGER; $$->const_int = $1; }
	| CONST_FLOAT						{ $$ = gwbn_NewNumericConstant(); $$->type = GWBBT_SINGLE; $$->const_float = $1; }

FunctionalOperator: MathFunction				{ $$ = gwbn_NewFunctionalOperator(); $$->type = GWBNT_MATHFUNCTION; $$->math_func = $1; }
	| StringFunction					{ $$ = gwbn_NewFunctionalOperator(); $$->type = GWBNT_STRINGFUNCTION; /*$$->str_func = $1;*/ }

Function: StringFunction					{ $$ = gwbn_NewFunction(); $$->type = GWBNT_STRINGFUNCTION; /*str->func = $1*/ }
	| MathFunction						{ $$ = gwbn_NewFunction(); $$->type = GWBNT_MATHFUNCTION; $$->math_func = $1; }
	| SystemFunction					{ $$ = gwbn_NewFunction(); $$->type = GWBNT_SYSTEMFUNCTION; }

StringFunction: Asc
	| Len
	| Left_Str
	| Mid_Str
	| Right_Str

Asc: ASC '(' StringExpression ')'
Len: LEN '(' StringExpression ')'
Left_Str: LEFT_STR '(' StringExpression ',' NumericExpression ')'
Mid_Str: MID_STR '(' StringExpression ',' NumericExpression ',' NumericExpression ')'
Right_Str: RIGHT_STR '(' StringExpression ',' NumericExpression ')'

MathFunction: Abs						{ $$ = gwbn_NewMathFunction(); $$->type = GWBNT_ABS; $$->abs = $1; }
	| Exp							{ $$ = gwbn_NewMathFunction(); $$->type = GWBNT_EXP; $$->exp = $1; }
	| Sin							{ $$ = gwbn_NewMathFunction(); $$->type = GWBNT_SIN; $$->sin = $1; }
	| Cos							{ $$ = gwbn_NewMathFunction(); $$->type = GWBNT_COS; $$->cos = $1; }
	| Tan							{ $$ = gwbn_NewMathFunction(); $$->type = GWBNT_TAN; $$->tan = $1; }
	| Log							{ $$ = gwbn_NewMathFunction(); $$->type = GWBNT_LOG; $$->log = $1; }
	| Fix							{ $$ = gwbn_NewMathFunction(); $$->type = GWBNT_FIX; $$->fix = $1; }
	| Int							{ $$ = gwbn_NewMathFunction(); $$->type = GWBNT_INT; $$->_int = $1; }
	| CInt							{ $$ = gwbn_NewMathFunction(); $$->type = GWBNT_CINT; $$->cint = $1; }
	| Sgn							{ $$ = gwbn_NewMathFunction(); $$->type = GWBNT_SGN; $$->sgn = $1; }
	| Sqr							{ $$ = gwbn_NewMathFunction(); $$->type = GWBNT_SQR; $$->sqr = $1; }
	| Rnd							{ $$ = gwbn_NewMathFunction(); $$->type = GWBNT_RND; $$->rnd = $1; }

Abs: ABS '(' NumericExpression ')'				{ $$ = gwbn_NewAbs(); $$->expr = $3; }
Exp: EXP '(' NumericExpression ')'				{ $$ = gwbn_NewExp(); $$->expr = $3; }
Sin: SIN '(' NumericExpression ')'				{ $$ = gwbn_NewSin(); $$->expr = $3; }
Cos: COS '(' NumericExpression ')'				{ $$ = gwbn_NewCos(); $$->expr = $3; }
Tan: TAN '(' NumericExpression ')'				{ $$ = gwbn_NewTan(); $$->expr = $3; }
Log: LOG '(' NumericExpression ')'				{ $$ = gwbn_NewLog(); $$->expr = $3; }
Fix: FIX '(' NumericExpression ')'				{ $$ = gwbn_NewFix(); $$->expr = $3; }
Int: INT '(' NumericExpression ')'				{ $$ = gwbn_NewInt(); $$->expr = $3; }
CInt: CINT'(' NumericExpression ')'				{ $$ = gwbn_NewCInt(); $$->expr = $3; }
Sgn: SGN '(' NumericExpression ')'				{ $$ = gwbn_NewSgn(); $$->expr = $3; }
Sqr: SQR '(' NumericExpression ')'				{ $$ = gwbn_NewSqr(); $$->expr = $3; }
Rnd: RND 							{ $$ = gwbn_NewRnd(); }

SystemFunction: EXTERR '(' CONST_INTEGER ')'

Dash: '-';
VariableName: DECLARATION;
LoadOption: DECLARATION;
FilePath: CONST_STRING;
PathName: CONST_STRING;
FileName: CONST_STRING						{ $$ = $1; }
OldFileName: CONST_STRING;
NewFileName: CONST_STRING;
LineNumber: CONST_INTEGER					{ $$ = $1; }
Increment: CONST_INTEGER;
Offset: CONST_INTEGER;
Length: CONST_INTEGER;
%%

/*
	GWBasic syntax Analyzer
*/
int yyerror(char *s)
{
	fprintf(stderr, "Syntax Error %s\n", s);
	return 0;
}

/*
	GWBasic program parser from char* buffer
*/
GWBN_Interpreter* gwbp_Parse(char* source_code)
{
	GWBN_Interpreter** interpreter = (GWBN_Interpreter**) malloc (sizeof(GWBN_Interpreter*));

	YY_BUFFER_STATE buffer = yy_scan_string(source_code);
	yyparse(interpreter);
	yy_delete_buffer(buffer);

	GWBN_Interpreter* result = *interpreter;
	free(interpreter);
	return result;
}
