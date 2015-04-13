/* GWBasic Commands */
#ifndef _GWBASIC_COMMANDS_H_
#define _GWBASIC_COMMANDS_H_

#include "auto.h"

#define GWBNT_SYSTEM	3001
#define GWBNT_AUTO	3002
#define GWBNT_BLOAD	3003
// Дописать остальные типы ...


typedef struct Command {
	int type;
	union Commands {
		Auto* _auto;				
	} cmds;
} Command;

Command* gwbn_Command(int type, union Commands cmds);
#endif
