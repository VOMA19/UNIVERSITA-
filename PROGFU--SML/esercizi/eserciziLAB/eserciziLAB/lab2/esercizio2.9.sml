(* ==========================================================================
    LABORATORIO 2 - ESERCIZIO 2.9
    Scrivi una funzione 'square_list' che prenda una lista di reali 
    e restituisca la lista dei loro quadrati.
    Esempio: square_list [1.0, 2.0, 3.0] = [1.0, 4.0, 9.0]
========================================================================== *)

(* Utilizziamo map: una funzione di ordine superiore che applica 
   una trasformazione a ogni elemento di una lista. *)

fun square_list L = map (fn x => x * x) L;

(* --- TEST --- *)
val test_squares = square_list [1.0, 2.5, 4.0];
(* Risultato: [1.0, 6.25, 16.0] *)

fun square_listManual [] = []
  | square_list (x::xs) = (x * x) :: square_list xs;