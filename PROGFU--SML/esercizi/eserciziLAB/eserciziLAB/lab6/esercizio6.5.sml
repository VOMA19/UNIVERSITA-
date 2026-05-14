fun tabulate (a, delta, n, F) =
    if n = 0 then ()
    else (
        print (Real.toString a ^ " " ^ Real.toString (F a) ^ "\n");
        tabulate (a + delta, delta, n - 1, F)
    );