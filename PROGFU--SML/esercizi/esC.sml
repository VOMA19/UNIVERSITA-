(*
Hai una lista di numeri: [1, 2, 3, 4, 5].
Voglio che tu scriva un'unica dichiarazione val che:

Prima filtri la lista tenendo solo i numeri dispari (un numero x è dispari se x mod 2 <> 0).

Poi mappi il risultato per raddoppiare i numeri rimasti.

Indizio: Puoi risolvere il problema in due modi. Puoi usare un let ... in ... end per salvare la lista filtrata e 
poi passarla a map, OPPURE puoi mettere il List.filter(...) [...] direttamente tra le parentesi tonde al posto della 
lista nel map!

Risultato atteso: [2, 6, 10].
*)

val dispari = map (fn x => x * 2) (List.filter (fn x => x mod 2 <> 0) [1, 2, 3, 4, 5]);

(* oppure *)

val dispari = 
    let 
        val solo_dispari = List.filter (fn x => x mod 2 <> 0) [1, 2, 3, 4, 5]
    in
        map (fn x => x * 2) solo_dispari
    end;