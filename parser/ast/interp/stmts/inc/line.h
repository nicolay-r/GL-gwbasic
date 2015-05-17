/* GWBasic Auxulary sructs and prototypes for Line ast node */

#ifndef _GWBN_LINE_H_
#define _GWBN_LINE_H_

typedef struct GWBN_Line GWBN_Line;
typedef struct GWBN_LineOptions GWBN_LineOptions;

/*
	Structures
*/
struct GWBN_Line {
	GWBN_ScreenCoordinate *coord_a, *coord_b; 
	GWBN_LineOptions* opts;
};
struct GWBN_LineOptions {
	GWBN_NumericExpression* color;
};

/*
	Prototypes
*/
GWBN_Line* gwbn_NewLine();
void gwbn_DeleteLine(GWBN_Line* ptr);
GWBN_LineOptions* gwbn_NewLineOptions();
void gwbn_DeleteLineOptions(GWBN_LineOptions* ptr);

#endif
