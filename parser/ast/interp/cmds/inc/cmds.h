/* GWBasic Commands */
#ifndef _GWBASIC_COMMANDS_H_
#define _GWBASIC_COMMANDS_H_

#include <stdlib.h> /* malloc */
#include "auto.h"

#define GWBNT_SYSTEM	3001
#define GWBNT_AUTO	3002
#define GWBNT_BLOAD	3003
// Дописать остальные типы ...

typedef struct GWBN_Command GWBN_Command;

struct GWBN_Command {
	int type;
	union {
		Auto* _auto;				
	};
};

GWBN_Command* gwbn_NewCommand();
#endif
