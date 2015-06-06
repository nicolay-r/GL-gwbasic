/* GWBasic Handler with possible Semantic Errors */

#ifndef _GWBR_ERRORS_H_
#define _GWBR_ERRORS_H_

/*
	Possible Results in GWBasic Runtime
*/

/* Results */
#define GWBR_RESULT_OK			0
#define GWBR_RESULT_NULLPTR		1

/* Errors */
#define GWBR_ERROR_TYPEMISMATCH		100		/* Несовместимость типов */

/* Notifications */
#define GWBR_NOTIFICATION_WAITFORVALUE  200		/* Ожидание ввода результата пользователем */		

/*
	Result Of Interpretation
*/
typedef struct GWBR_Result GWBR_Result;

struct GWBR_Result {
	int type;
	union {
		char* msg;	/* same as gwbr_results */
	};
};

#endif
