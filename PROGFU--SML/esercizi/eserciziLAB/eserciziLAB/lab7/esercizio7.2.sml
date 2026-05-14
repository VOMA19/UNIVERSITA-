fun toReal_map L = map (fn x => Real.fromInt x) L;

fun toReal_foldr L = foldr (fn (x, acc) => Real.fromInt x :: acc) [] L;

fun toReal_foldl L = rev (foldl (fn (x, acc) => Real.fromInt x :: acc) [] L);