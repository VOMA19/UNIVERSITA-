(* ==========================================================================
    ESERCIZIO 1.5
    Correggi le seguenti espressioni:
    1. explode ["bar"];
    2. implode ( #"a", #"b");
    3. ["r"]::["a","t"];
   ========================================================================== *)

(* 1. ERRORE ORIGINALE: explode ["bar"];
    PROBLEMA: explode vuole una string (es. "bar"), non una string list (es. ["bar"]).
    SOLUZIONE: Rimuovere le parentesi quadre. *)
val test_explode = explode "bar";
(* test_explode varrà: [#"b", #"a", #"r"] *)


(* 2. ERRORE ORIGINALE: implode ( #"a", #"b");
    PROBLEMA: implode vuole una char list (es. [#"a"]), non una tupla (es. (#"a")).
    SOLUZIONE: Sostituire le tonde con le quadre. *)
val test_implode = implode [#"a", #"b"];
print ("2. Implode corretto: " ^ test_implode ^ "\n");


(* 3. ERRORE ORIGINALE: ["r"]::["a","t"];
    PROBLEMA: :: attacca un ELEMENTO a una LISTA. ["r"] è una lista, non un elemento.
    SOLUZIONE: Rimuovere le quadre attorno a "r". *)
val test_cons = "r" :: ["a", "t"];
(* test_cons varrà: ["r", "a", "t"] *)