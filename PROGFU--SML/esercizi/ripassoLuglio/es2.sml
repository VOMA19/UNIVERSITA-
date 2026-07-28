datatype Expr = X
                | Y
                | Avg of Expr * Expr
                | Mul of Expr * Expr;

fun compute X x y = x
    | compute Y x y = y
    | compute (Avg(e1, e2)) x y = ((compute e1 x y) + (compute e2 x y)) div 2
    | compute (Mul(e1, e2)) x y = (compute e1 x y) * (compute e2 x y);

val rec compute = fn X => (fn x => fn y => x) 
    | Y => (fn x => fn y => y) 
    | Avg(e1, e2) => (fn x => fn y => ((compute e1 x y) + (compute e2 x y)) div 2) 
    | Mul(e1, e2) => (fn x => fn y => (compute e1 x y) * (compute e2 x y));
