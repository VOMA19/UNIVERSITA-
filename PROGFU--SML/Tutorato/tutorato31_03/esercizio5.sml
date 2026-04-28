(*Scrivere una funzione alt sum che prende in input una lista di interi e ne calcola la somma a segni alterni
utilizzando il pattern matching.
Ad esempio:
alt sum [1,2,3,4] = 1 - 2 + 3 - 4 = -2
alt sum [10,5,2] = 10 - 5 + 2 = 7*)

fun alt_sum [] = 0
    |alt_sum (x::y::xs) = x-y + alt_sum(xs)
    |alt_sum (x::xs) = x;

val valore = alt_sum [4,1,5,2] ; 

val _ = print("Il valore inserito ritorna: " ^ Int.toString valore ^ "\n");