(* Per far funzionare cyclei, ci serve prima la funzione che sposta un elemento *)
fun cycle L = tl(L) @ [hd(L)];

(* Esercizio 3.2: versione con if-then-else *)
fun cyclei (n, L) =
    if n = 0 then L
    else cyclei (n - 1, cycle L);