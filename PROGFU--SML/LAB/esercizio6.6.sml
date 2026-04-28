fun simpleMap (F,nil)=nil
    | simpleMap (F,x::xs)=F(x) :: simpleMap (F,xs);

val test = simpleMap ( (fn x => if x < 0.0 then 0.0 else x), [0.0, 1.0, ~2.1, ~2.3] );