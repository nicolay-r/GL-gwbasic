/* GWBN_Variable Prototypes declaration */

#include "inc/vars.h"

GWBN_Indexes* gwbn_NewIndexes()
{
	GWBN_Indexes* result = (GWBN_Indexes*) malloc (sizeof(GWBN_Indexes));
	return result;
}
void gwbn_DeleteIndexes(GWBN_Indexes* ptr)
{
	free(ptr);
}
