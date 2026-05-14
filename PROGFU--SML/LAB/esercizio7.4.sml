fun implode_foldl L = foldl (fn (x, acc) => acc ^ str x) "" L;

fun implode_foldr L = foldr (fn (x, acc) => str x ^ acc) "" L;