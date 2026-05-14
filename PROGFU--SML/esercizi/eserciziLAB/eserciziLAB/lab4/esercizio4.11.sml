(* Funzione di supporto: (a-b)*(a-c)*... *)
fun prodDiff1(a, nil) = 1.0 
  | prodDiff1(a, b::bs) = (a - b) * prodDiff1(a, bs); 

(* Funzione principale *)
fun prodDiff(nil) = 1.0 
  | prodDiff(x::xs) = prodDiff1(x, xs) * prodDiff(xs); 