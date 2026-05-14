fun cycle [] = []
    | cycle (x::xs) = xs @ [x];