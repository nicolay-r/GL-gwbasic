/* GWBasic Statements */
#ifndef _GWBASIC_STATEMENTS_H_
#define _GWBASIC_STATEMENTS_H_

typedef struct GWBN_Call GWBN_Call;
typedef struct GWBN_Let GWBN_Let;
typedef struct GWBN_Dim GWBN_Dim;
typedef struct GWBN_DefFn GWBN_DefFn;
typedef struct GWBN_Screen GWBN_Screen;

typedef struct GWBN_Circle GWBN_Circle;
typedef struct GWBN_Line GWBN_Line;
typedef struct GWBN_Paint GWBN_Paint;
/*
	Этот код нужно генерировать, так как это будет в разы быстрей 
*/


/*
	Statement
*/
typedef struct {
	int type;
	union {
		struct GWBN_Call* call;
		struct GWBN_Let* let;
		struct GWBN_Dim* dim;
		struct GWBN_DefFn* def_fn;
		struct GWBN_Circle* circle;
		struct GWBN_Screen* screen;
		struct GWBN_Line* line;
		
	};
} GWBN_Statement;

GWBN_Statement* gwbn_Statement();
void gwbn_DeleteStatement();

/*
	Call
*/
struct GWBN_Call { /* Not implemented */};

/*
	Let
*/
struct GWBN_Let { /* Not implemented */};

/*
	Dim 
*/
struct GWBN_Dim { /* Not implemented */};

/*
	DefFn
*/
struct GWBN_DefFn {/* Not implemented */};

/*
	If Then Else
*/
#endif
