/* GWBasic Functions for Expression AST Nodes */

#include "inc/expr.h"
#include <stdlib.h>

GWBN_Expression* gwbn_NewExpression() {
	GWBN_Expression* result = (GWBN_Expression*) malloc (sizeof(GWBN_Expression));
	return result;
} 
	
void gwbn_DeleteExpression(GWBN_Expression* ptr) {
	free(ptr);
}
	
GWBN_NumericExpression* gwbn_NewNumericExpression() {
	GWBN_NumericExpression* result = (GWBN_NumericExpression*) malloc (sizeof(GWBN_NumericExpression));
	return result;
} 
	
void gwbn_DeleteNumericExpression(GWBN_NumericExpression* ptr) {
	free(ptr);
}
	
GWBN_StringExpression* gwbn_NewStringExpression() {
	GWBN_StringExpression* result = (GWBN_StringExpression*) malloc (sizeof(GWBN_StringExpression));
	return result;
} 
	
void gwbn_DeleteStringExpression(GWBN_StringExpression* ptr) {
	free(ptr);
}
	
GWBN_ArithmeticOperator* gwbn_NewArithmeticOperator() {
	GWBN_ArithmeticOperator* result = (GWBN_ArithmeticOperator*) malloc (sizeof(GWBN_ArithmeticOperator));
	return result;
} 
	
void gwbn_DeleteArithmeticOperator(GWBN_ArithmeticOperator* ptr) {
	free(ptr);
}
	
GWBN_NumericTerm* gwbn_NewNumericTerm() {
	GWBN_NumericTerm* result = (GWBN_NumericTerm*) malloc (sizeof(GWBN_NumericTerm));
	return result;
} 
	
void gwbn_DeleteNumericTerm(GWBN_NumericTerm* ptr) {
	free(ptr);
}

GWBN_StringOperator* gwbn_NewStringOperator() {
	GWBN_StringOperator* result = (GWBN_StringOperator*) malloc (sizeof(GWBN_StringOperator));
	return result;
} 
	
void gwbn_DeleteStringOperator(GWBN_StringOperator* ptr) {
	free(ptr);
}
	
GWBN_StringTerm* gwbn_NewStringTerm() {
	GWBN_StringTerm* result = (GWBN_StringTerm*) malloc (sizeof(GWBN_StringTerm));
	return result;
} 
	
void gwbn_DeleteStringTerm(GWBN_StringTerm* ptr) {
	free(ptr);
}
	
GWBN_NumericConstant* gwbn_NewNumericConstant() {
	GWBN_NumericConstant* result = (GWBN_NumericConstant*) malloc (sizeof(GWBN_NumericConstant));
	return result;
} 
	
void gwbn_DeleteNumericConstant(GWBN_NumericConstant* ptr) {
	free(ptr);
}
	
GWBN_RelationalOperator* gwbn_NewRelationalOperator() {
	GWBN_RelationalOperator* result = (GWBN_RelationalOperator*) malloc (sizeof(GWBN_RelationalOperator));
	return result;
} 
	
void gwbn_DeleteRelationalOperator(GWBN_RelationalOperator* ptr) {
	free(ptr);
}
	
GWBN_LogicalOperator* gwbn_NewLogicalOperator() {
	GWBN_LogicalOperator* result = (GWBN_LogicalOperator*) malloc (sizeof(GWBN_LogicalOperator));
	return result;
} 
	
void gwbn_DeleteLogicalOperator(GWBN_LogicalOperator* ptr) {
	free(ptr);
}
	
GWBN_FunctionalOperator* gwbn_NewFunctionalOperator() {
	GWBN_FunctionalOperator* result = (GWBN_FunctionalOperator*) malloc (sizeof(GWBN_FunctionalOperator));
	return result;
} 
	
void gwbn_DeleteRunctionalOperator(GWBN_FunctionalOperator* ptr) {
	free(ptr);
}
	
