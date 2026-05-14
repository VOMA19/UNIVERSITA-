(* Riutilizziamo la logica del massimo (simile a min3) *)
fun max3 (a,b,c) = Int.max(a, Int.max(b,c));
fun min3 (a,b,c) = Int.min(a, Int.min(b,c));

fun sort3 (a, b, c) =
    let
        val minimo = min3(a, b, c)
        val massimo = max3(a, b, c)
        (* Il mediano si trova togliendo min e max dalla somma totale *)
        val mediano = (a + b + c) - minimo - massimo
    in
        [minimo, mediano, massimo]
    end;