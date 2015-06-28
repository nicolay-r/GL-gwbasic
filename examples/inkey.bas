10 cls
15 times% = 10
20 print "Press any key ", times%, " times";
25 for i% = 0 to times%
30      key% = inkey$
35      while key% = 0
40            key% = inkey$
45      wend
50      print "You pressed: ", key% ;
60      print "Pressed iteration: " , i% ;
70 next i%
80 end
