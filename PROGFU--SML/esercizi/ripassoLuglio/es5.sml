fun sommali n [] = n
    | sommali n [v1] = n
    | sommali n [v1, v2] = n
    | sommali n (v1::v2::v3::xs) = v3 + sommali n xs;


val rec sommali = fn z => 
    fn [] => z 
        | v::[] => z 
        | v1::v2::[] => z 
        | v1::v2::v3::l => v3 + (sommali z l);
