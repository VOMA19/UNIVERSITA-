exception EmptyList;
fun reduce (F, nil) = raise EmptyList
    | reduce (F, [a]) = a
    | reduce (F, x::xs) = F (x, reduce(F, xs));

val test3 = reduce((fn (a,b) => if a>b then a else b ), [1,4]);