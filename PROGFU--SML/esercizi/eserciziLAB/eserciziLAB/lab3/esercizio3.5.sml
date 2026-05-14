fun pow(x:real, i:int) =
    if i = 0 then 1.0
    else x * pow(x, i - 1);