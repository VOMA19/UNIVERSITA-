fun makelist 0 = "X" 
    | makelist n = makelist(n-1) ^ makelist(n-1); 

fun printXs n = print(makelist n); 