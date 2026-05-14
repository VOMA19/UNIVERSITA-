fun flip ([]) = []
    | flip ([x]) = [x]
    | flip (x::y::zs) = y::x::flip(zs);