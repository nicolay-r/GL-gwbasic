5  	h% = 20 : w% = 10
10 	dim a%(h%,w%)
30 	for i% = 0 TO h%-1
40		for j% = 0 TO w%-1
50			a%(i%,j%) = i%*j%
60		next j%
70 	next i%
75 	print "result:" 
80 	for i% = 0 to h%-1
90 		for j% = 0 to w%-1
100			print a%(i%, j%)
110		next j%
120		print ""
130 	next i%
