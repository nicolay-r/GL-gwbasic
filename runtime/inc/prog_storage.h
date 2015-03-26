/* GWBasic header for program storage structures */

/*
	Add new line into the program storage
*/
void gwbs_AddNewLine(int lineNumber, char* contents);

/*
	Remove existed line from the program storage	
*/
void gwbs_DeleteLine(int lineNumber);

/*
	Replace existed line in the program storage
*/
void gwbs_ReplaceExisted(int lineNumber, char* new_contents);
