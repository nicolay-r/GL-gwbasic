/* GWBasic Runtime Core Elements and Functions */

#ifndef _GWBR_CORE_H_
#define _GWBR_CORE_H_

#include "errors.h"

/*
	Value Types
*/
typedef struct GWBC_VariableListNode GWBC_VariableListNode;
typedef struct GWBC_Value GWBC_Value;
typedef struct GWBC_ArrayDimension GWBC_ArrayDimension;    
typedef struct GWBC_Array GWBC_Array;
typedef struct GWBC_Variable GWBC_Variable;

/*
	Variable ListNode
*/
struct GWBC_VariableListNode {
	GWBC_Variable* var;
	struct GWBC_VariableListNode *next;
};

/*
	Variable
*/
#define GWBCT_VALUE		1
#define GWBCT_ARRAY		2

struct GWBC_Variable{
	int type;	/* GWBCT_VALUE, GWBCT_ARRAY */
	char* name;
	union {
		GWBC_Value* val;
		GWBC_Array* arr;
	};
};

/*
	Array
*/
#define GWBC_MAX_DIM_COUNT	255

struct GWBC_Array{
	int elem_type;	/* GWBCT_INTEGER, GWBCT_SINGLE, GWBCT_DOUBLE, GWBCT_STRING */
	int dim_count;
	GWBC_ArrayDimension* dim; 
};
 
struct GWBC_ArrayDimension {
	int length;
	union {
		GWBC_Value* val;	
		struct GWBC_ArrayDimension* next_dim;
	}* cells;	/* cells[length] */
};

/*
	Values
*/
#define GWBCT_INTEGER		1
#define GWBCT_SINGLE		2
#define GWBCT_DOUBLE		3
#define GWBCT_STRING		4

struct GWBC_Value{
	int type;			/* GWBCT_INTEGER, GWBCT_SINGLE, GWBCT_DOUBLE, GWBCT_STRING */
	union {
		int int_val;		/* integer */
		float single_val;	/* single prec */
		double double_val;	/* double prec */	
		char* str_val;		/* string */
	};
};

/*
	Functions
*/

/* VariableListNode Prototypes */
GWBC_VariableListNode* gwbc_NewVariableListNode();
void gwbc_VariableListNode_Clear(GWBC_VariableListNode** list);

/* Variable Prototypes */
GWBC_Variable* gwbc_NewVariable(int type, char* name);
void gwbc_DeleteVariable(GWBC_Variable* var);
GWBC_Value gwbc_Variable_GetArrayValue(GWBC_Variable* var, int* indexes);
GWBR_Result gwbc_Variable_SetArrayValue(GWBC_Variable* var, int* indexes, GWBC_Value val);
GWBR_Result gwbc_Variable_SetValue(GWBC_Variable* var, GWBC_Value val);

#endif
