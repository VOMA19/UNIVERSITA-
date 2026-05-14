(* QUESTO E' SBAGLIATO *)
val is_one = fn x =>
    case x of
        _ => "anything else"
    | 1 => "one";