(* ==========================================================================
    LABORATORIO 2 - ESERCIZIO 2.5
    Scrivi una funzione 'min3tuple' che accetti una tupla (int * int * int)
    e ne restituisca il minimo.
    Esempio: min3tuple (10, 5, 8) = 5
========================================================================== *)

(* Nota: la firma della funzione sarà int * int * int -> int *)
fun min3tuple (a, b, c) = Int.min(a, Int.min(b, c));

(* Test *)
val res_tuple = min3tuple (10, 5, 8);
print ("Il minimo della tupla e': " ^ Int.toString(res_tuple) ^ "\n");