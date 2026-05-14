fun len(L) =
    if L = nil then 0
    else 1 + len(tl(L));

fun len [] = 0
    |len (x::xs) = 1 + len(xs);