(*
Scrivi una funzione solo_positivi che, data una lista di numeri reali (real list), 
usi List.filter e una funzione anonima (fn) per restituire solo i numeri strettamente maggiori di 0.0.
*)
fun solo_positivi lista = 
    List.filter (fn x => x > 0.0) lista;

(* --- TEST --- *)
val test_positivi = solo_positivi [1.1, ~1.2, ~1.3, 1.4];
(* Risultato: [1.1, 1.4] *)

(*oppure con il currying*)

val solo_positivi_curried = List.filter (fn x => x > 0.0);