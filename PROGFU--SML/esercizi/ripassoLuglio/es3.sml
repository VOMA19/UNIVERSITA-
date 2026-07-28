datatype 'a btree = Empty
                  | Node of 'a * 'a btree * 'a btree;

fun countInternalNodes p Empty = 0
    | countInternalNodes p (Node(x, Empty, Empty)) = 0
    | countInternalNodes p (Node(x, left, right)) =
        let
            val current = if p x then 1 else 0
        in
            current + countInternalNodes p left + countInternalNodes p right
        end;