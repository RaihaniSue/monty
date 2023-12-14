Read from stdin
>, >, <<   # Reading two integers into cells

Convert to integer
+++++ +     # Setting up divisor for ASCII to integer conversion
[
 >----- --- # Converting first input to integer (subtracting '0')
 >----- ---
 <<-
]

Multiply two integers
>[
 >[>+>+<<-] # Multiplication algorithm: result in cells 1 and 2
 >[<+>-]    # Moving the multiplied result to cell 1
 <<-
]

Separate two digits inputted
>[-]>+> >+++++ +++++<  # Separating input digits by 10

[
 - >- [>>>]+++++ +++++<<+  # Calculating the tens place digit
 [<<<]>>>>
]
<-
<+++++ +++++>>>[-<<<->>>]<<<  # Reconstructing the separated digits

Convert to ASCII
<+++++ +   # Setting up for ASCII conversion
[
 >+++++ +++>  # Converting result to ASCII character
 [+++++ +++>]
 <[<]>-   # Cleaning up
]

Print with newline
>>[.<<]<[<<]>>.  # Printing the result with newline
>>,.
