/* GWBasic Display Header, contains structures which describes display data */

typedef struct GWBG_Display GWBG_Display;
typedef struct GWBG_TextBuffer GWBG_TextBuffer;

struct GWBG_Display
{
	GWBG_TextBuffer* text_buffer;
};

struct GWBG_TextBuffer
{
	char **text_field;		/* текстовый буфер */
	int height, width;		/* высота, и длина текстовой матрицы */

};

