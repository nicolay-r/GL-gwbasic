/* GWBasic Array Indexes */

#ifndef _GWBN_INDEXES_H_
#define _GWBN_INDEXES_H_

/*
	Depends on
*/
#include "../../expr/inc/expr.h"

typedef struct GWBN_Indexes GWBN_Indexes;

struct GWBN_Indexes {
	GWBN_NumericExpression* num;
	struct GWBN_Indexes* next;
};

/*
	Prototypes
*/
GWBN_Indexes* gwbn_NewIndexes();
void gwbn_DeleteIndexes(GWBN_Indexes* ptr);

#endif
