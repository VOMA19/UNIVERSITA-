map (fn x => if x < 0.0 then 0.0 else x) L;

foldr (fn (x,y) => x andalso y) true L;