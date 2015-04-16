#include "inc/cmds.h"

GWBN_Command* gwbn_NewCommand()
{
	GWBN_Command* result = (GWBN_Command*) malloc(sizeof(GWBN_Command));
	return result;
}

GWBN_System* gwbn_NewSystem() {
	GWBN_System* result = (GWBN_System*) malloc (sizeof(GWBN_System));
	return result;
} 
	
void gwbn_DeleteSystem(GWBN_System* ptr) {
	free(ptr);
}
	
GWBN_Auto* gwbn_NewAuto() {
	GWBN_Auto* result = (GWBN_Auto*) malloc (sizeof(GWBN_Auto));
	return result;
} 
	
void gwbn_DeleteAuto(GWBN_Auto* ptr) {
	free(ptr);
}
	
GWBN_BLoad* gwbn_NewBLoad() {
	GWBN_BLoad* result = (GWBN_BLoad*) malloc (sizeof(GWBN_BLoad));
	return result;
} 
	
void gwbn_DeleteBLoad(GWBN_BLoad* ptr) {
	free(ptr);
}
	
GWBN_BSave* gwbn_NewBSave() {
	GWBN_BSave* result = (GWBN_BSave*) malloc (sizeof(GWBN_BSave));
	return result;
} 
	
void gwbn_DeleteBSave(GWBN_BSave* ptr) {
	free(ptr);
}
	
GWBN_Merge* gwbn_NewMerge() {
	GWBN_Merge* result = (GWBN_Merge*) malloc (sizeof(GWBN_Merge));
	return result;
} 
	
void gwbn_DeleteMerge(GWBN_Merge* ptr) {
	free(ptr);
}
	
GWBN_ChDir* gwbn_NewChDir() {
	GWBN_ChDir* result = (GWBN_ChDir*) malloc (sizeof(GWBN_ChDir));
	return result;
} 
	
void gwbn_DeleteChDir(GWBN_ChDir* ptr) {
	free(ptr);
}
	
GWBN_Clear* gwbn_NewClear() {
	GWBN_Clear* result = (GWBN_Clear*) malloc (sizeof(GWBN_Clear));
	return result;
} 
	
void gwbn_DeleteClear(GWBN_Clear* ptr) {
	free(ptr);
}
	
GWBN_Cont* gwbn_NewCont() {
	GWBN_Cont* result = (GWBN_Cont*) malloc (sizeof(GWBN_Cont));
	return result;
} 
	
void gwbn_DeleteCont(GWBN_Cont* ptr) {
	free(ptr);
}
	
GWBN_Delete* gwbn_NewDelete() {
	GWBN_Delete* result = (GWBN_Delete*) malloc (sizeof(GWBN_Delete));
	return result;
} 
	
void gwbn_DeleteDelete(GWBN_Delete* ptr) {
	free(ptr);
}
	
GWBN_Edit* gwbn_NewEdit() {
	GWBN_Edit* result = (GWBN_Edit*) malloc (sizeof(GWBN_Edit));
	return result;
} 
	
void gwbn_DeleteEdit(GWBN_Edit* ptr) {
	free(ptr);
}
	
GWBN_Files* gwbn_NewFiles() {
	GWBN_Files* result = (GWBN_Files*) malloc (sizeof(GWBN_Files));
	return result;
} 
	
void gwbn_DeleteFiles(GWBN_Files* ptr) {
	free(ptr);
}
	
GWBN_Kill* gwbn_NewKill() {
	GWBN_Kill* result = (GWBN_Kill*) malloc (sizeof(GWBN_Kill));
	return result;
} 
	
void gwbn_DeleteKill(GWBN_Kill* ptr) {
	free(ptr);
}
	
GWBN_List* gwbn_NewList() {
	GWBN_List* result = (GWBN_List*) malloc (sizeof(GWBN_List));
	return result;
} 
	
void gwbn_DeleteList(GWBN_List* ptr) {
	free(ptr);
}
	
GWBN_LList* gwbn_NewLList() {
	GWBN_LList* result = (GWBN_LList*) malloc (sizeof(GWBN_LList));
	return result;
} 
	
void gwbn_DeleteLList(GWBN_LList* ptr) {
	free(ptr);
}
	
GWBN_Load* gwbn_NewLoad() {
	GWBN_Load* result = (GWBN_Load*) malloc (sizeof(GWBN_Load));
	return result;
} 
	
void gwbn_DeleteLoad(GWBN_Load* ptr) {
	free(ptr);
}
	
GWBN_MkDir* gwbn_NewMkDir() {
	GWBN_MkDir* result = (GWBN_MkDir*) malloc (sizeof(GWBN_MkDir));
	return result;
} 
	
void gwbn_DeleteMkDir(GWBN_MkDir* ptr) {
	free(ptr);
}
	
GWBN_Name* gwbn_NewName() {
	GWBN_Name* result = (GWBN_Name*) malloc (sizeof(GWBN_Name));
	return result;
} 
	
void gwbn_DeleteName(GWBN_Name* ptr) {
	free(ptr);
}
	
GWBN_TrOn* gwbn_NewTrOn() {
	GWBN_TrOn* result = (GWBN_TrOn*) malloc (sizeof(GWBN_TrOn));
	return result;
} 
	
void gwbn_DeleteTrOn(GWBN_TrOn* ptr) {
	free(ptr);
}
	
GWBN_TrOff* gwbn_NewTrOff() {
	GWBN_TrOff* result = (GWBN_TrOff*) malloc (sizeof(GWBN_TrOff));
	return result;
} 
	
void gwbn_DeleteTrOff(GWBN_TrOff* ptr) {
	free(ptr);
}
	
