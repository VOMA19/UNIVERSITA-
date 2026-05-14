fun insertAll(a, nil) = nil
    | insertAll(a, L::Ls) = (a::L) :: insertAll(a, Ls);