fun delete (a, []) = []
    | delete (b, c::ys) = 
        if b = c then ys 
        else c :: delete(b, ys); 