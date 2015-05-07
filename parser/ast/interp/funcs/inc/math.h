/* GWBasic Math Functions header */

#ifndef _GWBN_MATH_H_
#define _GWBN_MATH_H_

#include <stdlib.h>

typedef struct GWBN_MathFunction GWBN_MathFunction; 
typedef struct GWBN_Abs GWBN_Abs;
typedef struct GWBN_Exp GWBN_Exp;
typedef struct GWBN_Sin GWBN_Sin;
typedef struct GWBN_Cos GWBN_Cos;
typedef struct GWBN_Tan GWBN_Tan;
typedef struct GWBN_Log GWBN_Log;
typedef struct GWBN_Fix GWBN_Fix;
typedef struct GWBN_Int GWBN_Int;
typedef struct GWBN_CInt GWBN_CInt;
typedef struct GWBN_Sgn GWBN_Sgn;
typedef struct GWBN_Rnd GWBN_Rnd;

GWBN_MathFunction* gwbn_NewMathFunction();
void gwbn_DeleteMathFunction(GWBN_MathFunction* ptr);
GWBN_Abs* gwbn_NewAbs();
void gwbn_DeleteAbs(GWBN_Abs* ptr);
GWBN_Exp* gwbn_NewExp();
void gwbn_DeleteExp(GWBN_Exp* ptr);
GWBN_Sin* gwbn_NewSin();
void gwbn_DeleteSin(GWBN_Sin* ptr);
GWBN_Cos* gwbn_NewCos();
void gwbn_DeleteCos(GWBN_Cos* ptr);
GWBN_Tan* gwbn_NewTan();
void gwbn_DeleteTan(GWBN_Tan* ptr);
GWBN_Log* gwbn_NewLog();
void gwbn_DeleteLog(GWBN_Log* ptr);
GWBN_Fix* gwbn_NewFix();
void gwbn_DeleteFix(GWBN_Fix* ptr);
GWBN_Int* gwbn_NewInt();
void gwbn_DeleteInt(GWBN_Int* ptr);
GWBN_CInt* gwbn_NewCInt();
void gwbn_DeleteCInt(GWBN_CInt* ptr);
GWBN_Sgn* gwbn_NewSgn();
void gwbn_DeleteSgn(GWBN_Sgn* ptr);
GWBN_Rnd* gwbn_NewRnd();
void gwbn_DeleteRnd(GWBN_Rnd* ptr);

struct GWBN_MathFunction {
	int type;
	union {
		GWBN_Abs *abs;
		GWBN_Exp *exp;
		GWBN_Sin *sin;
		GWBN_Cos *cos;
		GWBN_Tan *tan;
		GWBN_Log *log;
		GWBN_Fix *fix;
		GWBN_Int *_int;
		GWBN_CInt *cint;
		GWBN_Sgn *sgn;
		GWBN_Rnd *rnd;
	};
};
struct GWBN_Abs {
	/* Not Implemented */
};
struct GWBN_Exp {
	/* Not Implemented */
};
struct GWBN_Sin {
	/* Not Implemented */
};
struct GWBN_Cos {
	/* Not Implemented */
};
struct GWBN_Tan {
	/* Not Implemented */
};
struct GWBN_Log {
	/* Not Implemented */
};
struct GWBN_Fix {
	/* Not Implemented */
};
struct GWBN_Int {
	/* Not Implemented */
};
struct GWBN_CInt {
	/* Not Implemented */
};
struct GWBN_Sgn {
	/* Not Implemented */
};
struct GWBN_Rnd {
	/* Not Implemented */
};

#endif
