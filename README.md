#Holberton School - 0x18-stacks_queues_lifo_fifo

## Setup 
####Monty interpreter
This command will be used to compile the monty interpreter:
``gcc -Wall -Werror -Wextra -pedantic *.c -o monty``
Please use gcc-4.8

####Brainfuck programs
To Install the brainfuck interpreter:
``sudo apt-get install bf``

## Usage
####Monty interpreter
The Monty language is a very simple one. Monty relies on a unique stack of integers.  
Usage is : `./monty FILE` where `FILE` contains lines of commands.  
Lines are of the type `opcode [argument]`.  
Current opcodes are:  
1. `push` push onto stack. This opcode is the only one requiring an argument.  
2. `pall` print all stack.  
3. `pop` pop the value at the top of the stack.  
4. `pint` peek the top of the stack.
5. `pchar` peek, turning the value into an ascii character if possible.  
6. `add` pop the 2 elements at the top, push the addition on the stack.  
7. `sub` pop the 2 elements at the top, push the subtraction on the stack.  
8. `mul` pop the 2 elements at the top, push the multiplication on the stack.  
9. `div` pop the 2 elements at the top, push the division on the stack.  
10. `mod` pop the 2 elements at the top, push the modulo on the stack. 
11. `swap` swap the top 2 elements of the stack.  
12. `rotl` move the top element to the bottom of the stack.  
13. `rotr` move the element at the bottom of the stack to the top.  
14. `pstr` print the whole stack as a string if possible.  
15. `queue` change the functionment of the stack to one of a queue. Enqueue to the bottom of the stack and dequeue from the top.  
16. `stack` is the reverse of queue.  
17. `nop` does not do anything
<br>
The Monty language allows for any space before or after the opcode and its argument. Any text after the argument is disregarded.  
Any line starting with a `#` is considered a comment.  
Currently the stack is implemented as a doubly linked list.

####Brainfuck program
in the brainfuck folder: `bf FILE`.  

## Description of Files
<h6>monty.h</h6>
header file for the project, contains the structs used throughout.  

<h6>main.c</h6>
Entry point of the interpreter. Feeds a line at a time to `execute`

<h6>execute.c</h6>
Dispatch the line received from main to the function behind the opcode.

<h6>push_and_pop.c</h6>
Contains `push` and `pop` opcodes

<h6>calculations.c</h6>
contains `add`, `sub`, `mul`, `div` and `mod` opcodes.  

<h6>print_functions.c</h6>
Contains `pint`, `pall`, `pchar` and `pstr` opcodes.

<h6>nopandqueue.c</h6>
Contains `nop`, `stack` and `queue` opcodes.

<h6>move_elements_functions.c</h6>
Contains `swap`, `rotr` and `rotr` opcodes.

<h6>basic_linked_list_functions.c</h6>
The stack is implemented as a doubly linked list. This file contains the functions needed to add elements, remove elements and free a doubly linked list.  

<h6>helpers.c</h6>
This file contains helper functions to deal with a string.

<h6>getline.c</h6>
Our implementation of getline to read a line from a file.

<h5>brainfuck/</h5>
The brainfuck folder contains:
<h6>1000-holberton.bf</h6>
Print `Holberton` in bf.  

<h6>1000-add.bf</h6>
Add 2 single digit numbers whose result is less than 10 in bf.  

<h6>1000-mul.bf</h6>
Multiply 2 single digits numbers whose result is less than 10 in bf.

## Bugs
Who doesn't ?

## Links
[Brainfuck](https://en.wikipedia.org/wiki/Brainfuck)

## Authors
* **Ian Liu-Johnston** [Personal Website:](http://ianxaunliu-johnston.com) || [Twitter](https://twitter.com/Concativerse) || [LinkedIn](https://www.linkedin.com/in/ian-liu-johnston-32a40a115)
* **Anne Cognet** [Personal Website:] || [Twitter](https://twitter.com/1million40) || [Github](https://github.com/anne75) || [LinkedIn](https://www.linkedin.com/in/cognetanne)
