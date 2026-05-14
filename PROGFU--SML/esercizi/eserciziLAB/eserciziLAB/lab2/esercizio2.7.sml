(* ==========================================================================
    LABORATORIO 2 - ESERCIZIO 2.7
    Scrivi una funzione 'del3' che elimini il terzo elemento da una lista.
    Esempio: del3 [1, 2, 3, 4] = [1, 2, 4]
   ========================================================================== *)

fun del3 (x::y::_::xs) = x::y::xs  (* Caso con almeno 3 elementi: salto il terzo *)
  | del3 L = L;                    (* Caso con 0, 1 o 2 elementi: restituisco la lista così com'è *)

(* --- TEST --- *)
val test_del3 = del3 [10, 20, 30, 40, 50];
(* Risultato atteso: [10, 20, 40, 50] *)