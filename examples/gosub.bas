1	cls
5 	rmin% = 0 : rmax% = 30 : rcurr% = rmin% : circlesCount% = 0: colour% = 1
10	input "Circles Count?", circlesCount%
20	for i% = 0 to circlesCount%
30		circleX% = int(rnd*640) : circleY% = int(rnd*480)
35		colour% = colour% + 1 
36		if colour% > 15 then colour% = 1 
40		gosub 400
45	next i%
50	end
400	for t% = rmin% to rmax%
410		rcurr% = t%
420		gosub 500
430	next t%
440	return  
500	circle (circleX%, circleY%), rcurr%, colour%
510	return 
