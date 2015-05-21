/* GWBasic Commands */
#ifndef _GWBASIC_COMMANDS_H_
#define _GWBASIC_COMMANDS_H_

#include <stdlib.h> /* malloc */
#include "auto.h"

typedef struct GWBN_Command GWBN_Command;
typedef struct GWBN_Run	GWBN_Run;
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
		GWBN_Run* run;
		GWBN_TrOn* tron;
		GWBN_TrOff* troff;
		GWBN_Load* load;
		GWBN_List* list;
	};
};
struct GWBN_Run {
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
	char* file_name;
	int line_from, line_to;
};
struct GWBN_LList {
	/* Not Implemented */
};
struct GWBN_Load {
	char* file_path;
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

/*
	Prototypes
*/
GWBN_Command* gwbn_NewCommand();
void gwbn_DeleteCommand(GWBN_Command* ptr);
GWBN_Run* gwbn_NewRun();
void gwbn_DeleteRun(GWBN_Run* ptr);
GWBN_System* gwbn_NewSystem();
void gwbn_DeleteSystem(GWBN_System* ptr);
GWBN_Auto* gwbn_NewAuto();
void gwbn_DeleteAuto(GWBN_Auto* ptr);
GWBN_BLoad* gwbn_NewBLoad();
void gwbn_DeleteBLoad(GWBN_BLoad* ptr);
GWBN_BSave* gwbn_NewBSave();
void gwbn_DeleteBSave(GWBN_BSave* ptr);
GWBN_Merge* gwbn_NewMerge();
void gwbn_DeleteMerge(GWBN_Merge* ptr);
GWBN_ChDir* gwbn_NewChDir();
void gwbn_DeleteChDir(GWBN_ChDir* ptr);
GWBN_Clear* gwbn_NewClean();
void gwbn_DeleteClear(GWBN_Clear* ptr);
GWBN_Cont* gwbn_NewCont();
void gwbn_DeleteCont(GWBN_Cont* ptr);
GWBN_Delete* gwbn_NewDelete();
void gwbn_DeleteDelete(GWBN_Delete* ptr);
GWBN_Edit* gwbn_NewEdit();
void gwbn_DeleteEdit(GWBN_Edit* ptr);
GWBN_Files* gwbn_NewFiles();
void gwbn_DeleteFiles(GWBN_Files* ptr);
GWBN_Kill* gwbn_NewKill();
void gwbn_DeleteKill(GWBN_Kill* ptr);
GWBN_List* gwbn_NewList();
void gwbn_DeleteList(GWBN_List* ptr);
GWBN_LList* gwbn_NewLList();
void gwbn_DeleteLList(GWBN_LList* ptr);
GWBN_Load* gwbn_NewLoad();
void gwbn_DeleteLoad(GWBN_Load* ptr);
GWBN_MkDir* gwbn_NewMkDir();
void gwbn_DeleteMkDir(GWBN_MkDir* ptr);
GWBN_Name* gwbn_NewName();
void gwbn_DeleteName(GWBN_Name* ptr);
GWBN_TrOn* gwbn_NewTrOn();
void gwbn_DeleteTrOn(GWBN_TrOn* ptr);
GWBN_TrOff* gwbn_NewTrOff();
void gwbn_DeleteTrOff(GWBN_TrOff* ptr);

#endif
