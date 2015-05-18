/* GWBasic Ast node Circle implementation */

#include "inc/stmts.h"
#include <stdlib.h>

GWBN_Circle* gwbn_NewCircle() {
	GWBN_Circle* result = (GWBN_Circle*) malloc (sizeof(GWBN_Circle));
	return result;
} 
	
void gwbn_DeleteCircle(GWBN_Circle* ptr) {
	free(ptr);
}
	
GWBN_CircleOptions* gwbn_NewCircleOptions() {
	GWBN_CircleOptions* result = (GWBN_CircleOptions*) malloc (sizeof(GWBN_CircleOptions));
	return result;
} 
	
void gwbn_DeleteCircleOptions(GWBN_CircleOptions* ptr) {
	free(ptr);
}	
