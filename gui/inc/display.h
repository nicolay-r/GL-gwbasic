/* GWBasic Display Header, contains structures which describes display data */

#ifndef _GWBG_DISPLAY_H_
#define _GWBG_DISPLAY_H_

#include "core.h"
#include "runtime.h"

typedef struct GWBG_Ide GWBG_Ide;
typedef struct GWBG_TextBuffer GWBG_TextBuffer;

/*
	Structures
*/
struct GWBG_Ide
{
	GWBG_TextBuffer* text_buffer;
	GWBE_Environment* env;

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

/* Display */
GWBG_Ide* gwbg_NewDisplay();
void gwbg_Display_CreateTextBuffer(GWBG_Ide* ide, int height, int width);
void gwbg_Display_DeleteTextBuffer(GWBG_Ide* ide);

/* TextBuffer */
void gwbg_TextBuffer_PushString(GWBG_TextBuffer* text_buffer, char* string);
void gwbg_TextBuffer_PushChar(GWBG_TextBuffer* text_buffer, char c);
void gwbg_TextBuffer_PopChar(GWBG_TextBuffer* text_buffer);
void gwbg_TextBuffer_CursorNextLine(GWBG_TextBuffer* text_buffer);

#endif
