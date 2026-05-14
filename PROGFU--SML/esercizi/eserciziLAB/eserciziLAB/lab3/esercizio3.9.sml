fun cycle1 (nil) = nil             (* Se la lista è vuota, resta vuota *) 
  | cycle1 (x::xs) = xs @ [x];     (* Prendi la testa x e mettila in fondo alla coda xs *) 

fun cycleip (L, 0) = L
    | cycleip (L, i) = cycleip (cycle1(L), i - 1);