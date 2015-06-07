/* GWBasic Display Header, contains structures which describes display data */

#ifndef _GWBG_DISPLAY_H_
#define _GWBG_DISPLAY_H_

#include "core.h"			/* GWBC_DisplayPoint */
#include "runtime.h"			/* GWBE_Environment */
#include <GL/glut.h>

typedef struct GWBG_Ide GWBG_Ide;
typedef struct GWBG_TextBuffer GWBG_TextBuffer;
typedef struct GWBG_Canvas GWBG_Canvas;
typedef struct GWBG_ObjectsToDraw GWBG_ObjectsToDraw;
/*
	Global Variables
*/
GWBG_Ide* ide;

/*
	Structures
*/
struct GWBG_Ide
{
	GWBG_TextBuffer* text_buffer;	/* Текстовый буфер (строка пользователя) */
	GWBE_Environment* env;		/* Окружение (Структура Runtime GWBasic) */

	int height, width;		/* размер экрана */
	char* input_buffer;		/* буфер введенной пользователем строки */
	
	GWBG_Canvas* canvas;
};

struct GWBG_TextBuffer
{
	char **text_field;		/* текстовый буфер */
	int height, width;		/* высота, и длина текстовой матрицы */
	GWBC_DisplayPoint* cursor;	/* координаты курсора */
};

struct GWBG_ObjectsToDraw
{
	int type; /* GWBCT_Line, GWBCT_Circle */
	union {
		GWBC_Line line;
		GWBC_Circle circle;
	};
};

#define GWBG_CANVAS_MAXOBJECTS		10

struct GWBG_Canvas
{
	GWBG_ObjectsToDraw objects[GWBG_CANVAS_MAXOBJECTS];
	int to_draw_count;

	GLubyte *data;			/* Для графики */
	int pixel_format;		/* GL_RGB, GL_BGR, ... */
	int pixel_type;			/* GL_UNSIGNED_BYTE */
};

/*
	Prototypes
*/

/* Ide */
GWBG_Ide* gwbg_NewIde();
void gwbg_Ide_SetCanvas(GWBG_Ide* ide, int pixel_type);
void gwbg_Ide_SetTextBuffer(GWBG_Ide* ide, int rows, int columns);
void gwbg_Ide_DeleteTextBuffer(GWBG_Ide* ide);

/* TextBuffer */
void gwbg_TextBuffer_PushString(GWBG_TextBuffer* text_buffer, char* string);
void gwbg_TextBuffer_PushChar(GWBG_TextBuffer* text_buffer, char c);
void gwbg_TextBuffer_PopChar(GWBG_TextBuffer* text_buffer);
void gwbg_TextBuffer_CursorNextLine(GWBG_TextBuffer* text_buffer);
void gwbg_TextBuffer_Clear(GWBG_TextBuffer* text_buffer);

/* Environment */
void gwbg_Environment_ClearRequest(GWBE_Environment* env);
void gwbg_Environment_PushCharToRequest(GWBE_Environment* env, char c);
void gwbg_Environment_PopCharFromRequest(GWBE_Environment* env);

/* Canvas */
void gwbg_Canvas_AddLine(GWBG_Canvas* canvas, GWBC_Line line);
void gwbg_Canvas_AddCircle(GWBG_Canvas* canvas, GWBC_Circle circle);
void gwbg_Canvas_Clear(GWBG_Canvas* canvas);
#endif
