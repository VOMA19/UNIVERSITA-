fun fact(1) = 1
  | fact(n) = n * fact(n-1); 

fun fact(n) =
    if n=1 then 1
    else n * fact (n-1);