/* GWBasic statements.h functions implementation */

#include "inc/stmts.h"

/* 
	Constructor and Destructors
*/
GWBN_Statement* gwbn_NewStatement() {
	GWBN_Statement* result = (GWBN_Statement*) malloc (sizeof(GWBN_Statement));
	return result;
} 
	
void gwbn_DeleteStatement(GWBN_Statement* ptr) {
	free(ptr);
}
	
GWBN_Beep* gwbn_NewBeep() {
	GWBN_Beep* result = (GWBN_Beep*) malloc (sizeof(GWBN_Beep));
	return result;
} 
	
void gwbn_DeleteBeep(GWBN_Beep* ptr) {
	free(ptr);
}
	
GWBN_Call* gwbn_NewCall() {
	GWBN_Call* result = (GWBN_Call*) malloc (sizeof(GWBN_Call));
	return result;
} 
	
void gwbn_DeleteCall(GWBN_Call* ptr) {
	free(ptr);
}
	
GWBN_Dim* gwbn_NewDim() {
	GWBN_Dim* result = (GWBN_Dim*) malloc (sizeof(GWBN_Dim));
	return result;
} 
	
void gwbn_DeleteDim(GWBN_Dim* ptr) {
	free(ptr);
}
	
GWBN_Let* gwbn_NewLet() {
	GWBN_Let* result = (GWBN_Let*) malloc (sizeof(GWBN_Let));
	return result;
} 
	
void gwbn_DeleteLet(GWBN_Let* ptr) {
	free(ptr);
}
	
GWBN_OptionBase* gwbn_NewOptionBase() {
	GWBN_OptionBase* result = (GWBN_OptionBase*) malloc (sizeof(GWBN_OptionBase));
	return result;
} 
	
void gwbn_DeleteOptionBase(GWBN_OptionBase* ptr) {
	free(ptr);
}
	
GWBN_DefFn* gwbn_NewDefFn() {
	GWBN_DefFn* result = (GWBN_DefFn*) malloc (sizeof(GWBN_DefFn));
	return result;
} 
	
void gwbn_DeleteDefFn(GWBN_DefFn* ptr) {
	free(ptr);
}
	
GWBN_Circle* gwbn_NewCircle() {
	GWBN_Circle* result = (GWBN_Circle*) malloc (sizeof(GWBN_Circle));
	return result;
} 
	
void gwbn_DeleteCircle(GWBN_Circle* ptr) {
	free(ptr);
}
	
GWBN_Screen* gwbn_NewScreen() {
	GWBN_Screen* result = (GWBN_Screen*) malloc (sizeof(GWBN_Screen));
	return result;
} 
	
void gwbn_DeleteScreen(GWBN_Screen* ptr) {
	free(ptr);
}
	
GWBN_Line* gwbn_NewLine() {
	GWBN_Line* result = (GWBN_Line*) malloc (sizeof(GWBN_Line));
	return result;
} 
	
void gwbn_DeleteLine(GWBN_Line* ptr) {
	free(ptr);
}
	
GWBN_Paint* gwbn_NewPaint() {
	GWBN_Paint* result = (GWBN_Paint*) malloc (sizeof(GWBN_Paint));
	return result;
} 
	
void gwbn_DeletePaint(GWBN_Paint* ptr) {
	free(ptr);
}
	
GWBN_Pset* gwbn_NewPset() {
	GWBN_Pset* result = (GWBN_Pset*) malloc (sizeof(GWBN_Pset));
	return result;
} 
	
void gwbn_DeletePset(GWBN_Pset* ptr) {
	free(ptr);
}
	
GWBN_Preset* gwbn_NewPreset() {
	GWBN_Preset* result = (GWBN_Preset*) malloc (sizeof(GWBN_Preset));
	return result;
} 
	
void gwbn_DeletePreset(GWBN_Preset* ptr) {
	free(ptr);
}
	
GWBN_Cls* gwbn_NewCls() {
	GWBN_Cls* result = (GWBN_Cls*) malloc (sizeof(GWBN_Cls));
	return result;
} 
	
void gwbn_DeleteCls(GWBN_Cls* ptr) {
	free(ptr);
}
	
