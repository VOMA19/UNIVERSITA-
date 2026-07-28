fun sommali n [] = n
    | sommali n [x] = n
    | sommali n (x::y::xs) = y + sommali n xs;

fun sommali n [] = n
    | sommali n [x] = n
    | sommali n [x, y] = n   
    | sommali n (x::y::z::xs) = z + sommali n xs;

val unione = fn i1 => fn i2 => (fn n => (contiene i1 n) orelse (contiene i2 n));

fun elementi_pari [] = nil
    |elementi_pari [x] = []
    |elementi_pari (x::y::xs) = y::elementi_pari(xs);

exception shortList of int;

fun thirdElement1 [] = raise shortList(0)
    | thirdElement1 [x] = raise shortList(1)
    | thirdElement1 [x,y] = raise shortList(2)
    | thirdElement1 (x::y::z::xs) = z;


fun sum_list [] = 0
    | sum_list (nil::ys) = sum_list (ys)
    | sum_list ((x::xs)::ys) = x + sum_list (xs::ys);


datatype Expr = X 
                | Y 
                | Avg of Expr * Expr 
                | Mul of Expr * Expr;

fun compute X x y = x
    | compute Y x y = y
    | compute (Avg(e1, e2)) x y = ((compute e1 x y) + (compute e2 x y)) div 2
    | compute (Mul(e1, e2)) x y = (compute e1 x y) * (compute e2 x y);

datatype espressione = costante of int
                        | variabile of string
                        | somma of espressione * espressione
                        | prodotto of espressione * espressione;

fun eval env (costante n) = n
    | eval env (variabile s) = cerca s env
    | eval env (somma (e1, e2)) = (eval env e1) + (eval env e2)
    | eval env (prodotto (e1, e2)) = (eval env e1) * (eval env e2)


datatype lambda_expr = Var of string 
                     | Lambda of string * lambda_expr 
                     | Apply of lambda_expr * lambda_expr;

fun is_free s (Var v) = (s = v)
    | is_free s (Lambda(v, e1)) = if s = v then false else is_free s e1
    | is_free s (Apply(e1, e2)) = (is_free s e1) orelse (is_free s e2);


datatype 'a btree = Empty | Node of 'a * 'a btree * 'a btree;

fun all_satisfy lt Empty = true
    | all_satisfy lt (Node(valore, sx, dx)) = 
        (lt valore) andalso (all_satisfy lt sx) andalso (all_satisfy lt dx);


datatype codice = rosso of string | giallo of string | verde of string;

fun arriva [] nuovoP = [nuovoP]
    | arriva ((rosso nome)::xs) nuovoP = (rosso nome) :: arriva xs nuovoP
    
    | arriva ((giallo nome)::xs) (rosso nomeNuovo) = (rosso nomeNuovo) :: (giallo nome) :: xs
    | arriva ((giallo nome)::xs) nuovoP = (giallo nome) :: arriva xs nuovoP
    
    | arriva ((verde nome)::xs) (verde nomeNuovo) = (verde nome) :: arriva xs (verde nomeNuovo)
    | arriva ((verde nome)::xs) nuovoP = nuovoP :: (verde nome) :: xs;


fun sum_listL [] = (0,0)
    |sum_listL [x] = (x,0)
    |sum_listL (x::y::xs)=
    let
        val (summOdd, sumEven) = sum_listL xs
    in
        (x+summOdd, y+ sumEven)
    end;


datatype Expr = X 
                | Y 
                | Avg of Expr * Expr 
                | Mul of Expr * Expr;

fun compute X x y = x
    | compute Y x y = y
    | compute (Avg(e1, e2)) x y = ((compute e1 x y) + (compute e2 x y)) div 2
    | compute (Mul(e1, e2)) x y = (compute e1 x y) * (compute e2 x y);


fun sommali n [] = n
    | sommali n [x] = n
    | sommali n (_::y::ys) = y + sommali n ys;

fun hist [] (c:real, d:real) = 0
    | hist (x::xs) (c:real, d:real) = 
        let 
            val som = hist xs (c,d)
        in 
            if x > (c - d) andalso x < (c + d) 
            then 1 + som
            else som
        end;

datatype 'a T = Lf | Br of 'a * 'a T * 'a T

fun depth Lf = 0
    | depth (Br(value, sx, dx)) = 
        let
            val left = depth sx
            val right = depth dx
        in
            if left > right then left + 1 
            else right + 1
        end;

datatype 'a rbtree = Empty 
                   | Red of 'a * 'a rbtree * 'a rbtree
                   | Black of 'a * 'a rbtree * 'a rbtree;

fun isRootBlack Empty = true
    | isRootBlack (Red(_, _, _)) = false
    | isRootBlack (Black(_, _, _)) = true;

fun noRedChildren Empty = true
    | noRedChildren (Red(_, Red(_,_,_), _)) = false
    | noRedChildren (Red(_, _, Red(_,_,_))) = false
    | noRedChildren (Red(_, sx, dx)) = noRedChildren sx andalso noRedChildren dx
    | noRedChildren (Black(_, sx, dx)) = noRedChildren sx andalso noRedChildren dx;
