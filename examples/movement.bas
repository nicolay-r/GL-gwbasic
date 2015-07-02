10      cls
15      dim a%(32, 24)
20      let x% = 160 : let y% = 120
40      while 1
50              pressed% = inkey$
60              IF pressed% = 119 then cls : print "UP"; : y% = y% + 10 : gosub 500
70              IF pressed% = 115 then cls : print "DOWN"; : y% = y% - 10 : gosub 500
80              IF pressed% = 97 then cls : print "LEFT"; : x% = x% - 10 : gosub 500
90              IF pressed% = 100 then cls : print "RIGHT"; : x% = x% + 10 : gosub 500
110     wend
500     for i% = 0 to 20
510             circle (x%, y%), i%, 4
520     next i%
600     a%(x%/10,y%/10) = a%(x%/10,y%/10) + 1
605     for i% = 0 to 32-1
610             for j% = 0 to 24-1
620                     print a%(i%, j%), " "
630             next j%
635             print ;
640     next i%
650     return
