fun printHello 0 = ()
    | printHello n = (print "ciao\n"; printHello (n - 1));

printHello 10;