GWBN_For* gwbn_NewFor() {
	GWBN_For* result = (GWBN_For*) malloc (sizeof(GWBN_For));
	return result;
} 
	
void gwbn_DeleteFor(GWBN_For* ptr) {
	free(ptr);
}
	
GWBN_Next* gwbn_NewNext() {
	GWBN_Next* result = (GWBN_Next*) malloc (sizeof(GWBN_Next));
	return result;
} 
	
void gwbn_DeleteNext(GWBN_Next* ptr) {
	free(ptr);
}
	
GWBN_GoSub* gwbn_NewGoSub() {
	GWBN_GoSub* result = (GWBN_GoSub*) malloc (sizeof(GWBN_GoSub));
	return result;
} 
	
void gwbn_DeleteGoSub(GWBN_GoSub* ptr) {
	free(ptr);
}
	
GWBN_Return* gwbn_NewReturn() {
	GWBN_Return* result = (GWBN_Return*) malloc (sizeof(GWBN_Return));
	return result;
} 
	
void gwbn_DeleteReturn(GWBN_Return* ptr) {
	free(ptr);
}
	
GWBN_Goto* gwbn_NewGoto() {
	GWBN_Goto* result = (GWBN_Goto*) malloc (sizeof(GWBN_Goto));
	return result;
} 
	
void gwbn_DeleteGoto(GWBN_Goto* ptr) {
	free(ptr);
}
	
GWBN_IfThenElse* gwbn_NewIfThenElse() {
	GWBN_IfThenElse* result = (GWBN_IfThenElse*) malloc (sizeof(GWBN_IfThenElse));
	return result;
} 
	
void gwbn_DeleteIfThenElse(GWBN_IfThenElse* ptr) {
	free(ptr);
}
	
GWBN_Input* gwbn_NewInput() {
	GWBN_Input* result = (GWBN_Input*) malloc (sizeof(GWBN_Input));
	return result;
} 
	
void gwbn_DeleteInput(GWBN_Input* ptr) {
	free(ptr);
}
	
GWBN_Print* gwbn_NewPrint() {
	GWBN_Print* result = (GWBN_Print*) malloc (sizeof(GWBN_Print));
	return result;
} 
	
void gwbn_DeletePrint(GWBN_Print* ptr) {
	free(ptr);
}
	
GWBN_LineInput* gwbn_NewLineInput() {
	GWBN_LineInput* result = (GWBN_LineInput*) malloc (sizeof(GWBN_LineInput));
	return result;
} 
	
void gwbn_DeleteLineInput(GWBN_LineInput* ptr) {
	free(ptr);
}
	
GWBN_Locate* gwbn_NewLocate() {
	GWBN_Locate* result = (GWBN_Locate*) malloc (sizeof(GWBN_Locate));
	return result;
} 
	
void gwbn_DeleteLocate(GWBN_Locate* ptr) {
	free(ptr);
}
	
GWBN_Mid* gwbn_NewMid() {
	GWBN_Mid* result = (GWBN_Mid*) malloc (sizeof(GWBN_Mid));
	return result;
} 
	
void gwbn_DeleteMid(GWBN_Mid* ptr) {
	free(ptr);
}
	
GWBN_OnErrorGoto* gwbn_NewOnErrorGoto() {
	GWBN_OnErrorGoto* result = (GWBN_OnErrorGoto*) malloc (sizeof(GWBN_OnErrorGoto));
	return result;
} 
	
void gwbn_DeleteOnErrorGoto(GWBN_OnErrorGoto* ptr) {
	free(ptr);
}
	
GWBN_OnGosub* gwbn_NewOnGosub() {
	GWBN_OnGosub* result = (GWBN_OnGosub*) malloc (sizeof(GWBN_OnGosub));
	return result;
} 
	
void gwbn_DeleteOnGosub(GWBN_OnGosub* ptr) {
	free(ptr);
}
	
GWBN_OnGoto* gwbn_NewOnGoto() {
	GWBN_OnGoto* result = (GWBN_OnGoto*) malloc (sizeof(GWBN_OnGoto));
	return result;
} 
	
void gwbn_DeleteOnGoto(GWBN_OnGoto* ptr) {
	free(ptr);
}

