/* GWBasic Display Header, contains structures which describes display data */

#ifndef _GWBG_DISPLAY_H_
#define _GWBG_DISPLAY_H_

#include "core.h"			/* GWBC_DisplayPoint */
#include "runtime.h"			/* GWBE_Environment */

typedef struct GWBG_Ide GWBG_Ide;
typedef struct GWBG_TextBuffer GWBG_TextBuffer;

/*
	Structures
*/
struct GWBG_Ide
{
	GWBG_TextBuffer* text_buffer;	/* Текстовый буфер (строка пользователя) */
	GWBE_Environment* env;		/* Окружение (Структура Runtime GWBasic) */

	int height, width;		/* размер экрана */
	char* input_buffer;		/* буфер введенной пользователем строки */
};

struct GWBG_TextBuffer
{
	char **text_field;		/* текстовый буфер */
	int height, width;		/* высота, и длина текстовой матрицы */
	GWBC_DisplayPoint* cursor;	/* координаты курсора */
};

/*
	Prototypes
*/

/* Ide */
GWBG_Ide* gwbg_NewIde();
void gwbg_Ide_CreateTextBuffer(GWBG_Ide* ide, int height, int width);
void gwbg_Ide_DeleteTextBuffer(GWBG_Ide* ide);
/* Display */

/* TextBuffer */
void gwbg_TextBuffer_PushString(GWBG_TextBuffer* text_buffer, char* string);
void gwbg_TextBuffer_PushChar(GWBG_TextBuffer* text_buffer, char c);
void gwbg_TextBuffer_PopChar(GWBG_TextBuffer* text_buffer);
void gwbg_TextBuffer_CursorNextLine(GWBG_TextBuffer* text_buffer);

/* Environment */
void gwbg_Environment_ClearRequest(GWBE_Environment* env);
void gwbg_Environment_PushCharToRequest(GWBE_Environment* env, char c);
void gwbg_Environment_PopCharFromRequest(GWBE_Environment* env);

#endif
