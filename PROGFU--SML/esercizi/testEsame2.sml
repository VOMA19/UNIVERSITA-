datatype ctree = Empty | Leaf of char | Node of char * ctree * ctree

fun get_words Empty = ("", "")
    | get_words (Leaf car) = 
        (str car, "")
    | get_words (Node (car, sx, dx)) = 
        let
            val (foglie_sx, nodi_sx) = get_words sx
            val (foglie_dx, nodi_dx) = get_words dx
        in
            (foglie_sx ^ foglie_dx, str car ^ nodi_sx ^ nodi_dx)
        end;