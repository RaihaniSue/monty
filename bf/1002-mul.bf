++++[>++++[>+++<-]<-]    Set cell(2) to 48 / 0x30 / '0'
,>,>                      Read two numbers into cell(0) and cell(1)
[<-<->>-]                 Decrement cell(0) and cell(1) by 48 / 0x30 / '0'
<<                        Move to cell(0)
[                         Multiplication loop
    >                     Move to cell(1)
    [>+>+<<-]             Move cell(1) to cell(2) and cell(3)
    >>                    Move to cell(3)
    [<<+>>-]              Move cell(3) back to cell(1)
    <<<-                  Decrement cell(0)
]
>[-]<                     Set cell(1) to 0 for counter (currently in cell 0)
++++[>++++[>+++<-]<-]    Add 48 / 0x30 / '0' to cell(2); cell 2 holds the result
>>.                       Print the result from cell 2
