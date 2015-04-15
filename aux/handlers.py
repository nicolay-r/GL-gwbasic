#!/usr/bin/python

import sys

def generateHandlerPrototype(nterm):
	hndl_prot = """GWBR_Result gwbh_%s(GWBE_Environment *env, GWBN_%s* node);"""%(nterm, nterm)
	return hndl_prot
def generateHandler(nterm):
	
	hndlr = """GWBR_Result gwbh_%s(GWBE_Environment *env, GWBN_%s* node) {
	GWBR_Result result;

	/* \"%s\" handler implementation */
	printf(\"In \\"%s\\" Handler\\n\"); 

	result.type = GWBR_RESULT_OK;
	return result;	 
} 
	"""%(nterm, nterm, nterm, nterm)
	return hndlr

# begin
if (len(sys.argv) < 2):
	print "usage: ctors.py <filename>"
else:
	with open(sys.argv[1], "r") as f:
		lines = f.readlines()
		for line in lines:
			nterm = line.strip()	
			print generateHandlerPrototype(nterm)
		print
		for line in lines:
			nterm = line.strip()
			print generateHandler(nterm)
