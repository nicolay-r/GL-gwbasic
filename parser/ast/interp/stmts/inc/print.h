/* GWBasic Print Statement */

#ifndef _GWBN_PRINT_H_
#define _GWBN_PRINT_H_

#include "../../expr/inc/expr.h"

typedef struct GWBN_PrintExpressions GWBN_PrintExpressions;
typedef int GWBN_PrintSeparator; /* GWBBT_COMMA, GWBBT_SEMICOLON */

/*
	Structs
*/
struct GWBN_PrintExpressions {
	GWBN_Expression* expr;
	GWBN_PrintSeparator sep_type;	 /* GWBBT_NONE, GWBBT_COMMA, GWBBT_SEMICOLON */
	struct GWBN_PrintExpressions* next;
};

/*
	Prototypes
*/
GWBN_PrintExpressions* gwbn_NewPrintExpressions();	
void gwbn_DeletePrintExpressions(GWBN_PrintExpressions* ptr);

#endif
