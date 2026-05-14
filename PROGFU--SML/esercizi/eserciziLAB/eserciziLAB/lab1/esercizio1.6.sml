(* ==========================================================================
    ESERCIZIO 1.6
    Fornire esempi di dati che corrispondono ai seguenti tipi complessi.
   ========================================================================== *)

(* 1. Tipo: int list list list *)
val test_lista3D : int list list list = [[[1,2],[3]], [[4,5,6]]];

(* 2. Tipo: (int * char) list *)
val test_listaTuple : (int * char) list = [(1, #"a"), (2, #"b"), (3, #"c")];

(* 3. Tipo: string list * (int * (real * string)) * int *)
val test_tuplaGigante : string list * (int * (real * string)) * int = 
    (["ciao", "mondo"], (5, (3.14, "test")), 10);