#!/usr/bin/python

import sys

def generateCtorPrototype(nterm):
	ctor_prot = """GWBN_%s* gwbn_New%s();"""%(nterm, nterm)
	return ctor_prot

def generateDtorPrototype(nterm):
	dtor_prot = """void gwbn_Delete%s(GWBN_%s* ptr);"""%(nterm, nterm)
	return dtor_prot

def generateCtor(nterm):
	ctor = """GWBN_%s* gwbn_New%s() {
	GWBN_%s* result = (GWBN_%s*) malloc (sizeof(GWBN_%s));
	return result;
} 
	"""%(nterm, nterm, nterm, nterm, nterm)
	return ctor

def generateDtor(nterm):
	dtor = """void gwbn_Delete%s(GWBN_%s* ptr) {
	free(ptr);
}
	"""%(nterm, nterm)
	return dtor

def generateStructPrototype(nterm):
	prot = """typedef struct GWBN_%s GWBN_%s;"""%(nterm, nterm)
	return prot

def generateStruct(nterm):
	struct = """struct GWBN_%s {
	/* Not Implemented */
};"""%(nterm)
	return struct


# begin
if (len(sys.argv) < 2):
	print "usage: ctors.py <filename>"
else:
	with open(sys.argv[1], "r") as f:
		lines = f.readlines()
		for line in lines:
			nterm = line.strip()	
			print generateCtorPrototype(nterm)
			print generateDtorPrototype(nterm)	
		print
		for line in lines:
			nterm = line.strip()
			print generateStructPrototype(nterm)
		for line in lines:
			nterm = line.strip()
			print generateStruct(nterm)
		for line in lines:
			nterm = line.strip()		
			print generateCtor(nterm)
			print generateDtor(nterm)
