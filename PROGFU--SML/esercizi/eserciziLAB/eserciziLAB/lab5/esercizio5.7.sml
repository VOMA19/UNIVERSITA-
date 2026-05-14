fun doubleExp(x:real, 0) = x              (* Caso base: x^(2^0) = x^1 = x *) 
    | doubleExp(x, i) = 
        let 
            val y = doubleExp(x, i-1)         (* Calcolo x^(2^(i-1)) una sola volta *) 
        in
            y * y                             (* Elevo al quadrato il risultato precedente *) 
        end;