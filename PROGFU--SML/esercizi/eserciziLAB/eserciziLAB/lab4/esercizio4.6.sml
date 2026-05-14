fun member (_, nil) = false
    | member (x, y::ys) = (x = y) orelse member(x, ys);