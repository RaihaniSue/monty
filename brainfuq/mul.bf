++++[>++++[>+++<-]<-]    # Stores 48 ('0' in ASCII) in cell(2)
,>,>                     # Reads two numbers into cell(0) and cell(1)
[<-<->>-]                # Converts input numbers to integer values (subtract '0')
<<                       # Move to cell(0)
[                        # Multiplication loop
    >                    # Move to cell(1)
    [>+>+<<-]            # Copy cell(1) to cell(2) and cell(3)
    >>                   # Move to cell(3)
    [<<+>>-]             # Move cell(3) back to cell(1)
    <<<-                 # Decrement cell(0)
]
>[-]<                    # Reset cell(1) to 0 (used as counter, currently in cell(0))
++++[>++++[>+++<-]<-]    # Adds 48 ('0' in ASCII) to cell(2), result is in cell(2)
>>.                      # Print the result (go to cell(2) and print)
