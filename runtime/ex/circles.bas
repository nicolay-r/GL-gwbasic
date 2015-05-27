5  	LET circles% = 6: LET dist% = 60
10 	LET x# = RND: LET y# = RND
20 	LET screenX% = INT(x#*640): LET screenY% = INT(y#*480)
25 	LET radius% = INT(RND*50)
30 	CIRCLE (screenX%, screenY%) radius%
40 	FOR i% = 0 TO circles%
50		CIRCLE (screenX%, screenY%) radius% + i%*dist%
60 	NEXT i%
70 	LINE (screenX% - circles%*dist% - radius%, screenY%) - (screenX% + circles%*dist% + radius%, screenY%), 10
71 	LINE (screenX%, screenY% - circles%*dist% - radius%) - (screenX%, screenY% + circles%*dist% + radius%), 10
80 	LET uX% = 0: LET uY% = 0
90 	FOR i% = 0 TO 1
95 		INPUT "Shoot at coordinate: ", uX%, uY%
100		LINE (uX% - 30, uY% - 30) - (uX% + 30, uY% + 30), 10
105		LINE (uX% - 30, uY% + 30) - (uX% + 30, uY% - 30), 10
110	NEXT i%
