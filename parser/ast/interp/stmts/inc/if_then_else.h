/* GWBasic Auxulary sructs and prototypes for IfThenElse ast node */

#ifndef _GWBN_IF_THEN_ELSE_H_
#define _GWBN_IF_THEN_ELSE_H_

/*
	This file included into stmts.h
*/

typedef struct GWBN_IfThenElse GWBN_IfThenElse;
typedef struct GWBN_Then GWBN_Then;
typedef struct GWBN_Else GWBN_Else;

/*
	Structs
*/
struct GWBN_IfThenElse {
	GWBN_Expression* expr;
	GWBN_Then* then;
	GWBN_Else* _else;
};
struct GWBN_Then {
	int type;	/* GWBNT_GOTO, GWBNT_STATEMENTS */
	union {
		GWBN_Goto* _goto;
		GWBN_Statements* stmts;		
	};
};
struct GWBN_Else {
	GWBN_Statements* stmts;
};

/*
	Prototypes
*/
GWBN_IfThenElse* gwbn_NewIfThenElse();
void gwbn_DeleteIfThenElse(GWBN_IfThenElse* ptr);
GWBN_Then* gwbn_NewThen();
void gwbn_DeleteThen(GWBN_Then* ptr);
GWBN_Else* gwbn_NewElse();
void gwbn_DeleteElse(GWBN_Else* ptr);

#endif
