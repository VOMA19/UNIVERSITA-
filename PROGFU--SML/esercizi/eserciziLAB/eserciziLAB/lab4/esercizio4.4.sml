(* Soluzione 4.4: flip di una lista di coppie *)
fun flip(nil) = nil
    | flip((a, b) :: xs) = 
        if a < b then (a, b) :: flip(xs) 
        else (b, a) :: flip(xs);
