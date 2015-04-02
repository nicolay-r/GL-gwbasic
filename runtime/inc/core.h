/* GWBasic Runtime Core Elements and Functions */

#ifndef _GWBR_CORE_H_
#define _GWBR_CORE_H_

/*
	Values
*/
typedef union {
	int int_val;		/* integer */
	float float_val;	/* single prec */
	double double_val;	/* double prec */	
	char* str;		/* string */
} GWBC_Value;

/*
	Array
*/
typedef struct GWBC_ArrayDimension {
	int length;
	union {
		GWBC_Value* val;	
		struct GWBC_ArrayDimension* next_dim;
	}* cells;	/* cells[length] */
} GWBC_ArrayDimension;

typedef struct {
	int elem_type;
	int dim_count;
	GWBC_ArrayDimension* dim; 
} GWBC_Array; 

/*
	Variable
*/
typedef struct {
	int type;
	char* name;
	union {
		GWBC_Value* vals;
		GWBC_Array* arr;
	};
} GWBC_Variable;

/*
	Functions
*/
GWBC_Variable* gwbc_NewVariable();
void gwbc_DeleteVariable(GWBC_Variable* var);

#endif
