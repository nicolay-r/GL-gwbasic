10      cls
20      let x% = 320 : let y% = 240
40      while 1
50              pressed% = inkey$
60              IF pressed% = 119 then cls : y% = y% + 10
70              IF pressed% = 115 then cls : y% = y% - 10
80              IF pressed% = 97 then cls : x% = x% - 10
90              IF pressed% = 100 then cls : x% = x% + 10
100             circle (x%, y%), 20, 4
110     wend
