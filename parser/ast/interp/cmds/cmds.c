#include "inc/cmds.h"

GWBN_Command* gwbn_NewCommand()
{
	GWBN_Command* result = (GWBN_Command*) malloc(sizeof(GWBN_Command));
	return result;
}
