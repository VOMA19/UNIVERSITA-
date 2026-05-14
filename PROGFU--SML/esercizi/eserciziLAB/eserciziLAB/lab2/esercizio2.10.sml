(* ==========================================================================
    LABORATORIO 2 - ESERCIZIO L2.10
    Scrivi una funzione 'rem' che rimuova il secondo elemento di una lista.
    Esempio: rem [1, 2, 3, 4] = [1, 3, 4]
========================================================================== *)

fun rem (x::_::xs) = x::xs  (* Caso specifico: lista con almeno 2 elementi *)
  | rem L = L;              (* Caso generale: se ha 0 o 1 elemento, la lascia intatta *)

(* --- TEST --- *)
val test_rem1 = rem [1, 2, 3, 4]; (* Risultato: [1, 3, 4] *)
val test_rem2 = rem [1, 2];       (* Risultato: [1] *)