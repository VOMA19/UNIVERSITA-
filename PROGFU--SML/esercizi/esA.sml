(*
Hai una lista di numeri [1, 2, 3, 4, 5]. Scrivi una dichiarazione 
val usando map e una funzione anonima (fn) per trasformare questa lista in 
una lista in cui ogni numero è stato moltiplicato per 10.
Risultato atteso: [10, 20, 30, 40, 50]
*)

val per10 = map(fn x => x*10) [1,2,3,4,5];