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

## Shorts

### Command Line

These commands will work on any UNIX-based system, including Linux and MacOS.

- `ls` - list - give you a readout of all files and folders in the current directory  
- `cd` - change directory - navigate between directories. The current directory is always "." and the name of the directory one level above where we are is always ".." . If you're not sure of the same of your current directory, you can type:  
- `pwd` which stands for present working directory  
- `Ctrl + L` - clears the screen  
- `mkdir` - make directory - create a new folder  
- `cp` - copy - you need to specify a source (what you want to copy) and also the destination. e.g. `cp <source> <destination>`. If you want to copy a whole directory and the stuff that's in it, you need a slightly different command:  
- `cp -r` - copy recursive - use this when you want to copy an entire directory. <source><destination> fields work the same  
- `rm` - remove - `rm <file>`. If you want to avoid being asked "are you sure", alter as follows:  
- `rm -f` - remove force - removes without the "are you sure" option. NO UNDO!  
- `rm -r` - remove recursive - use this to remove a directory. Can also combine with force, e.g. `rm -rf <directory>`  
- `mv` - move - similar to rename. Work like, `mv <source> <destination>`

Other commands which it's useful to learn for later on in CS50:

- `chmod`
- `rmdir`
- `sudo`
- `ln`
- `man`
- `clear`
- `touch`
- `diff`
- `telnet`

### Data Types

C is the only language where you have to specify the data type of every variable.

- `int` - integers. Ints always take up 4 bytes of memory - 32 bits. The range of values they can store is limited to 32 bits worth of information. Negative and positive integers each get half of the range (roughly negative 2 billion to positive 2 billion). 
- `unsigned int` - unsigned integer. They're qualifiers. Modify the data type of integer. You can unsign other data types. Doubles the range of positive integers you can take on at the expense of being able to use negative ones. Limit of zero to around 4 billion.
- `short`, `long`, `const` - other qualifers that we may not come on to during CS50.
- `chars` - used for variables that will store single characters. Characters take up 1 byte of memory - 8 bits. Can only store 8 bits of information. This takes us from -128 to 0 to 127. 0-127 are used to map ASCII values.
- `float` - floating point numbers - _real_ numbers, such as those which include decimals. Always take up 4 bytes of memory - 32 bits. Due to the nature of `float`, it's hard to set a range for the numbers precisely.
- `double` - double precision floating point numbers. They will take up 8 bytes - 64 bits. You can be much more precise. If you have numbers into the decimals and you need precision, use `double`. 
- `void` - this is a type but NOT a data type. Functions can have a `void` return type, which means that they **don't return a value**. The parameter list of a function can also be void - which means the function takes no parameters. `void` = placeholder for **nothing**. 

The next data types are included within the CS50 library - be sure to add `#include <cs50.h>` if you want to use them

- `bool` - boolean values - for storing TRUE or FALSE
- `string` - words, sentences. Strings of characters. 

Later in CS50 we'll encounter things like:
- `structs` - structures
- `typedefs` - defined types

If you want to create a variable, you need to do 2 things:

1. Give it a type
2. Give it a name

Slap a semicolon on the end and you're good to go. Examples:

```
int number;
char letter;
```

If you want to create multiples of the same type, you specify the type _once_ and then list as many variables of that type as you want. Examples:

```
int height, width;
float sqrt2, sqrt3, pi;
```

It's good practice to only declare variables when you need them.

How do we use them? 

Once you've declared a variable, it's no longer necessary to specify it's type. (If you do, it can have some unintended consequences!)

```
int number;                 // declaration
number = 17;                // assignment
char = letter;              // declaration
letter = 'H';               // assignment
```

If you want to declare and set the value of a variable in a single step, you can do this. Known as **initializing**.

```
int number = 17;            // initializing
char letter = 'H';          // initializing
```

### Operators

