fun duplicatep (nil) = nil
    | duplicatep (x::xs) = x :: x :: duplicatep(xs);