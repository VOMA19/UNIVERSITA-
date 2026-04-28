fun filter (P,nil)=nil
    | filter (P,x::xs)=
        if P(x) then x :: filter(P,xs)
        else filter (P,xs);

val test2 = filter ( (fn x => x > 0.0), [1.1, ~1.2, ~1.3, 1.4] );