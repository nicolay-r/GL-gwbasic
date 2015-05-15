/* GWBasic Display Header, contains structures which describes display data */

#ifndef _GWBG_DISPLAY_H_
#define _GWBG_DISPLAY_H_

#include "core.h"

typedef struct GWBG_Display GWBG_Display;
typedef struct GWBG_TextBuffer GWBG_TextBuffer;

/*
	Structures
*/
struct GWBG_Display
{
	GWBG_TextBuffer* text_buffer;
	int height, width;
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
GWBG_Display* gwbg_NewDisplay();
void gwbg_Display_CreateTextBuffer(GWBG_Display* display, int height, int width);
void gwbg_Display_DeleteTextBuffer(GWBG_Display* display);

/* TextBuffer */
void gwbg_TextBuffer_PushChar(GWBG_TextBuffer* text_buffer, char c);
void gwbg_TextBuffer_PopChar(GWBG_TextBuffer* text_buffer);

#endif
