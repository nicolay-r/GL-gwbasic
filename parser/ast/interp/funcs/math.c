/* GWBasic Math Functions declaration */
#include "inc/math.h"

GWBN_MathFunction* gwbn_NewMathFunction() {
	GWBN_MathFunction* result = (GWBN_MathFunction*) malloc (sizeof(GWBN_MathFunction));
	return result;
} 
	
GWBN_Abs* gwbn_NewAbs() {
	GWBN_Abs* result = (GWBN_Abs*) malloc (sizeof(GWBN_Abs));
	return result;
} 
	
void gwbn_DeleteAbs(GWBN_Abs* ptr) {
	free(ptr);
}
	
GWBN_Exp* gwbn_NewExp() {
	GWBN_Exp* result = (GWBN_Exp*) malloc (sizeof(GWBN_Exp));
	return result;
} 
	
void gwbn_DeleteExp(GWBN_Exp* ptr) {
	free(ptr);
}
	
GWBN_Sin* gwbn_NewSin() {
	GWBN_Sin* result = (GWBN_Sin*) malloc (sizeof(GWBN_Sin));
	return result;
} 
	
void gwbn_DeleteSin(GWBN_Sin* ptr) {
	free(ptr);
}
	
GWBN_Cos* gwbn_NewCos() {
	GWBN_Cos* result = (GWBN_Cos*) malloc (sizeof(GWBN_Cos));
	return result;
} 
	
void gwbn_DeleteCos(GWBN_Cos* ptr) {
	free(ptr);
}
	
GWBN_Tan* gwbn_NewTan() {
	GWBN_Tan* result = (GWBN_Tan*) malloc (sizeof(GWBN_Tan));
	return result;
} 
	
void gwbn_DeleteTan(GWBN_Tan* ptr) {
	free(ptr);
}
	
GWBN_Log* gwbn_NewLog() {
	GWBN_Log* result = (GWBN_Log*) malloc (sizeof(GWBN_Log));
	return result;
} 
	
void gwbn_DeleteLog(GWBN_Log* ptr) {
	free(ptr);
}
	
GWBN_Fix* gwbn_NewFix() {
	GWBN_Fix* result = (GWBN_Fix*) malloc (sizeof(GWBN_Fix));
	return result;
} 
	
void gwbn_DeleteFix(GWBN_Fix* ptr) {
	free(ptr);
}
	
GWBN_Int* gwbn_NewInt() {
	GWBN_Int* result = (GWBN_Int*) malloc (sizeof(GWBN_Int));
	return result;
} 
	
void gwbn_DeleteInt(GWBN_Int* ptr) {
	free(ptr);
}
	
GWBN_CInt* gwbn_NewCInt() {
	GWBN_CInt* result = (GWBN_CInt*) malloc (sizeof(GWBN_CInt));
	return result;
} 
	
void gwbn_DeleteCInt(GWBN_CInt* ptr) {
	free(ptr);
}
	
GWBN_Sgn* gwbn_NewSgn() {
	GWBN_Sgn* result = (GWBN_Sgn*) malloc (sizeof(GWBN_Sgn));
	return result;
} 
	
void gwbn_DeleteSgn(GWBN_Sgn* ptr) {
	free(ptr);
}
	
GWBN_Rnd* gwbn_NewRnd() {
	GWBN_Rnd* result = (GWBN_Rnd*) malloc (sizeof(GWBN_Rnd));
	return result;
} 
	
void gwbn_DeleteRnd(GWBN_Rnd* ptr) {
	free(ptr);
}
	
