#ifndef _GWBASIC_FUNCTIONS_H_
#define _GWBASIC_FUNCTIONS_H_

#include <stdlib.h>
#include "math.h"

typedef struct GWBN_Function GWBN_Function;

struct GWBN_Function {	
	int type;	/* GWBNT_STRINGFUNCTION, GWBNT_MATHFUNCTION, GWBNT_SYSTEMFUNCTION */
	union {
		GWBN_MathFunction* math_func;
	};
};


GWBN_Function* gwbn_NewFunction();
void gwbn_DeleteFunction(GWBN_Function* ptr);

#endif
