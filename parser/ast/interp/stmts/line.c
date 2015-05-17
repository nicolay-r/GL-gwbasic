/* GWBasic Ast node Line implementation */

#include "inc/stmts.h"
#include <stdlib.h>

GWBN_Line* gwbn_NewLine() {
	GWBN_Line* result = (GWBN_Line*) malloc (sizeof(GWBN_Line));
	return result;
} 
	
void gwbn_DeleteLine(GWBN_Line* ptr) {
	free(ptr);
}
	
GWBN_LineOptions* gwbn_NewLineOptions() {
	GWBN_LineOptions* result = (GWBN_LineOptions*) malloc (sizeof(GWBN_LineOptions));
	return result;
} 
	
void gwbn_DeleteLineOptions(GWBN_LineOptions* ptr) {
	free(ptr);
}	
