/* GWBN_Variable Prototypes declaration */

#include "inc/vars.h"

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
	
