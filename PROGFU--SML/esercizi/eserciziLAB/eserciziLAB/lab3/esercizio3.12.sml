fun maxList([x:real]) = x
    | maxList(x::y::zs) = 
        if x < y then maxList(y::zs) 
        else maxList(x::zs);