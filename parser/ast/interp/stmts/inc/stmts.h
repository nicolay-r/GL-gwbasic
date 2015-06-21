/* GWBasic Statements */
#ifndef _GWBASIC_STATEMENTS_H_
#define _GWBASIC_STATEMENTS_H_

/*
	Statements Depends on
*/
#include <stdlib.h>
#include "../../expr/inc/expr.h"

typedef struct GWBN_Statements GWBN_Statements;
typedef struct GWBN_Statement GWBN_Statement;
typedef struct GWBN_Beep GWBN_Beep;
typedef struct GWBN_Call GWBN_Call;
typedef struct GWBN_Dim GWBN_Dim;
typedef struct GWBN_Let GWBN_Let;
typedef struct GWBN_OptionBase GWBN_OptionBase;
typedef struct GWBN_DefFn GWBN_DefFn;
typedef struct GWBN_ScreenCoordinate GWBN_ScreenCoordinate;
typedef struct GWBN_Screen GWBN_Screen;
typedef struct GWBN_Paint GWBN_Paint;
typedef struct GWBN_Pset GWBN_Pset;
typedef struct GWBN_Preset GWBN_Preset;
typedef struct GWBN_Cls GWBN_Cls;
typedef struct GWBN_For GWBN_For;
typedef struct GWBN_Next GWBN_Next;
typedef struct GWBN_GoSub GWBN_GoSub;
typedef struct GWBN_Return GWBN_Return;
typedef struct GWBN_Goto GWBN_Goto;
typedef struct GWBN_Input GWBN_Input;
typedef struct GWBN_Print GWBN_Print;
typedef struct GWBN_LineInput GWBN_LineInput;
typedef struct GWBN_Locate GWBN_Locate;
typedef struct GWBN_Mid GWBN_Mid;
typedef struct GWBN_OnErrorGoto GWBN_OnErrorGoto;
typedef struct GWBN_OnGosub GWBN_OnGosub;
typedef struct GWBN_OnGoto GWBN_OnGoto;

/*
	Statements Includes
*/
#include "print.h"
#include "input.h"
#include "if_then_else.h"
#include "line.h"
#include "circle.h"

/*
	Statements
*/

struct GWBN_Statements {
	struct GWBN_Statement* stmt;
	struct GWBN_Statements* next;
};

/*
	Statement
*/
struct GWBN_Statement {
	int type;
	union {
		GWBN_Call* call;
		GWBN_Let* let;
		GWBN_Dim* dim;
		GWBN_DefFn* def_fn;
		GWBN_Circle* circle;
		GWBN_Screen* screen;
		GWBN_Line* line;
		GWBN_Print* print;
		GWBN_Input* input;
		GWBN_Goto* _goto;
		GWBN_IfThenElse* if_then_else;		
		GWBN_For* _for;
		GWBN_Next* next;
		GWBN_Cls* cls;
		GWBN_Return* ret;
		GWBN_GoSub* gosub;
	};
}; 

/*
	Structures
*/
struct GWBN_Beep {
	/* Not Implemented */
};
struct GWBN_Call {
	/* Not Implemented */
};
struct GWBN_Dim {
	GWBN_ArrayVariables* arr_vars;
};
struct GWBN_Let {
	GWBN_Variable *var;
	GWBN_Expression *expr;
};
struct GWBN_OptionBase {
	/* Not Implemented */
};
struct GWBN_DefFn {
	/* Not Implemented */
};
struct GWBN_ScreenCoordinate {
	GWBN_NumericExpression *x, *y;	
};

struct GWBN_Screen {
	int mode;
};

