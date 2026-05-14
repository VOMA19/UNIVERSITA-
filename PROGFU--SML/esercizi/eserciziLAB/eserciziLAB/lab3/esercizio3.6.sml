fun maxList(L: string list) =
    if tl(L) = nil then hd(L)  (* Se c'è solo un elemento, restituiscilo *)
    else
        if hd(L) > hd(tl(L)) then 
            maxList(hd(L) :: tl(tl(L))) (* Se il 1° > 2°, tieni il 1° e prosegui *)
        else 
            maxList(tl(L));             (* Altrimenti prosegui dal 2° *)