fun countInternalNodes p Empty = 0
    |countInternalNodes p (Node(v, Empty, Empty)) = 0 (* Foglia: non contare *)
    | countInternalNodes p (Node(v, left, right)) =
        let 
            val count = if p(v) then 1 else 0
        in
            count + countInternalNodes p left + countInternalNodes p right
        end;