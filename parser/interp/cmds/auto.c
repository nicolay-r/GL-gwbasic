
#include "inc/auto.h"
#include <stdlib.h>

Auto* gwbn_Auto(int line_number, int increment)
{
	Auto* _auto = malloc(sizeof(Auto));
	_auto->line_number = line_number;
	_auto->increment = increment;

	return _auto;
}
