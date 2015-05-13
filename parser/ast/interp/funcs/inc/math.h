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
typedef struct GWBN_Sqr GWBN_Sqr;
typedef struct GWBN_Rnd GWBN_Rnd;

/*
	Structures
*/
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
		GWBN_Sqr *sqr;
		GWBN_Rnd *rnd;
	};
};

struct GWBN_Abs {
	GWBN_NumericExpression* expr;
};
struct GWBN_Exp {
	GWBN_NumericExpression* expr;
};
struct GWBN_Sin {
	GWBN_NumericExpression* expr;
};
struct GWBN_Cos {
	GWBN_NumericExpression* expr;
};
struct GWBN_Tan {
	GWBN_NumericExpression* expr;
};
struct GWBN_Log {
	GWBN_NumericExpression* expr;
};
struct GWBN_Fix {
	GWBN_NumericExpression* expr;
};
struct GWBN_Int {
	GWBN_NumericExpression* expr;
};
struct GWBN_CInt {
	GWBN_NumericExpression* expr;
};
struct GWBN_Sgn {
	GWBN_NumericExpression* expr;
};
struct GWBN_Sqr {
	GWBN_NumericExpression* expr;
};
struct GWBN_Rnd {
};

/*
	Prototypes
*/
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
GWBN_Sqr* gwbn_NewSqr();
void gwbn_DeleteSqr(GWBN_Sqr* ptr);
GWBN_Rnd* gwbn_NewRnd();
void gwbn_DeleteRnd(GWBN_Rnd* ptr);


#endif
