datatype 'a btree =
    Empty |
    Node of 'a * 'a btree * 'a btree;

fun postOrder Empty = []
    | postOrder (Node (valore, sinistro, destro)) = 
        postOrder sinistro @ postOrder destro @ [valore];