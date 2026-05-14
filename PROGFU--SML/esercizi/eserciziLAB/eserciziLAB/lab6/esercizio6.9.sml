fun readAndSum (filename) =
    let
        val is = TextIO.openIn filename
        fun helper (acc) =
            case TextIO.inputLine is of
                NONE => (TextIO.closeIn is; acc)
                | SOME line => 
                case Int.fromString line of
                    SOME n => helper (acc + n)
                    | NONE => helper (acc)
    in
        helper (0)
    end;