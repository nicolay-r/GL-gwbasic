/* GWBasic Auxulary implementation for if_then_else.h */

#include "inc/stmts.h"

GWBN_IfThenElse* gwbn_NewIfThenElse() {
	GWBN_IfThenElse* result = (GWBN_IfThenElse*) malloc (sizeof(GWBN_IfThenElse));
	return result;
} 
	
void gwbn_DeleteIfThenElse(GWBN_IfThenElse* ptr) {
	free(ptr);
}
	
GWBN_Then* gwbn_NewThen() {
	GWBN_Then* result = (GWBN_Then*) malloc (sizeof(GWBN_Then));
	return result;
} 
	
void gwbn_DeleteThen(GWBN_Then* ptr) {
	free(ptr);
}
	
GWBN_Else* gwbn_NewElse() {
	GWBN_Else* result = (GWBN_Else*) malloc (sizeof(GWBN_Else));
	return result;
} 
	
void gwbn_DeleteElse(GWBN_Else* ptr) {
	free(ptr);
}
