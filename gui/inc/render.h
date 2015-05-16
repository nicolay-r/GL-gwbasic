/* GWBasic Header, contains rendering functions */

#include "display.h"
#include "core.h"

#define GWBGS_CURSORMARKER	'_'

void gwbg_SetTextLinePosition(int x, int y);
void gwbg_RenderTextLine(char c);

void gwbg_Ide_Render(GWBG_Ide* ide);
void gwbg_TextBuffer_Render(GWBG_TextBuffer* text_buffer, GWBC_DisplayPoint left_upper_corner_offset);
void gwbg_TextBuffer_MarkCursorPosition(GWBG_TextBuffer* text_buffer);
