fun fact n =
    if n < 0 then 
        (print ("Negative argument " ^ Int.toString n ^ " found.\n"); 0)
    else if n = 0 then 1
    else n * fact (n - 1);