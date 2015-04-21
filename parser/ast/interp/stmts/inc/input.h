/* GWBasic Input Statement */

#ifndef _GWBN_INPUT_H_
#define _GWBN_INPUT_H_

#include "../../expr/inc/expr.h"

typedef struct GWBN_Input GWBN_Input;
typedef struct GWBN_InputPrompt GWBN_InputPrompt;
typedef int GWBN_InputPromptEndType;
typedef GWBB_String GWBN_InputPromptString;

/*
	Structs
*/
struct GWBN_InputPrompt {
	GWBN_InputPromptString str;
	GWBN_InputPromptEndType end_type; 
};

/*
	Prototypes
*/
GWBN_InputPrompt* gwbn_NewInputPrompt();
void gwbn_DeleteInputPrompt(GWBN_InputPrompt* ptr);

#endif
