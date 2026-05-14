datatype figura = 
    Cerchio of real 
  | Rettangolo of real * real;

fun calcolaArea (Cerchio r) = Math.pi * r * r
  | calcolaArea (Rettangolo (l, h)) = l * h;