(* ==========================================================================
    ESERCIZIO 1.3
    Come possiamo correggere gli errori nelle seguenti espressioni?
    1. ceil(4);
    2. if true then 5+6 else 7.0;
   ========================================================================== *)

(* 1. ERRORE ORIGINALE: ceil(4); 
    PROBLEMA: ceil accetta solo numeri reali (real), ma 4 è un intero (int).
    SOLUZIONE: Fornire un numero reale aggiungendo il .0 *)
val test_ceil1 = ceil(4.0);
val test_ceil2 = ceil(4.5);
print ("1. ceil(4.0) restituisce l'intero: " ^ Int.toString(test_ceil1) ^ "\n");
print ("   ceil(4.5) restituisce l'intero: " ^ Int.toString(test_ceil2) ^ "\n");


(* 2. ERRORE ORIGINALE: if true then 5+6 else 7.0;
    PROBLEMA: Il ramo 'then' calcola un int (11), il ramo 'else' un real (7.0).
            Devono essere identici!
   SOLUZIONE: Cambiare 7.0 in 7 (oppure 5+6 in 5.0+6.0). *)
val test_if = if true then 5+6 else 7;
print ("2. Risultato dell'if corretto: " ^ Int.toString(test_if) ^ "\n");