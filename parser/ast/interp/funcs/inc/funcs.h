#ifndef _GWBASIC_FUNCTIONS_H_
#define _GWBASIC_FUNCTIONS_H_

#include <stdlib.h>
#include "math.h"

typedef struct GWBN_Function GWBN_Function;

struct GWBN_Function {	
	/* Not Implemented */
};


GWBN_Function* gwbn_NewFunction();
void gwbn_DeleteFunction(GWBN_Function* ptr);

#endif
