(*
Scrivi una funzione lunghezze_parole che prenda una 
lista di stringhe e usi map per restituire una lista di interi contenente la lunghezza di ciascuna stringa.
*)

fun lunghezza_parole lista =
    map String.size lista;

(* --- TEST --- *)
val test_lunghezze = lunghezza_parole ["ciao", "a", "tutti"];
(* Risultato: [4, 1, 5] *)