#ifndef _GWBASIC_EXPRESSIONS_H_
#define _GWBASIC_EXPRESSIONS_H_

#include "../../vars/inc/vars.h"
#include "../../../inc/base.h"		/* GWBB_Integer, GWBB_Single, GWBB_Double, GWBB_String */

typedef struct GWBN_NumericExpression GWBN_NumericExpression;  
typedef struct GWBN_ArithmeticOperator GWBN_ArithmeticOperator;
typedef struct GWBN_Expression GWBN_Expression;
typedef struct GWBN_NumericTerm GWBN_NumericTerm;
typedef struct GWBN_StringExpression GWBN_StringExpression;
typedef struct GWBN_StringOperator GWBN_StringOperator;
typedef struct GWBN_StringTerm GWBN_StringTerm;
typedef struct GWBN_RelationalOperator GWBN_RelationalOperator;
typedef struct GWBN_LogicalOperator GWBN_LogicalOperator;
typedef struct GWBN_FunctionalOperator GWBN_FunctionalOperator;
typedef struct GWBN_NumericConstant GWBN_NumericConstant; 

/*
	Expression
*/
struct GWBN_Expression{
	int type; /*GWBN_NUMERICEXPRESSION, GWBN_STRINGOPERATOR */
	union {
		GWBN_NumericExpression*	num_expr;
		GWBN_StringExpression* str_expr;
	};
};

struct GWBN_NumericExpression{
	int type;
	union {
		GWBN_ArithmeticOperator* arithm;
		GWBN_RelationalOperator* rel;
		GWBN_LogicalOperator* log;
		GWBN_FunctionalOperator* func;
	};
};

struct GWBN_ArithmeticOperator{
	int type; /* GWBB_ADD, GWBB_SUB, GWBB_MUL, GWBB_DIV, GWBN_NUMERICTERM */
	union {
		struct {
			GWBN_NumericExpression *a;
			union {
				GWBN_NumericExpression *b;
				GWBN_NumericTerm *term_b;
			};
		};
		GWBN_NumericTerm *term;	
	};
};
	
struct GWBN_NumericTerm {
	int type;
	union {
		GWBN_NumericExpression* num_expr;
		struct {
			struct GWBN_NumericTerm *a, *b;
		};
		struct GWBN_NumericTerm* term;
		GWBN_NumericVariable* var;
		GWBN_NumericConstant* num_const;
	};
};

struct GWBN_StringExpression{
	GWBN_StringOperator* op;
};

struct GWBN_StringOperator{
	int type; /* GWBB_ADD, GWBB_STRINGTERM */
	union {
		struct {
			struct GWBN_StringTerm *a;
			struct GWBN_StringOperator *b;
		};
		GWBN_StringTerm* term;
	};
};

struct GWBN_StringTerm {
	int type; /* GWBN_STRINGVARIABLE, GWBB_STRING */
	union {
		GWBN_StringVariable* var;
		GWBB_String str;
	};
};


struct GWBN_NumericConstant {
	int type; /* GWBB_INTEGER, GWBB_SINGLE */
	union {
		GWBB_Integer const_int;
		GWBB_Single const_float;
	};
};

struct GWBN_RelationalOperator {
	int op_type;	/*GWBB_EQUAL, GWBB_INEQUAL, ... */
	int args_type;	/*GWBN_ARITHMETICOPERATOR, GWBN_STRINGOPERATOR */
	union {
		struct {
			GWBN_ArithmeticOperator *a, *b;	
		};
		struct {
			GWBN_StringOperator *s1, *s2;
		};
	};
};

struct GWBN_LogicalOperator {
	int type;	/* GWBB_NOT, GWBB_AND, GWBB_OR, GWBB_XOR */
	GWBN_RelationalOperator* rop;
};

struct GWBN_FunctionalOperator {
	
};

/*
	Prototypes
*/
GWBN_Expression* gwbn_NewExpression();
void gwbn_DeleteExpression(GWBN_Expression* ptr);
GWBN_NumericExpression* gwbn_NewNumericExpression();
void gwbn_DeleteNumericExpression(GWBN_NumericExpression* ptr);
GWBN_StringExpression* gwbn_NewStringExpression();
void gwbn_DeleteStringExpression(GWBN_StringExpression* ptr);
GWBN_ArithmeticOperator* gwbn_NewArithmeticOperator();
void gwbn_DeleteArithmeticOperator(GWBN_ArithmeticOperator* ptr);
GWBN_NumericTerm* gwbn_NewNumericTerm();
void gwbn_DeleteNumericTerm(GWBN_NumericTerm* ptr);
GWBN_StringExpression* gwbn_NewStringExpression();
void gwbn_DeleteStringExpression(GWBN_StringExpression* ptr);
GWBN_StringOperator* gwbn_NewStringOperator();
void gwbn_DeleteStringOperator(GWBN_StringOperator* ptr);
GWBN_StringTerm* gwbn_NewStringTerm();
void gwbn_DeleteStringTerm(GWBN_StringTerm* ptr);
GWBN_NumericConstant* gwbn_NewNumericConstant();
void gwbn_DeleteNumericConstant(GWBN_NumericConstant* ptr);
GWBN_RelationalOperator* gwbn_NewRelationalOperator();
void gwbn_DeleteRelationalOperator(GWBN_RelationalOperator* ptr);
GWBN_LogicalOperator* gwbn_NewLogicalOperator();
void gwbn_DeleteLogicalOperator(GWBN_LogicalOperator* ptr);
GWBN_FunctionalOperator* gwbn_NewFunctionalOperator();
void gwbn_DeleteRunctionalOperator(GWBN_FunctionalOperator* ptr);


#endif 
