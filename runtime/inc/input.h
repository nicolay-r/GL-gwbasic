/* GWBasic Input runtime module */

#ifndef _GWBR_INPUT_H_
#define _GWBR_INPUT_H_

typedef struct GWBI_Input GWBI_Input;
typedef struct GWBI_UserRequest GWBI_UserRequest;
typedef struct GWBI_InputRequest GWBI_InputRequest;

/*
	Input
*/
#define GWBE_INPUT_BUFFERLENGTH			2048 	/* Размер буфера входной строки */

/*
	Cache Structures
*/
struct GWBI_UserRequest{
	/* Nothing */
};

struct GWBI_InputRequest{
	int var_index;				/* номер переменной, к которой нужно присвоить введенное значение*/
};

/*
	Input Structure
*/
struct GWBI_Input {
	char* buffer;				/* буфер прочитанной строки */
	size_t buffer_len;			/* длина буфера (задается при инициализации Environment структуры */
	
	struct {
		GWBI_UserRequest user_request;
		GWBI_InputRequest input_request; /* дополнительная информация для типа GWBIT_INPUTREQUEST */
	};
};

GWBI_Input* gwbi_NewInput();
void gwbi_GetString(GWBE_Environment* env);
int gwbi_GetInteger(GWBE_Environment* env);
float gwbi_GetFloat(GWBE_Environment* env);
double gwbi_GetDouble(GWBE_Environment* env);

#endif
