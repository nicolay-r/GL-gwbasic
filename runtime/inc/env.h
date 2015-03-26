/* GWBasic IDE Environment structure and operations with this structure */

#ifndef _GWBR_ENVIRONMENT_H_

#define _GWBR_ENVIRONMENT_H_

typedef struct {
	/* нужно дополнить аргументами, которые 
	будут доступны любому молдулю IDE GWBasiс. */
} GWBE_Environment;

/*
	Malloc environment structure
*/
GWBE_Environment* gwbe_Create();
/*
	Free environment structure
*/
void gwbe_Delete(GWBE_Environment* env);

#endif
