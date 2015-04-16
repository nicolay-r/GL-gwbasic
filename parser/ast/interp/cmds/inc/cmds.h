/* GWBasic Commands */
#ifndef _GWBASIC_COMMANDS_H_
#define _GWBASIC_COMMANDS_H_

#include <stdlib.h> /* malloc */
#include "auto.h"

#define GWBNT_SYSTEM	3001
#define GWBNT_AUTO	3002
#define GWBNT_BLOAD	3003

typedef struct GWBN_Command GWBN_Command;
typedef struct GWBN_System GWBN_System;
typedef struct GWBN_Auto GWBN_Auto;
typedef struct GWBN_BLoad GWBN_BLoad;
typedef struct GWBN_BSave GWBN_BSave;
typedef struct GWBN_Merge GWBN_Merge;
typedef struct GWBN_ChDir GWBN_ChDir;
typedef struct GWBN_Clear GWBN_Clear;
typedef struct GWBN_Cont GWBN_Cont;
typedef struct GWBN_Delete GWBN_Delete;
typedef struct GWBN_Edit GWBN_Edit;
typedef struct GWBN_Files GWBN_Files;
typedef struct GWBN_Kill GWBN_Kill;
typedef struct GWBN_List GWBN_List;
typedef struct GWBN_LList GWBN_LList;
typedef struct GWBN_Load GWBN_Load;
typedef struct GWBN_MkDir GWBN_MkDir;
typedef struct GWBN_Name GWBN_Name;
typedef struct GWBN_TrOn GWBN_TrOn;
typedef struct GWBN_TrOff GWBN_TrOff;

/*
	Structures
*/
struct GWBN_Command {
	int type;
	union {
		Auto* _auto;				
	};
};
struct GWBN_System {
	/* Not Implemented */
};
struct GWBN_Auto {
	/* Not Implemented */
};
struct GWBN_BLoad {
	/* Not Implemented */
};
struct GWBN_BSave {
	/* Not Implemented */
};
struct GWBN_Merge {
	/* Not Implemented */
};
struct GWBN_ChDir {
	/* Not Implemented */
};
struct GWBN_Clear {
	/* Not Implemented */
};
struct GWBN_Cont {
	/* Not Implemented */
};
struct GWBN_Delete {
	/* Not Implemented */
};
struct GWBN_Edit {
	/* Not Implemented */
};
struct GWBN_Files {
	/* Not Implemented */
};
struct GWBN_Kill {
	/* Not Implemented */
};
struct GWBN_List {
	/* Not Implemented */
};
struct GWBN_LList {
	/* Not Implemented */
};
struct GWBN_Load {
	/* Not Implemented */
};
struct GWBN_MkDir {
	/* Not Implemented */
};
struct GWBN_Name {
	/* Not Implemented */
};
struct GWBN_TrOn {
	/* Not Implemented */
};
struct GWBN_TrOff {
	/* Not Implemented */
};

GWBN_Command* gwbn_NewCommand();
#endif
