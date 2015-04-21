/* GWBasic AST node "input" functions implementation */

#include "inc/input.h"

GWBN_InputPrompt* gwbn_NewInputPrompt() {
	GWBN_InputPrompt* result = (GWBN_InputPrompt*) malloc (sizeof(GWBN_InputPrompt));
	return result;
} 
	
void gwbn_DeleteInputPrompt(GWBN_InputPrompt* ptr) {
	free(ptr);
}	
