Ones ← ≡◇⧻ {"one"
            "two"
            "three"
            "four"
            "five"
            "six"
            "seven"
            "eight"
            "nine"}
Teens ← ≡◇⧻{"ten"
            "eleven"
            "tvelve"
            "thirteen"
            "fourteen"
            "fifteen"
            "sixteen"
            "seventeen"
            "eighteen"
            "nineteen"}
Tens ← ≡◇⧻ {"twenty"
            "thirty"
            "forty"
            "fifty"
            "sixty"
            "seventy"
            "eighty"
            "ninety"}
Hundred ← ⧻ "hundred"
And     ← ⧻ "and"

F ← |1 ⨬0(
  ⌊⊸ₙ₁₀
  ⨬(⊡:Ones-1
  | ⊸<20
    ⨬(+⊓(⊡:Tens-2)F⊃÷◿10
    | ⊡:Teens-10)
  | +⍥(+And)±,∩F⊃÷◿100
  )
)⊸±

⍜-₁⇡1000
≡F

# +⧻"onethousand"
