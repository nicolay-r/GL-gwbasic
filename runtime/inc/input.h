/* GWBasic Input runtime module */

#ifndef _GWBR_INPUT_H_
#define _GWBR_INPUT_H_

typedef struct GWBI_Input GWBI_Input;

/*
	Input
*/
#define GWBE_INPUT_BUFFERLENGTH			2048
struct GWBI_Input {
	char* buffer;				/* буфер прочитанной строки */
	size_t buffer_len;			/* длина буфера (задается при инициализации Environment структуры */
};

void gwbi_GetString(GWBE_Environment* env);
int gwbi_GetInteger(GWBE_Environment* env);
float gwbi_GetFloat(GWBE_Environment* env);
double gwbi_GetDouble(GWBE_Environment* env);

#endif
