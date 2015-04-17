/* GWBasic Runtime Core Elements and Functions */

#ifndef _GWBR_CORE_H_
#define _GWBR_CORE_H_

typedef union GWBC_Value GWBC_Value;
typedef struct GWBC_ArrayDimension GWBC_ArrayDimension;    
typedef struct GWBC_Array GWBC_Array;
typedef struct GWBC_Variable GWBC_Variable;

/*
	Variable
*/
struct GWBC_Variable{
	int type;
	char* name;
	union {
		GWBC_Value* vals;
		GWBC_Array* arr;
	};
};

/*
	Array
*/
struct GWBC_Array{
	int elem_type;
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
union GWBC_Value{
	int int_val;		/* integer */
	float float_val;	/* single prec */
	double double_val;	/* double prec */	
	char* str;		/* string */
};

/*
	Functions
*/
GWBC_Variable* gwbc_NewVariable();
void gwbc_DeleteVariable(GWBC_Variable* var);

#endif
