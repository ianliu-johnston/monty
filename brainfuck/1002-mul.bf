[ The following is the program in one line.
NULL
End Comment ]

,                a0 add x  getchar()     Only reads the first character
>,               a1 add x  getchar()     Only reads the second character
>+++ ++++   	 a2 add 7                a2 set loop to 7
[                start loop
<<--- ----       a0 sub 7                a0 subtracts by 7 each time
>>-              a2 sub 1                a2 decrements by 1 until nothing left
]                end loop
<<+		 a0 add 1
>>+++ ++++   	 a2 add 7                a2 set loop to 7
[                start loop
<--- ----        a1 sub 7                a1 subtracts by 7 each time
>-               a2 sub 1                a2 decrements by 1 until nothing left
]                end loop
<+		 a1 add 1
<		 mv to a0
[                start outer loop
>
[		 start inner loop
>+		 a2 add 1
>+		 a3 add 1
<<-	         a1 sub 1		decrement a1 until nothing left
]                end inner loop
>>		 mov a3
[		 start inner loop	move a3 to a1
<<+		 a1 add 1
>>-		 a3 sub 1
]		 end inner loop
<<<-		 a0 sub 1
]		 end outer loop
>>>++++ ++++     a3 add 8                a3 set loop to 8
[                start loop
<+++ +++         a2 add 6                a2 add 6 each each time
>-               a3 sub 1                a3 decrements by 1 until nothing left
]                end loop
<.               a2  Print