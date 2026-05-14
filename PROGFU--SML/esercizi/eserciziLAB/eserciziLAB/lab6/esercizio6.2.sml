fun getList (filename) =
    let
        val is = TextIO.openIn filename
        val contenuto = TextIO.inputAll is
        val _ = TextIO.closeIn is (* Chiudiamo lo stream *)
    in
        (* String.tokens divide la stringa ogni volta che trova uno spazio o un a capo *)
        String.tokens Char.isSpace contenuto
    end;