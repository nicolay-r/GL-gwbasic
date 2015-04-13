/* 
	Contains implementation for AST Nodes, declared in "interp.h"
*/

#include "inc/interp.h"

GWBN_DirectMode* gwbn_NewDirectMode() {
	GWBN_DirectMode* result = (GWBN_DirectMode*) malloc (sizeof(GWBN_DirectMode));
	return result;
} 
	
void gwbn_DeleteDirectMode(GWBN_DirectMode* ptr) {
	free(ptr);
}
	
GWBN_IndirectMode* gwbn_NewIndirectMode() {
	GWBN_IndirectMode* result = (GWBN_IndirectMode*) malloc (sizeof(GWBN_IndirectMode));
	return result;
} 
	
void gwbn_DeleteIndirectMode(GWBN_IndirectMode* ptr) {
	free(ptr);
}
	
GWBN_Interpreter* gwbn_NewInterpreter() {
	GWBN_Interpreter* result = (GWBN_Interpreter*) malloc (sizeof(GWBN_Interpreter));
	return result;
} 
	
void gwbn_DeleteInterpreter(GWBN_Interpreter* ptr) {
	free(ptr);
}
	
