1	LET score% = 0: LET shoots% = 10: LET thickness% = 60
2	CLS
4	PRINT "Your score:", score%
5  	LET circles% = 6
10 	LET x# = RND: LET y# = RND
20 	LET screenX% = INT(x#*640): LET screenY% = INT(y#*480)
25 	LET radius% = thickness%
30 	CIRCLE (screenX%, screenY%), radius%
40 	FOR i% = 0 TO circles%
50		CIRCLE (screenX%, screenY%), radius% + i%*thickness%, 14
60 	NEXT i%
70 	LINE (screenX% - circles%*thickness% - radius%, screenY%) - (screenX% + circles%*thickness% + radius%, screenY%), 13
71 	LINE (screenX%, screenY% - circles%*thickness% - radius%) - (screenX%, screenY% + circles%*thickness% + radius%), 13
80 	LET uX% = 0: LET uY% = 0 : LET isHit% = 0
90 	FOR i% = 0 TO shoots%
92		PRINT "You got ", shoots% - i% , " shoots."
95 		INPUT "Shoot at coordinate: ", uX%, uY%
100		dist# = SQR((uX%-screenX%)*(uX%-screenX%) + (uY%-screenY%)*(uY%-screenY%))
105		PRINT "Distance: ", dist#
106		LINE (uX% - 30, uY% - 30) - (uX% + 30, uY% + 30), 4
110		LINE (uX% - 30, uY% + 30) - (uX% + 30, uY% - 30), 4
115		score% = score% + (circles% - INT(dist#/thickness%)) 
120		IF dist# < radius% THEN isHit% = 1 : shoots% = shoots% - (i% + 1): i% = shoots% + 1 
130	NEXT i%
135	IF isHit% THEN CLS: PRINT "You Hit!": LET thickness% = thickness% - 10: GOTO 4
140	PRINT "Game over. Your Score: ", score%
