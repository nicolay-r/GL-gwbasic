/* GWBasic Functions implementation */

#include "../expr/inc/expr.h"

GWBN_Function* gwbn_NewFunction() {
	GWBN_Function* result = (GWBN_Function*) malloc (sizeof(GWBN_Function));
	return result;
} 
	
void gwbn_DeleteFunction(GWBN_Function* ptr) {
	free(ptr);
}
	
