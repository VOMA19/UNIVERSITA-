datatype 'a btree =
    Empty |
    Node of 'a * 'a btree * 'a btree;

fun inOrder Empty = []
    | inOrder (Node (valore, sinistro, destro)) = inOrder sinistro @ [valore] @ inOrder destro;