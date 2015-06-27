/* GWBParser Variables struct */

#ifndef _GWBN_VARS_H_
#define _GWBN_VARS_H_

#include <stdlib.h>

typedef struct GWBN_Variables GWBN_Variables;
typedef struct GWBN_Variable GWBN_Variable;
typedef struct GWBN_StringVariable GWBN_StringVariable;
typedef struct GWBN_NumericVariable GWBN_NumericVariable;
typedef struct GWBN_ArrayVariable GWBN_ArrayVariable;
typedef struct GWBN_ArrayVariables GWBN_ArrayVariables;
typedef struct GWBN_SystemVariable GWBN_SystemVariable;

/*
	Dependencies
*/
#include "indexes.h"

/*
	Structures
*/

/* 
	Variables 
*/
struct GWBN_Variables {
	GWBN_Variable* var;
	struct GWBN_Variables* next;
};
struct GWBN_Variable {
	int type;		/*	GWBNT_STRINGVARIABLE
					GWBNT_NUMERICVARIABLE
					GWBNT_STRINGVARIABLE	
					GWBNT_SYSTEMVARIABLE	*/
	union {
		GWBN_StringVariable* str;
		GWBN_NumericVariable* num;
		GWBN_ArrayVariable* arr;
		GWBN_SystemVariable* sys;
	};
};
struct GWBN_StringVariable {
	char* name;
};
struct GWBN_NumericVariable {
	int type;		/* 	GWBNT_INTEGERVARIABLE
					GWBNT_SINGLEPRECISIONVARIABLE 
					GWBNT_DOUBLEPRECISIONVARIABLE 	*/
	char* name;
};
struct GWBN_SystemVariable {
	int var_type;		/* variable type */
	int val_type;		/* value type */
};

/* 
	Array Variables 
*/
struct GWBN_ArrayVariables {
	GWBN_ArrayVariable* var;
	struct GWBN_ArrayVariables* next;
};

struct GWBN_ArrayVariable {
	int type; 		/* GWBNT_StringVariable, GWBNT_NumericVariable */
	GWBN_Indexes* dims;

	union {
		GWBN_StringVariable* str;
		GWBN_NumericVariable* num;
	};
};
/*
	Prototypes
*/
GWBN_Variables* gwbn_NewVariables();
void gwbn_DeleteVariables(GWBN_Variables* ptr);
GWBN_Variable* gwbn_NewVariable();
void gwbn_DeleteVariable(GWBN_Variable* ptr);
GWBN_StringVariable* gwbn_NewStringVariable();
void gwbn_DeleteStringVariable(GWBN_StringVariable* ptr);
GWBN_NumericVariable* gwbn_NewNumericVariable();
void gwbn_DeleteNumericVariable(GWBN_NumericVariable* ptr);
GWBN_ArrayVariable* gwbn_NewArrayVariable();
void gwbn_DeleteArrayVariable(GWBN_ArrayVariable* ptr);
GWBN_ArrayVariables* gwbn_NewArrayVariables();
void gwbn_DeleteArrayVariables(GWBN_ArrayVariables* ptr);
GWBN_SystemVariable* gwbn_NewSystemVariable();
void gwbn_DeleteSystemVariable(GWBN_SystemVariable* ptr);
#endif
