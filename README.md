# Brainf**k Interpreter (C)

This is a simple Brainf**k interpreter written in C.

## Features
This interpreter supports the following Brainf**k commands:

* \+ : Increment the value at the current memory cell.
* \- : Decrement the value at the current memory cell.
* . : Output the value at the current memory cell as an ASCII character.
* , : Read a single ASCII character from the user and store it in the current memory cell.
* < : Move the data pointer to the left (decrement).
* \> : Move the data pointer to the right (increment).
* [ : If the value at the current memory cell is zero, jump to the corresponding ] command.
* ] : If the value at the current memory cell is nonzero, jump to the corresponding [ command.

## Compilation
clone this repo and run 

```bash
gcc -Wall brainf\*\*k.c -o bf
```
this will generate an executable named bf. 

## Usage 
run a brainf**k file by passing it as an arument for bf executable
```bash
./bf test.bf
```
## Limitations
This interpreter has the following limitations:

* It only supports Brainf**k code with a maximum of 30,000 memory cells.
* It does not support multi-byte characters or Unicode.
* It does not support input or output redirection.
## License
This interpreter is licensed under the [MIT License](LICENSE). Feel free to use, modify, and distribute it as you see fit.
