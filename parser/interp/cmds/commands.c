#include "inc/commands.h"
#include <stdlib.h> /* malloc */

Command* gwbn_Command(int type, union Commands cmds)
{
	Command* cmd = malloc(sizeof(Command));
	cmd->type = type;
	cmd->cmds = cmds;

	return cmd;
}
