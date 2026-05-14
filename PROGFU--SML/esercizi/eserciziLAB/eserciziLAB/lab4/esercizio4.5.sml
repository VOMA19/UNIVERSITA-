fun vowel(#"a"::ys) = true
    | vowel(#"e"::ys) = true
    | vowel(#"i"::ys) = true
    | vowel(#"o"::ys) = true
    | vowel(#"u"::ys) = true
    | vowel(_)        = false; (* Gestisce consonanti e lista vuota *)