/* GWBasic Auxulary sructs and prototypes for Circle ast node */

#ifndef _GWBN_CIRCLE_H_
#define _GWBN_CIRCLE_H_

typedef struct GWBN_Circle GWBN_Circle;
typedef struct GWBN_CircleOptions GWBN_CircleOptions;

/*
	Structures
*/
struct GWBN_Circle {
	GWBN_ScreenCoordinate *coord;
	GWBN_NumericExpression* r;  
	GWBN_CircleOptions* opts;
};
struct GWBN_CircleOptions {
	GWBN_NumericExpression* color;
};

/*
	Prototypes
*/
GWBN_Circle* gwbn_NewCircle();
void gwbn_DeleteCircle(GWBN_Circle* ptr);
GWBN_CircleOptions* gwbn_NewCircleOptions();
void gwbn_DeleteCircleOptions(GWBN_CircleOptions* ptr);

#endif
