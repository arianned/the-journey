# Week 1

## Scratch vs C

C is a lower-level traditional language. It's purely textual. In Scratch we have visual blocks but these can be relatively easily translated into text equivalents. For example, the `say "hello, world"` block would be shown in C as:

```
printf("hello, world\n");
```

The `\n` has the effect of moving the cursor to the next line - like hitting the Enter key.

Semicolons `;` just mean "end of thought".

## Loops

If we had wrapped the `say "hello, world"` block in a forever block so it kept looping and looping, it would look like this in C:

```
while (true)  
{  
    printf("hello, world\n");  
}
```

It's the `while (true)` which indirectly implies a forever loop - as `true` is always true.

If we wanted to repeat `say "hello, world"` 50 times, our code would look like this in C:

```
for (int i = 0; i < 50; i++)
{
    printf("hello, world\n");  
}
```

## Variables

If we wanted to set i to zero in Scratch, we'd use a `set i to 0` block. In C, we would say:

```
int i = 0;
```

Remember **Boolean Expressions8**? They're something that can be either true or false. In Scratch, we might ask whether `i < 50` to keep track of a score or something like that. In C?

```
i < 50
```

If we want to ask whether `x < y`, we can do that in C as long as we've already created those variables earlier on.

```
x < y
```

## Conditions

If something is true, do this, else if something else is true, do that. It's the programming equivalent of a fork in the road. Could be a two, three, four or more way fork.

If we had a Scratch block which said, `if x < y say, "x is less than y" or if x > y say "x is greater than y" or if neither of those are right (x=y) say "x i equal to y"` then this is potentially easier to represent in C:

```
if (x < y)
{
    printf("x is less than y\n");
}
else if (x > y)
{
    printf("x is greather than y\n");
}
else
{
    printf("x is equal to y\n");
}
```

## Arrays

Scratch allowed us to create lists of things, back to back. C doesn't have lists, but it does have **arrays**. It's a special type of variable that allows us to store data back, to back, to back.

In Scratch, if I wanted to get `item 1 of argv`,  I can just create a block for that. (Side note - Scratch usually starts counting from 1 for lists, not 0.) In C, this is simply:

```
argv [0]
```

Remember than in C, `0` will mean first.

## hello C

In the same way that Scratch has the green flag that you click to initial programmes, C has its own equivalent special function, called **main**.

```
#include <stdio.h>

int main (void)
{
    printf("hello, world\n");
}
```

## Compiling

However once we've written this, to make it work, we have to take it and translate it into machine code. Back to **binary**. To save us having to put it into binary ourselves, we can use pre-designed programmes called **compilers**. **"Compiling"** simply means converting from source code to machine code.

Like last week, where we talked about inputs and outputs, and using an algorithm (black box) to solve the problem, in this case we're going to use algorithms in the compiler to convert the special keywords like `main` and `printf` to machine code.

## The CS50 IDE

So how do we get a compiler? We can download one, or we can use the CS50 IDE which lives in the cloud. (cs50.io) It runs on Cloud9, with some features excluded, but with a CS50 library included to allow additional functionality.

On the left you'll have an area to access your files, on the top right you'll write your code and on the bottom right you'll have your terminal window.

The terminal, or CLI (command line interface) allows you to run commands like compile your code, to run your programs, or start your web server. 

Any files you create should be saved with the ".c" file extension.

In C, when you want to write a string, you use "double quotes". But if you want to use a single character (char) you use 'single quotes'.

C doesn't have the word "or", so you have to use two pipes (vertical lines) instead `||`

C doesn't have the word "and", so you have to use two ampersands instead `&&`

### Notes on the CS50 IDE

`clang` is what you type to run the compiler  
`a.out` is the default name for a program when you don't specify one (assembly output)  
`./` the dot indicates to run a program in the current directory  
`-o xxx` will output the code to a program called "xxx"  
`ls` lists the files in the current directory  
`rm` remove  
`make` is a program that comes with Linux and Cs50 IDE to create programs from your source code. It's a convenience that triggers a compiler etc.  
`cd` command directory - move forward and back, open up different folders etc  
`mkdir` make directory  
`rmdir` remove directory  
`get_string` ask user to input a string  
`get_int` ask user to input an integer  
`get_float` ask user to input a floating number (real/decimal number)  
`%s` acts as a placeholder for a string variable (insert in speechmarks but list variable after speechmarks)  
`%i` acts as a placeholder for an integer variable (insert in speechmarks but list variable after speechmarks)  
`%f` acts as a placeholder for an floating variable (insert in speechmarks but list variable after speechmarks)  
`bool` boolean Y or N operator  
`char` single character  
`double` uses 64 bits
`float`
`int`
`long long` uses 64 bits
`string`
`if`
`else`
`switch` is another way of doing `if else` - is use with `case`. You also need to include a `break` statement  
`for`
`while`
`do ... while`
`return`
