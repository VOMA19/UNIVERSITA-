(*Scrivere una funzione remove zeros che, data una lista di interi, restituisce la lista privata di tutte le
occorrenze del numero 0. Ad esempio duplicate [1,0,2,0,3] deve diventare [1,2,3]*)

fun remove_zeros [] = []
    | remove_zeros (0::xs) = remove_zeros xs
    | remove_zeros (x::xs) = x :: remove_zeros xs;  

val nuovaLista = remove_zeros([0,1,2,3,0,5]);

fun stampaListaInt [] = print "\n"
    |stampaListaInt (x::xs) = 
        let
            val _ = print(Int.toString x ^ " ")
        in 
            stampaListaInt xs
        end;

val _ = print "la nuova e': ";
val _ = stampaListaInt nuovaLista;
    

