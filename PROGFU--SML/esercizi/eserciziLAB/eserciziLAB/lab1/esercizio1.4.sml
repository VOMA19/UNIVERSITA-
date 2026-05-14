(* ==========================================================================
    ESERCIZIO 1.4
    Come possiamo correggere gli errori nelle seguenti espressioni?
    1. if 0 then 1 else 2;
    2. ord ("a")
========================================================================== *)

(* 1. ERRORE ORIGINALE: if 0 then 1 else 2;
    PROBLEMA: L'if richiede una condizione booleana, ma 0 è un int.
    SOLUZIONE: Sostituire 0 con un valore bool come true o false. *)
val test_if_bool = if true then 1 else 2;
print ("1. L'if corretto restituisce l'intero: " ^ Int.toString(test_if_bool) ^ "\n");

(* 2. ERRORE ORIGINALE: ord ("a");
    PROBLEMA: "a" è una stringa (string), ma ord richiede un carattere (char).
    SOLUZIONE: Usare la sintassi corretta per i caratteri con l'hash (#). *)
val test_ord = ord(#"a");
print ("2. Il codice ASCII di #" ^ "a" ^ " è: " ^ Int.toString(test_ord) ^ "\n");