struct GWBN_Paint {
	/* Not Implemented */
};
struct GWBN_Pset {
	/* Not Implemented */
};
struct GWBN_Preset {
	/* Not Implemented */
};
struct GWBN_Cls {
};
struct GWBN_For {
	GWBN_NumericVariable* num_var;
	GWBN_NumericExpression *from_num_expr, *to_num_expr, *step; 
};
struct GWBN_Next {
	GWBN_Variables* vars;
};
struct GWBN_GoSub {
	GWBB_Integer line;
};
struct GWBN_Return {	
	int type;
	GWBB_Integer line;
};
struct GWBN_Goto {
	GWBB_Integer line;	
};
struct GWBN_Input {
	GWBN_InputPrompt* prompt;
	GWBN_Variables* vars;	
};
struct GWBN_Print {
	GWBN_PrintExpressions* exprs;
};
struct GWBN_LineInput {
	/* Not Implemented */
};
struct GWBN_Locate {
	/* Not Implemented */
};
struct GWBN_Mid {
	/* Not Implemented */
};
struct GWBN_OnErrorGoto {
	/* Not Implemented */
};
struct GWBN_OnGosub {
	/* Not Implemented */
};
struct GWBN_OnGoto {
	/* Not Implemented */
};
/*
	Prototypes
*/
GWBN_Statements* gwbn_NewStatements();
void gwbn_DeleteStatements(GWBN_Statements* ptr);
GWBN_Statement* gwbn_NewStatement();
void gwbn_DeleteStatement(GWBN_Statement* ptr);
GWBN_Beep* gwbn_NewBeep();
void gwbn_DeleteBeep(GWBN_Beep* ptr);
GWBN_Call* gwbn_NewCall();
void gwbn_DeleteCall(GWBN_Call* ptr);
GWBN_Dim* gwbn_NewDim();
void gwbn_DeleteDim(GWBN_Dim* ptr);
GWBN_Let* gwbn_NewLet();
void gwbn_DeleteLet(GWBN_Let* ptr);
GWBN_OptionBase* gwbn_NewOptionBase();
void gwbn_DeleteOptionBase(GWBN_OptionBase* ptr);
GWBN_DefFn* gwbn_NewDefFn();
void gwbn_DeleteDefFn(GWBN_DefFn* ptr);
GWBN_Screen* gwbn_NewScreen();
void gwbn_DeleteScreen(GWBN_Screen* ptr);
GWBN_ScreenCoordinate* gwbn_NewScreenCoordinate();
void gwbn_DeleteScreenCoordinate(GWBN_ScreenCoordinate* ptr);
GWBN_Paint* gwbn_NewPaint();
void gwbn_DeletePaint(GWBN_Paint* ptr);
GWBN_Pset* gwbn_NewPset();
void gwbn_DeletePset(GWBN_Pset* ptr);
GWBN_Preset* gwbn_NewPreset();
void gwbn_DeletePreset(GWBN_Preset* ptr);
GWBN_Cls* gwbn_NewCls();
void gwbn_DeleteCls(GWBN_Cls* ptr);
GWBN_For* gwbn_NewFor();
void gwbn_DeleteFor(GWBN_For* ptr);
GWBN_Next* gwbn_NewNext();
void gwbn_DeleteNext(GWBN_Next* ptr);
GWBN_GoSub* gwbn_NewGoSub();
void gwbn_DeleteGoSub(GWBN_GoSub* ptr);
GWBN_Return* gwbn_NewReturn();
void gwbn_DeleteReturn(GWBN_Return* ptr);
GWBN_Goto* gwbn_NewGoto();
void gwbn_DeleteGoto(GWBN_Goto* ptr);
GWBN_Input* gwbn_NewInput();
void gwbn_DeleteInput(GWBN_Input* ptr);
GWBN_Print* gwbn_NewPrint();
void gwbn_DeletePrint(GWBN_Print* ptr);
GWBN_LineInput* gwbn_NewLineInput();
void gwbn_DeleteLineInput(GWBN_LineInput* ptr);
GWBN_Locate* gwbn_NewLocate();
void gwbn_DeleteLocate(GWBN_Locate* ptr);
GWBN_Mid* gwbn_NewMid();
void gwbn_DeleteMid(GWBN_Mid* ptr);
GWBN_OnErrorGoto* gwbn_NewOnErrorGoto();
void gwbn_DeleteOnErrorGoto(GWBN_OnErrorGoto* ptr);
GWBN_OnGosub* gwbn_NewOnGosub();
void gwbn_DeleteOnGosub(GWBN_OnGosub* ptr);
GWBN_OnGoto* gwbn_NewOnGoto();
void gwbn_DeleteOnGoto(GWBN_OnGoto* ptr);


#endif
