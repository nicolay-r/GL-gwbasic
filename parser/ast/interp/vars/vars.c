/* GWBN_Variable Prototypes declaration */

#include "inc/vars.h"

GWBN_Variables* gwbn_NewVariables() {
	GWBN_Variables* result = (GWBN_Variables*) malloc (sizeof(GWBN_Variables));
	return result;
} 
	
void gwbn_DeleteVariables(GWBN_Variables* ptr) {
	free(ptr);
}


GWBN_Variable* gwbn_NewVariable() {
	GWBN_Variable* result = (GWBN_Variable*) malloc (sizeof(GWBN_Variable));
	return result;
} 
	
void gwbn_DeleteVariable(GWBN_Variable* ptr) {
	free(ptr);
}

GWBN_StringVariable* gwbn_NewStringVariable() {
	GWBN_StringVariable* result = (GWBN_StringVariable*) malloc (sizeof(GWBN_StringVariable));
	return result;
} 
	
void gwbn_DeleteStringVariable(GWBN_StringVariable* ptr) {
	free(ptr);
}
	
GWBN_NumericVariable* gwbn_NewNumericVariable() {
	GWBN_NumericVariable* result = (GWBN_NumericVariable*) malloc (sizeof(GWBN_NumericVariable));
	return result;
} 
	
void gwbn_DeleteNumericVariable(GWBN_NumericVariable* ptr) {
	free(ptr);
}
	
GWBN_ArrayVariable* gwbn_NewArrayVariable() {
	GWBN_ArrayVariable* result = (GWBN_ArrayVariable*) malloc (sizeof(GWBN_ArrayVariable));
	return result;
} 
	
void gwbn_DeleteArrayVariable(GWBN_ArrayVariable* ptr) {
	free(ptr);
}
		
GWBN_ArrayVariables* gwbn_NewArrayVariables() {
	GWBN_ArrayVariables* result = (GWBN_ArrayVariables*) malloc (sizeof(GWBN_ArrayVariables));
	return result;
} 
	
void gwbn_DeleteArrayVariables(GWBN_ArrayVariables* ptr) {
	free(ptr);
}
GWBN_SystemVariable* gwbn_NewSystemVariable()
{
	GWBN_SystemVariable* result = (GWBN_SystemVariable*) malloc (sizeof(GWBN_SystemVariable));
	return result;
}
void gwbn_DeleteSystemVariable(GWBN_SystemVariable* ptr)
{
	free(ptr);
}
