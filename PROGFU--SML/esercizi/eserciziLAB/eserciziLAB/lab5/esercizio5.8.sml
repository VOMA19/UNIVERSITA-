    
fun sumList (nil) = (0, 0)
    | sumList ([x]) = (x, 0)
    | sumList (x::y::zs) =
        let
            val (sumOdd, sumEven) = sumList (zs)
        in
            (x + sumOdd, y + sumEven)
        end;