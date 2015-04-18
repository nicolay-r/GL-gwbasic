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
	int type;
	union {
		GWBN_NumericExpression*	num_expr;
		GWBN_StringOperator* str_expr;
	};
};

struct GWBN_NumericExpression{
	int type;
	union {
		GWBN_ArithmeticOperator* arithm;
		GWBN_RelationalOperator* rel;
		GWBN_LogicalOperator* logic;
		GWBN_FunctionalOperator* func;
	};
};

struct GWBN_ArithmeticOperator{
	int type;
	union {
		struct {
			GWBN_NumericExpression *a, *b;
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
		GWBN_NumericConstant* num;
	};
};

struct GWBN_StringExpression{
		
};

struct GWBN_StringOperator{
	int type;
	union {
		struct {
			struct GWBN_StringOperator *a, *b;
		};
		GWBN_StringVariable* var;
		char* str;
	};
};

struct GWBN_StringTerm {

};

struct GWBN_NumericConstant {
	
};

struct GWBN_RelationalOperator {

};

struct GWBN_LogicalOperator {
	
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
