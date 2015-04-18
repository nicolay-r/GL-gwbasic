#ifndef _GWBASIC_EXPRESSIONS_H_
#define _GWBASIC_EXPRESSIONS_H_

#include "../../vars/inc/vars.h"

#define GWBNT_EXPRESSION_NUMERIC		4000
#define GWBNT_EXPRESSION_STRING			4001
#define GWBNT_EXPRESSION_SUBEXPR		4002

#define GWBNT_OPERATION_ADD			4020
#define GWBNT_OPERATION_SUB			4021
#define GWBNT_OPEARTION_MUL			4022
#define GWBNT_OPERATION_DIV			4023
#define GWBNT_OPERATION_POW			4024
#define GWBNT_OPERATION_UNARY_MINUS		4025

/*
	String Expression
*/

typedef struct {
	int type;
	union {
		struct {
			struct GWBN_StringOperator *a, *b;
		};
		GWBN_StringVariable* var;
		char* str;
	};
} GWBN_StringOperator;
	
/*
	Numeric Expression
*/
typedef void GWBN_NumericConstant;

/* for reference to each other */
typedef struct GWBN_NumericExpression GWBN_NumericExpression;  
typedef struct GWBN_ArithmeticOperator GWBN_ArithmeticOperator;
 
typedef struct {
	int type;
	union {
		GWBN_NumericExpression* num_expr;
		struct {
			struct GWBN_NumericTerm *a, *b;
		};
		struct GWBN_NumericTerm* term;
		GWBN_NumericVariable* var;
		GWBN_NumericConstant* num;
	};
} GWBN_NumericTerm;


struct GWBN_ArithmeticOperator{
	int type;
	union {
		struct {
			GWBN_NumericExpression *a, *b;
		};
		GWBN_NumericTerm *term;	
	};
};

typedef void GWBN_RelationalOperator;
typedef void GWBN_LogicalOperator;
typedef void GWBN_FunctionalOperator;

struct GWBN_NumericExpression{
	int type;
	union {
		GWBN_ArithmeticOperator* arithm;
		GWBN_RelationalOperator* rel;
		GWBN_LogicalOperator* logic;
		GWBN_FunctionalOperator* func;
	};
};

/*
	Expression
*/
typedef struct {
	int type;
	union {
		GWBN_NumericExpression*	num_expr;
		GWBN_StringOperator* str_expr;
	};
} GWBN_Expression;

GWBN_Expression* gwbn_NewExpression();
void gwbn_DeleteExpression();
#endif 
