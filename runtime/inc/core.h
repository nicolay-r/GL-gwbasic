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
typedef struct GWBC_Circle GWBC_Circle;
typedef struct GWBC_Line GWBC_Line;
typedef struct GWBC_DisplayPoint GWBC_DisplayPoint;
typedef struct GWBC_Indexes GWBC_Indexes;
typedef union GWBC_ArrayCell GWBC_ArrayCell;

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
#define GWBCT_ARRAYDIMENSION	100

#define GWBC_MAX_DIM_COUNT	255

struct GWBC_Array{
	int type;				/* GWBCT_INTEGER, GWBCT_SINGLE, GWBCT_DOUBLE, GWBCT_STRING */
	int dim_count;				/* Amount of Dimentions */
	GWBC_ArrayDimension* dim; 		/* Array storage */
};
 
union GWBC_ArrayCell {
	GWBC_Value val;
	GWBC_ArrayDimension* next_dim;
};

struct GWBC_ArrayDimension {
	int type;				/* GWBCT_ARRAYDIMENSION, GWBCT_VALUE */
	int length;
	GWBC_ArrayCell* cells;			/* cells[length] */
};

struct GWBC_Indexes {
	int count;
	int* indexes;
};
/*
	Graphics and Display Objects
*/
#define GWBCT_LINE		101
#define GWBCT_CIRCLE		102

/*
	Display Point 
*/
struct GWBC_DisplayPoint{
	int x, y;
};

/*
	Line
*/
struct GWBC_Line{
	GWBC_DisplayPoint a, b;
	GWBC_Value* color;
};

/*
	Circle
*/
struct GWBC_Circle{
	GWBC_DisplayPoint center;
	double r;
	GWBC_Value* color;
};


/*
	Functions
*/

/* VariableListNode Prototypes */
GWBC_VariableListNode* gwbc_NewVariableListNode();
void gwbc_VariableListNode_Clear(GWBC_VariableListNode** list);

/* Variable Prototypes */
GWBC_Variable* gwbc_NewVariable(char* name, int node_var_type);
GWBC_Variable* gwbc_NewArrayVariable(char* name, int node_var_type, GWBC_Indexes* inds);

void gwbc_DeleteVariable(GWBC_Variable* var);
GWBC_Value gwbc_Variable_GetArrayValue(GWBC_Variable* var, GWBC_Indexes* inds);
GWBR_Result gwbc_Variable_SetArrayValue(GWBC_Variable* var, GWBC_Indexes* inds, GWBC_Value val);
GWBR_Result gwbc_Variable_SetValue(GWBC_Variable* var, GWBC_Value val);
void gwbc_InitArrayDimension(GWBC_Indexes* inds, int curr_index, int node_var_type, GWBC_ArrayDimension* this);
  
#endif