- **+** - plus
- **-** - minus
- **x** - multiply
- **/** - divide
- **%** - modulus operator - gives us the remainder when the number on the left of the operator is divided by the right, e.g.
```
int m = 13 % 4;             // m is now 1
```

With assignment in C, the value on the right gets assigned to the value on the left.

C also gives you a shorthand way to apply an arithmetic operator to a single variable, e.g.

```
x = x * 5;
x *= 5;
```

This trick works with all five basic arithmetic operators. C also gives a shorthand for incrementing or decrementing a variable by 1:

```
x++;
X--;
```

#### Boolean Expressions

These are used in C to compare values.

All Boolean expressions in C evaluate to either `true` or `false`.

We can use the result of evaluating a Boolean expression in other programming constructs such as deciding which branch in a _conditional_ to take or whether a _loop_ should run.

In C, every non-zero value is equivalent to `true` and zero is `false`. 

There are two main type of Boolean expressions:

1. Logical operators
    1. Logical AND (&&) is true if and only if both operands are true, otherwise false, e.g. `x && y`
    2. Logical OR (||) is true if and only if at least one operand is true, otherwise false, e.g. `x || y`
    3. Logical NOT (!) inverts the value of its operand
2. Relational operators - these behave as you'd expect and appear syntactically similar to regular maths
    1. Less than `(x < y)`
    2. Less than or equal to `(x <=y)`
    3. Greater than `(x > y)`
    4. Greater than or equal to `(x >= y)`
    5. Equality `(x == y)`
    6. Inequality `(x != y)`

### Conditional Statements

C provides a few ways to implement conditional expressions (also known as **branches**).

#### if (and if-else and if-else if-...-else)

```
if (boolean-expression)
{
    
}
```

If the `boolean-expression` evaluates to `true`, all lines of code between the curly braces will execute in order from top-to-bottom.

If the `boolean-expression` evaluates to `false`, those lines of code will not execute.

Take this one step further with **if-else**. 

```
if (boolean-expression)
{

}
else
{

}
```

If the `boolean-expression` evaluates to `true`, all lines of code between the first set of curly braces will execute in order from top-to-bottom.

If the `boolean-expression` evaluates to `false`, all lines of code between the second set of curly braces will execute in order from top-to-bottom.

In C you can also create an **if-else** chain with multiple **if-else** strung together.

```
if (boolean-expr1)
{
            // first branch
}
else if (boolean-expr2)
{
            // second branch
}
else if (boolean-expr3)
{
            // third branch
}
else
{
            // fourth branch
}
```

All of the above branches are mutually exclusive.

It's also possible and sometimes useful, to create a chain of non-mutually exclusive branches. In the below example only the third an fourth branches are mutually exclusive. The `else` binds to the nearest `if` only.

```
if (boolean-expr1)
{
            // first branch
}
if (boolean-expr2)
{
            // second branch
}
if (boolean-expr3)
{
            // third branch
}
else
{
            // fourth branch
}
```

#### Switch Statement

It's a conditional statement that allows you to specify distinct cases. It doesn't rely on Boolean expressions.

```
int x = GetInt();
switch (x)
{
    case 1:
        printf("One!\n");
        break;
    case 2:
        printf("Two!\n");
        break;
    case 3:
        printf("Three!\n");
        break;
    default:
        printf("Sorry!\n");
}
```
It's important to `break;` between each case or you will "fall through" each case (unless you want that to happen).

What about if we omit the `break`?

```
int x = GetInt();
switch (x)
{
    case 5:
        printf("Five, ");
    case 4:
        printf("Four, ");
    case 3:
        printf("Three, ");
    case 2:
        printf("Two!\n");
    case 1:
        printf("One, ");
    default:
        printf("Blast-off!\n");
}
```

In this case, rather than print a number and then stop, this acts as a count-down, based on the number selected. It could go from 5 to blast-off, or it could go 1, blast-off.

#### Ternary Operators (?:)

The following snippets of code act identically:

```
int x;
if (boolean-expr)
{
    x = 5;
}
else
{
    x = 6;
}
```

```
int x = (boolean-expr) ? 5 : 6;
```

The ternary operator is mostly a cute trick but is useful for writing trivially short conditional branches. Great for quick and simple. Don't use if you've got 6 lines of code between each set.

The value after the `?` is what x's value will be if the expression is `true`.

The value after the `:` is what x's value will be if the expression is `false`.

### Loops

