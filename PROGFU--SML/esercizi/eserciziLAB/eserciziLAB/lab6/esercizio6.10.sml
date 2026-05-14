fun applyList nil v = nil
    | applyList (f::fs) v = f(v) :: applyList fs v;