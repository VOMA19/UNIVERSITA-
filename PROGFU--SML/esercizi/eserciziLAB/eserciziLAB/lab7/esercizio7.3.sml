fun andb_foldr L = foldr (fn (x, acc) => x andalso acc) true L;

fun andb_foldl L = foldl (fn (x, acc) => x andalso acc) true L;