(*
Esercizio 4 (Mappatura e Funzioni Anonime)
Hai una lista di stringhe che rappresentano nomi, ma purtroppo sono tutti scritti in minuscolo e vuoi aggiungere un "!" 
alla fine di ognuno per farli sembrare entusiasti.

Scrivi una dichiarazione val nomi_entusiasti = ... che usa la funzione map e una funzione anonima (fn)
per prendere la lista ["marco", "giulia", "luca"] e restituire ["marco!", "giulia!", "luca!"].

(Indizio: In SML, l'operatore per concatenare (unire) due stringhe è l'accento circonflesso ^.
Quindi per aggiungere "!" alla stringa x, scriverai x ^ "!").
*)

val nomi_entusiasti = map (fn x => x ^ "!") ["marco", "giulia", "luca"];