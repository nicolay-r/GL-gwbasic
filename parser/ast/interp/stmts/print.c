/* GBasic Print Statement Implementation */

#include "inc/print.h"

GWBN_PrintExpressions* gwbn_NewPrintExpressions() {
	GWBN_PrintExpressions* result = (GWBN_PrintExpressions*) malloc (sizeof(GWBN_PrintExpressions));
	return result;
} 
	
void gwbn_DeletePrintExpressions(GWBN_PrintExpressions* ptr) {
	free(ptr);
}
