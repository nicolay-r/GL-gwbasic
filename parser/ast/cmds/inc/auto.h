#ifndef _GWBASIC_AUTO_H_
#define _GWBASIC_AUTO_H_

/*
	GWBasic Auto struct
*/
typedef struct Auto {
	int line_number;
	int increment;
} Auto;

/*
	GWBasic Auto command ctor
*/
Auto* gwbn_Auto(int line_number, int increment);

#endif
