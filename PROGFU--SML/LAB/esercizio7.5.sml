datatype 'a btree =
    Empty |
    Node of 'a * 'a btree * 'a btree;

(*forma generale*)

fun esplora Empty = ... (* Cosa faccio se l'albero è vuoto? *)
    | esplora (Node (valore, sinistro, destro)) = ... (* Cosa faccio se ho un nodo? *)

(*es 7.5*)

fun postOrder Empty = []
    | postOrder (Node (valore, sinistro, destro)) = 
        postOrder sinistro @ postOrder destro @ [valore];