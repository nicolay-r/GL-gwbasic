10      cls
20      let x% = 320 : let y% = 240
40      while 1
50              pressed% = inkey$
60              IF pressed% = 119 then cls : print "UP" : y% = y% + 10: gosub 500
70              IF pressed% = 115 then cls : print "DOWN" : y% = y% - 10: gosub 500
80              IF pressed% = 97 then cls : print "LEFT" : x% = x% - 10: gosub 500
90              IF pressed% = 100 then cls : print "RIGHT" : x% = x% + 10: gosub 500
110     wend
500     circle (x%, y%), 20, 4
510     return
