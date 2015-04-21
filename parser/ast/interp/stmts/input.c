/* GWBasic AST node "input" functions implementation */

#include "inc/input.h"

GWBN_InputPrompt* gwbn_NewInputPrompt() {
	GWBN_InputPrompt* result = (GWBN_InputPrompt*) malloc (sizeof(GWBN_InputPrompt));
	return result;
} 
	
void gwbn_DeleteInputPrompt(GWBN_InputPrompt* ptr) {
	free(ptr);
}
	
GWBN_InputPromptEnd* gwbn_NewInputPromptEnd() {
	GWBN_InputPromptEnd* result = (GWBN_InputPromptEnd*) malloc (sizeof(GWBN_InputPromptEnd));
	return result;
} 
	
void gwbn_DeleteInputPromptEnd(GWBN_InputPromptEnd* ptr) {
	free(ptr);
}
	
