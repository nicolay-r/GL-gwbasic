/* GWBasic Input Statement */

#ifndef _GWBN_INPUT_H_
#define _GWBN_INPUT_H_

#include "../../expr/inc/expr.h"

typedef struct GWBN_Input GWBN_Input;
typedef struct GWBN_InputPrompt GWBN_InputPrompt;
typedef struct GWBN_InputPromptEnd GWBN_InputPromptEnd;

/*
	Structs
*/
struct GWBN_Input {
	/* Not Implemented */
};
struct GWBN_InputPrompt {
	/* Not Implemented */
};
struct GWBN_InputPromptEnd {
	/* Not Implemented */
};

/*
	Prototypes
*/
GWBN_InputPrompt* gwbn_NewInputPrompt();
void gwbn_DeleteInputPrompt(GWBN_InputPrompt* ptr);
GWBN_InputPromptEnd* gwbn_NewInputPromptEnd();
void gwbn_DeleteInputPromptEnd(GWBN_InputPromptEnd* ptr);

#endif
