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

100

⌊⊸ₙ₁₀
# ⊡:Ones-1

# ⊸<20
# ⨬(+⊓(⊡:Tens-2)⋅0⊃÷◿10 # gap0 is F
# | ⊡:Teens-10)

# +⍥(+And)±, ∩⋅0⊃÷◿100
