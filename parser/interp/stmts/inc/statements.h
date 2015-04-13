/* GWBasic Statements */
#ifndef _GWBASIC_STATEMENTS_H_
#define _GWBASIC_STATEMENTS_H_

#include <stdlib.h>

typedef struct GWBN_Beep GWBN_Beep;
typedef struct GWBN_Call GWBN_Call;
typedef struct GWBN_Dim GWBN_Dim;
typedef struct GWBN_Let GWBN_Let;
typedef struct GWBN_OptionBase GWBN_OptionBase;
typedef struct GWBN_DefFn GWBN_DefFn;
typedef struct GWBN_Circle GWBN_Circle;
typedef struct GWBN_Screen GWBN_Screen;
typedef struct GWBN_Line GWBN_Line;
typedef struct GWBN_Paint GWBN_Paint;
typedef struct GWBN_Pset GWBN_Pset;
typedef struct GWBN_Preset GWBN_Preset;
typedef struct GWBN_Cls GWBN_Cls;
typedef struct GWBN_For GWBN_For;
typedef struct GWBN_Next GWBN_Next;
typedef struct GWBN_GoSub GWBN_GoSub;
typedef struct GWBN_Return GWBN_Return;
typedef struct GWBN_Goto GWBN_Goto;
typedef struct GWBN_IfThenElse GWBN_IfThenElse;
typedef struct GWBN_Input GWBN_Input;
typedef struct GWBN_Print GWBN_Print;
typedef struct GWBN_LineInput GWBN_LineInput;
typedef struct GWBN_Locate GWBN_Locate;
typedef struct GWBN_Mid GWBN_Mid;
typedef struct GWBN_OnErrorGoto GWBN_OnErrorGoto;
typedef struct GWBN_OnGosub GWBN_OnGosub;
typedef struct GWBN_OnGoto GWBN_OnGoto;

/*
	Statement
*/
typedef struct {
	int type;
	union {
		struct GWBN_Call* call;
		struct GWBN_Let* let;
		struct GWBN_Dim* dim;
		struct GWBN_DefFn* def_fn;
		struct GWBN_Circle* circle;
		struct GWBN_Screen* screen;
		struct GWBN_Line* line;		
	};
} GWBN_Statement;

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
	/* Not Implemented */
};
struct GWBN_Let {
	/* Not Implemented */
};
struct GWBN_OptionBase {
	/* Not Implemented */
};
struct GWBN_DefFn {
	/* Not Implemented */
};
struct GWBN_Circle {
	/* Not Implemented */
};
struct GWBN_Screen {
	/* Not Implemented */
};
struct GWBN_Line {
	/* Not Implemented */
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
	/* Not Implemented */
};
struct GWBN_For {
	/* Not Implemented */
};
struct GWBN_Next {
	/* Not Implemented */
};
struct GWBN_GoSub {
	/* Not Implemented */
};
struct GWBN_Return {
	/* Not Implemented */
};
struct GWBN_Goto {
	/* Not Implemented */
};
struct GWBN_IfThenElse {
	/* Not Implemented */
};
struct GWBN_Input {
	/* Not Implemented */
};
struct GWBN_Print {
	/* Not Implemented */
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
GWBN_Circle* gwbn_NewCircle();
void gwbn_DeleteCircle(GWBN_Circle* ptr);
GWBN_Screen* gwbn_NewScreen();
void gwbn_DeleteScreen(GWBN_Screen* ptr);
GWBN_Line* gwbn_NewLine();
void gwbn_DeleteLine(GWBN_Line* ptr);
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
GWBN_IfThenElse* gwbn_NewIfThenElse();
void gwbn_DeleteIfThenElse(GWBN_IfThenElse* ptr);
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
