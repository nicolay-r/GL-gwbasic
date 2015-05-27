5  	LET circles% = 6: LET thickness% = 60: LET score% = 0: LET shoots% = 10
10 	LET x# = RND: LET y# = RND
20 	LET screenX% = INT(x#*640): LET screenY% = INT(y#*480)
25 	LET radius% = INT(RND*50)
30 	CIRCLE (screenX%, screenY%) radius%
40 	FOR i% = 0 TO circles%
50		CIRCLE (screenX%, screenY%) radius% + i%*thickness%
60 	NEXT i%
70 	LINE (screenX% - circles%*thickness% - radius%, screenY%) - (screenX% + circles%*thickness% + radius%, screenY%), 10
71 	LINE (screenX%, screenY% - circles%*thickness% - radius%) - (screenX%, screenY% + circles%*thickness% + radius%), 10
80 	LET uX% = 0: LET uY% = 0
90 	FOR i% = 0 TO shoots%
92		PRINT "You got ", shoots% - i% , " shoots."
95 		INPUT "Shoot at coordinate: ", uX%, uY%
100		dist# = SQR((uX%-screenX%)*(uX%-screenX%) + (uY%-screenY%)*(uY%-screenY%))
105		PRINT "Distance: ", dist#
106		LINE (uX% - 30, uY% - 30) - (uX% + 30, uY% + 30), 10
110		LINE (uX% - 30, uY% + 30) - (uX% + 30, uY% - 30), 10
120		IF dist# < radius% THEN PRINT "You win!": LET shoots% = i% - 1 
130	NEXT i%
140	PRINT "Your Score: ", score%
