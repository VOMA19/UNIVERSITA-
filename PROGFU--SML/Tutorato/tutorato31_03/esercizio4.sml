(* Funzione is_zero *)
fun is_zero "zero" = 0       (* Se la stringa è esattamente "zero", restituisci 0 *)
  | is_zero _ = 1;           (* Per QUALSIASI altra stringa (_), restituisci 1 *)

(* Test della funzione *)
val valore = is_zero "ciao"; 

(* Stampa del risultato (nota l'aggiunta del segno '=' che mancava) *)
val _ = print("Il valore inserito ritorna: " ^ Int.toString valore ^ "\n");