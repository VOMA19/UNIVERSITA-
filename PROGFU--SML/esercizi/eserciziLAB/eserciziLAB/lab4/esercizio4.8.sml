fun insert(x, nil) = [x]
    | insert(x, S as y::ys) = 
        if x = y then S 
        else y :: insert(x, ys);