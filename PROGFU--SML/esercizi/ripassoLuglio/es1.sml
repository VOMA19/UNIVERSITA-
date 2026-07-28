fun elementi_pari [] = nil
    | elementi_pari [x] = nil
    | elementi_pari (x::y::xs) = y :: elementi_pari xs;
