# Week 2

In Week 1 we translated some topics from Scratch and translated them into content that works in the world of C. That said, a lot of the fundamental building blocks were the same.

This time we'll take a look at **arrays**, which Scratch calls "lists".

## Debugging

Before we do that, let's talk about debugging.

### help50

If I'm attempting to run some code and I get an error message, within the CS50 IDE, I can use a command called `help50`, which has been written by the CS50 team. I can pass my code into this, to get help.

### eprintf

Within the CS50 library is a function called `eprintf`, which can be used to print some diagnostic information in the console. For example, if you're running a `for` loop and want to see what the value of `i` is, you can run this code:

```
#include <cs50.h>
#include <stdio.h>

int main (void)
{
    for (int i = 0; i <= 10; i++>)
    {
        printf("#\n");
        eprintf("i is now %i\n", i);
    }
}
```

This code, alongside printing out a "#" per line, will also give me the value of `i`, so I will be able to work out why I have 11 lines, not 10.

(Solution - starting to count at zero will mean there's 11 values. Either you set `i` at 1, or you only run `i` until it's less than or equal to 9, or less than 10.)

### debug50

A debugger is something that lets you run your program step by step, line by line, poking around looking at variables at a slower speed, so I can interact with it and hopefully work out what's going on.

I need to specify the line I want to start looking at my code from, my clicking as appropriate in the gutter next to my line numbers.

## Cryptography

- plain text - the input message
- cypher text - the scrambled output - the encrypted text
- key - something used by the encoding algorithm to perform the encryption

In C, we need to be able to take strings and examine/change individual characters, or letters within that string.

For example, if we want to be able to break out the individual letters in a string, we could do this as follows:

```
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
    string s = get_string();
    for (int i = 0; i < strlen(s); i++);
    {
        printf("%c\n", s[i]);
    }
}
```

This code allows us to print the "i-th" value of our string. It'll print an individual character (`"%c\n"`), and the square brackets allow us to index the value we want to use.

The above code is potentially buggy. `get_string` can return a value called `NULL`, if the input is too long, or in some way impossible for the computer to understand. Whenever we use `get_string`, we should use it within an `if` statement that ensures it only gets used when `s` does not equal `NULL`. For example:

```
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
    string s = get_string();
    if (s != NULL)
    {
        for (int i = 0; i < strlen(s); i++);
        {
            printf("%c\n", s[i]);
        }
    }
}
```

While the above code should now never crash, it's inefficient. Why? Because every time the `for` loop runs, the computer is counting the length of the string - every single time. More efficient code would establish the length of the string up front, and then tell the loop to check `i` against that value - rather than counting again. For example:

```
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
    string s = get_string();
    if (s != NULL)
    {
        for (int i = 0, n = strlen(s); i < n; i++);
        {
            printf("%c\n", s[i]);
        }
    }
}
```

So now our code is well-designed - it's efficent. But how are we doing for style? We haven't commented any of our code, so it's impossible to know what's meant to be happening. We could comment our code as follows:

```
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
    // ask user for input
    string s = get_string();
    
    // make sure get_string returned a string
    if (s != NULL)
    {
        // iterate over the characters in s one at a time
        for (int i = 0, n = strlen(s); i < n; i++);
        {
            // print i-th character in s
            printf("%c\n", s[i]);
        }
    }
}
```

## Typecasting

This allows you to convert, either implicity or explicity, data from one type to another.

For example, turning upper case to lower case, or vice versa.

In the below example, we'll get the computer to return the ASCII value for each capital letter of the alphabet (where 65 represents "A"):

```
#include <stdio.h>

int main (void)
{
    for (int i = 65; i < 65 + 26; i++)
    {
        printf("%c is %i\n", (char) i, i);
    }
}
```

This **explicitly** tells the computer to treat `i` as a character. You can **implicitly** do this by passing `i` as both placeholders - as `printf` will be able to discern that you want it to treat `i` like a `char`.

```
#include <stdio.h>

int main (void)
{
    for (int i = 65; i < 65 + 26; i++)
    {
        printf("%c is %i\n", i, i);
    }
}
```

You can also flip this round the other way:

```
#include <stdio.h>

int main (void)
{
    for (char c = 'A'; c <= 'Z'; c++)
    {
        printf("%c is %i\n", c, (int) c);
    }
}
```

Because all of the ASCII value from 'A' through to 'Z' are contiguous, we can use the mathematical operators in the above code.

If we want to do this implicitly, we can do this and let the computer figure it out:


```
#include <stdio.h>

int main (void)
{
    for (char c = 'A'; c <= 'Z'; c++)
    {
        printf("%c is %i\n", c, c);
    }
}
```

Taking this back to cryptography for a second.

- A = 65
- a = 97

- B = 66
- b = 98

There's a gap of 32 between all of the upper case characters and their lower case equivalents. With this in mind, we can create code that allows us to amend characters from their original case.

```
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (void)
{
    string s = get_string();
    if (s != NULL)
    {
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            if (s[i]>= 'a' && s[i] <= 'z')
            {
                // you can include 'a' - 32, but 'a' - 'A' saves needing to remember
                printf("%c", s[i] - ('a' - 'A'));
            }
            else
            {
                printf("%c", s[i]);
            }
        }
        printf("\n");
    }
}
```

We can make this code even better, by introducing functions that can make some of the changes for us.

We need a new library for this though.


```
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main (void)
{
    string s = get_string();
    if (s != NULL)
    {
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            if (s[i]>= 'a' && s[i] <= 'z')
            {
                printf("%c", toupper(s[i]));
            }
            else
            {
                printf("%c", s[i]);
            }
        }
        printf("\n");
    }
}
```

If you want to find out more about a function that you're using, you can use the `man` command - which stands for manual. So `man toupper` would return the manual for the `toupper` function.

The use of `toupper` means we don't need a huge chunk of the code we've written. It can all be condensed into a single `printf`.

```
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main (void)
{
    string s = get_string();
    if (s != NULL)
    {
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            printf("%c", toupper(s[i]));
        }
        printf("\n");
    }
}
```

Computers use `\0` to mark the difference between different strings stored in their memory. Strings are **nul terminated** when this happens. (Notice "nul" NOT "NULL", which means something different.) It puts eight zero bits there, to act as this demarcation.

Using this idea, we can create a formula that recreates the functionality of `strlen`, but without having to use that function or an additional library.

```
#include <stdio.h>
#include <cs50.h>

int main (void)
{
    string s = get_string();
    int n = 0;
    while (s[n] != '\0')
    {
        n++;
    }
    printf("%i\n", n);
}
```

## Command-Line Arguments

In all the code we've run so far, we've expressed `int main (void)`, declaring that `main` itself doesn't take any arguments. Any input that `main` is going to get has to come from some other mechanism, like `get_int`, or `get_float` or `get_string`. However you can specify that the program will take inputs from the human at the command line. These command-line arguments are additional words that we specify at the terminal prompt.

So far, we haven't taken input from the user when running our programs but we can do that by re-declaring `main` moving forward, not as having `(void)`, but instead as having these:
```
int main (int argc, string argv[])
```
These two arguments call an integer and the second calls an **array**, similar to "lists" in Scratch.

It's an array of strings.

```
#include <stdio.h>
#include <cs50.h>

int main (int argc, string argv[])
{
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("hello world\n");
    }
}
```
Running the above code with the command `./argv0` (where `argv0` is the name given to the program), will just return the output of
```
hello world
```

Why?

When we run a program at the command line we're filling in the **argument vector**. The computer hands over to the program all the words we typed in at the prompt, in case we want to do something with the information.

Running the program with the command `./argv0 Zamyla` would return:
```
hello Zamyla
```
As long as I provide 2 words at the prompt, it will continue to work (2 words including the program name).

An array is just a chunk of contiguous memory, whose elements are back to back, and generally the same type.

Whereas before, we were looking at the characters in a string, we can now look at the strings in an array - one level above, conceptually.

Here's some code and what it would return:

```
#include <stdio.h>
#include <cs50.h>

int main (int argc, string argv[])
{
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
}
```

This code is designed to return the i-th string in the array. If a user types in:
```
./argv0 foo bar buzz
```
the returned result will be:
```
./argv0
foo
bar
buzz
```

**Remember** - `argv` is just an array of strings. A string, is just an array of characters. This means we could select a string and then a character within that string.

For example:

```
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (int argc, string argv[])
{
    // iterate over strings in argv
    for (int i = 0; i < argc; i++)
    {
        // iterative over characters in current string
        for (int j = 0, n = strlen(argv[i]); j < n; j++)
        {
            // print j-th character in i-th string
            printf("%c\n", argv[i][j]);
        }
    }
}
```

This code returns, if you run the command `./argv0`:
```
.
/
a
r
g
v
0
```

## Error Code

We've been talking about `main`'s input - what about `main`'s output?

When we've been typing in `int main (void)`, it still returns an output - it just does so secretly. It returns an integer. If everything works well and there's no issues, it returns a vaue of `0`. If something goes wrong, it'll return some non-zero value, which can ac as a clue to the programmer on exactly what went wrong.

I can write a program that will **only** work if the user provides me with an input of exactly two arguments. 

```
#include <stdio.h>
#include <cs50.h>

int main (int argc, string argv[])
{
    if (argc != 2)
    {
        printf("missing command-line argument\n");
        return 1;
    }
    printf("hello, %s\n", argv[1]);
    return 0;
}
```

If we didn't specify `return 0` it would be assumed and output for us, but in the interests of clarity, it's worth doing here.

If you want to see what error message a program exited with, after the program quits, you should type in the following at the prompt:
```
echo $?
```
And this will show you the value that was returned.

## Shorts

### Functions

So far, everything we've written has been inside of `main`. This is fine when we're writing relatively few lines of code, but when there's thousands or tens of thousands of lines of code, it's not a good idea to keep everything inside of `main`.

C and nearly all other languages, allow us to write **functions**, sometimes also known as **procedures**, **methods** or **subroutines**.

#### What is a function?

A function is a black box with a set of 0+ inputs and 1 output.

Why call it a black box? If we aren't writing the functions ourselves, we don't need to know the underlying implementation.

When you create a function, make sure you use a clear, relatively obvious name and that it's well docmented.

Why use functions?

1. Organisation - functions help us break up a complicated problem into more manageable subparts
2. Simplification - smaller components tend to be easier to design, implement and debug
3. Reusability - functions can be recyled - you only need to write them once but can use them as often as you need

#### Function Declarations

- The first step to creating a function is to declare it. This gives the compiler a heads-up that a user-written function appears in the code.
- Function declarations should always go atop your code, before you begin writing `main()`
- There is a standard form that every declaration follows:
```
return-type name(argument-list);
```
- The `return-type` is what kind of variable the function will output
- The `name` is what you want to call your function
- The `argument-list` is the comma-separated set of inputs to your function, each of which has a type and a name

For example:
```
int add_two_ints(int a, int b);
```
- This is a function to add two integers
- The output of adding two integers will be an integer as well
- Considering it's function, it's been given an appropriate name
- There are two inputs to this function and we need to give a name to each of them for the purposes of the function. There's nothing important about these inputs (as far as we know), so it's fine to give them simple names

Here's another example:
```
float multiply_floats(float x, float y);
```
- This is a function to multiply two floating point numbers
- The product of two floating point numbers would also be a float

#### Function Definitions

Now we've declared our function, we have to write it.

A function definition looks very similar to a function declaration, except with a small change.

```
// function declaration - note the semicolon
float mult_two_reals(float x, float y);

// function definition
float mult_two_reals(float x, float y)
{
    float product = x * y;
    return product;
}
```

Here's a slightly simpler version of the above:

```
// function declaration - note the semicolon
float mult_two_reals(float x, float y);

// function definition (this one is slightly simpler than the one above)
float mult_two_reals(float x, float y)
{
    return x * y;
}
```
- `return` is the output of the black box - in this case the product of our sum

Here's how we would define one of the other functions we declared a moment ago:

```
int add_two_ints(int a, int b);

int add_two_ints(int a, int b)
{
    int sum = a + b;
    return sum;
}

```

#### Function Calls

Now to use our functions!

To call a function, pass it appropriate arguments and assign its return value to something of the correct type.

Here's an example of how we would call a function:

```
// includes
#include <stdio.h>
#include <cs50.h>

// declare functions
int add_two_ints(int a, int b);

int main(void)
{
    // ask user for input
    printf("Give me an integer: ");
    int x = get_int();
    printf("Give me another integer ");
    int y = get_int();

    // add the two numbers together via a function call
    int z = add_two_ints(x,y);

    // output the results
    printf("The sum of %i and %i is %i!\n", x, y, z);
}


int add_two_ints(int a, int b)
{
    int sum = a + b;
    return sum;
}
```

#### Function Miscellany

- Recall that functions can sometimes take no inputs. In that case we declare the function as having a `void` argument list
- Recall that functions sometimes do not have an output - in which case we declare the function as having a `void` return type

#### Practice Problem

- Declare and write a function called `valid_triangle` that takes three real numbers representing the lengths of three sides of a triangle as its arguments, and outputs either `true` or `false` depending on whether those three lengths are capable of making a triangle
- Note the following about triangles:
    - A triangle may only have sides with positive length
    - The sum of the lengths of any two sides of the triangle must be greater than the length of the third side

```
//include
#include <stdio.h>
#include <cs50.h>

// declare function
string valid_triangle(float a, float b, float c);

int main(void)
{
    // ask the user for input
    printf("Give me a number: ");
    float a = get_float();
    printf("Give me another number: ");
    float b = get_float();
    printf("Give me a final number: ");
    float c = get_float();

    // check whether the numbers can be make a valid triangle via a function call
    string s = valid_triangle(a, b, c);

    // output the result
    printf("Can the numbers make a triangle? %s\n", s);
}

// define function
string valid_triangle(float a, float b, float c)
{
    // check for all positive sides
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return "false";
    }

    // check that the sum of two sides is greater than the third
    if ((a + b <= c) || (a + c <= b) || (b + c <= a))
    {
        return "false";
    }
    
    // if both test are passed, we can confirm it's true!
    return "true";
 }
```

### Variables & Scope

As we start working with functions, something which is really important to understand is the concept of **variable scope**. 

**Scope** is the characteristic of a variable that defines from which functions that variable may be accessed.
- Local variables can only be accessed within the functions in which they are created
- Global variables can be accessed by any function in the program

You must be careful when working with global variables. They're flexible and allow you to pass information around so that every function can use it. However, this can also be dangerous as one function can change the value of a variable before you expect it to be changed.

#### Why Does This Distinction Matter?

- In general, _local_ variables in C are **passed by value** in function calls
- When a variable is **passed by value**, the _callee_ receives a copy of the passed variable, not the variable itself
- That means the variable in the _caller_ is left unchanged unless overwritten

For example in the below code, `foo` is not changed at all:
```
int main(void)
{
    int foo = 4;
    triple(foo);
}
int triple(int x)
{
    return x *= 3;
}
```

However in this example, `foo` does get overwritten:
```
int main(void)
{
    int foo = 4;
    foo = triple(foo);
}
int triple(int x)
{
    return x *= 3;
}
```
If we asked `main` to print out the value of `foo`, it would now be 12. However in the first piece of code it would remain as 4.

Variable scope can be an issue if the same variable name appears in multiple functions. This is generally ok if the variables exist in different scopes. 

For example, in the below code, what would be printed out at the end of this program?
```
int increment(int x);

int main(void)
{
    int x = 1;
    int y;
    y = increment(x);
    printf("x is %i, y is %i\n", x, y);
}

int increment(int x)
{
    x++;
    return x;
}
```
`x is 1, y is 2`

The reason this is confusing is that we have 2 variables called `x`. But each was local to its own function.

### Arrays

What if we want to work with lots of different variables, but we don't want loads of different names flying around the code?

This is where **arrays** come in handy. We use arrays to hold values of the same data type at contiguous memory locations - think of it like a load of PO boxes at a post office.

In C, the elements of an array are indexed starting from 0, not 1. If an array consists of `n` elements, the first element is located at index `0`. The last element is located at index `(n-1)`.

C won't tell you if you've gone out of bounds for your array. If you have 50 elements and you try and access `-3` or `59`, it won't prevent you from trying to do so.

#### Array Declarations

What does an array declaration look like?
```
type name[size]
```
- The type is what kind of variable each element of the array will be
- The name is what you want to call the array
- The size is how many elements you would like your array to contain

If you think of arrays in the same way as you do any other variable if the same data-type, all of the familiar operations make sense. All of the below operations would work:

```
// declared my array
bool truthtable[10];

// operation 1
truthtable[2] = false;

// operation 2
if (truthtable[7] == true)
{
    printf("TRUE\n");
}

// operation 3
truthtable[9] = true;
```

When declaring and initialising an array simultaneously, there is a special syntax that you can use to fill up the array with its starting values.

```
// instantition syntax
bool truthtable[3] = { false, true, true };

// individual element syntax
bool truthtable[3];
truthtable[0] = false;
truthtable[1] = true;
truthtable[2] = true;
```

You can also iterate over all of the elements in an array by using a loop. How do you create an array of 100 integers where every element of the array is its index? We'd want to put 0 in the first element, 1 in the second and so on.

```
```

You can tweak the instantiation syntax to not specify an array size. The compiler would automatically know to create 3 elements if you specified 3 elements after the equals sign. If you'd put 4, it would create 4:

```
// instantition syntax
bool truthtable[] = { false, true, true, false };
```

#### Array Dimensions

Arrays can also consist of more than a single dimension. You can have as many size specifiers as you wish:
```
bool battleship[10][10];
```
You can think of this as a 10x10 grid of cells. In the memory, it's just one 100-element one-dimensional array. Multi-dimensional arrays like this are great **abstractions** to help visualise game boards or other complex representations.

#### Copying Arrays

- We can treat individual elements of arrays as variables, but we cannot treat entire arrays themselves as variables
- For example, we cannot assign one array to another using the assignment operator in C
- Instead, we would need to use a loop to copy over the elements one at a time

```
// code which won't work
int foo[5] = { 1, 2, 3, 4, 5 };
int bar[5];

bar = foo;

// code which would work
for (int j = 0; j < 5; j++)
{
    bar[j] = foo[j];
}
```

#### Passed by Reference

Most variable in C are **passed by value** in function calls - meaning that the function, the _callee_ gets a copy of the variable to work with - not the variable itself. 

Arrays don't follow this rule. They are **passed by reference** - which means the _callee_ receives the **actual** array, not a copy of it. 

We'll return later to why arrays have this special property.

A final bit of code:
```
void set_array(int array[4]);
void set_int(int x);

int main(void)
{
    int a = 10;
    int b[4] = { 0, 1, 2, 3 };
    set_int = a;
    set_array(b);
    printf("%d %d\n", a b[0]);
}

void set_array(int array[4])
{
    array[0] = 22
}

void set_int(int x)
{
    x = 22;
}
```
- `set_array` takes an array of 4 integers as its input
- `set_int` takes a single integer as its input
- Neither function has an output
- We specify the single integer and array values (10 and 0, 1, 2, 3)
- We then have a call to `set_int` and `set_array`
- The answer is `10, 22`, as `set_int` received a copy of 10, and so `a` remained unchanged, but `set_array` received the actual array - so value `[0]` changed from `0` to `22`

### Command-Line Arguments

So far, all of our arguments have started with:

```
int main(void)
{

}
```

We've been collecting all of our data through in-program prompts. However if we want the user to provide data to the program before it starts running, we need to do things differently.

To collect command-line arguments from the user, change the declaration of `main` to look like this:

```
int main(int argc, string argv[])
{

}
```

We are passing in two parameters - one, an integer called `argc` and the other is an array of strings called `argv`. These two arguments enable you to know what data the user provided at the command line and how much data was provided. (You can give them different names, but it's traditional to use `argument count` and `argument vector`.) (`Vector` is just another word for an `array`.)

Something to remember is that if you're asking the array to store a number, e.g. `1024`, it will be stored as a **string**, not an **integer** - so you wouldn't be able to perform mathematical operations on it. There is however, a function to convert strings to integers which we'll learn later.

### Magic Numbers

Directly writing constants into our code is sometimes referred to as using **magic numbers**.

It's usually viewed as a bad habit to write constants into your code. Generally we want to try and avoid this. 

For example:
```
card deal_cards(deck name)
{
    for (int i = 0; i < 52; i++)
    {
        // deal the card
    }
}
```
We have a magic number here - the 52 which can cause issues later on if we're combining this function with other files later on.

One way to solve this would be to explicitly call out the deck size as 52:
```
card deal_cards(deck name)
{
    int deck_size = 52;
    for (int i = 0; i < deck_size; i++)
    {
        // deal the card
    }
}
```
This fixes one problem but introduces another. Even if globally prepared, some other function could manipulate `deck_size` - which could be problematic.

#### Preprocessor Directive

C provides a **preprocessor directive** (also known as a **macro**) for creating symbolic constants. 
```
#define NAME REPLACEMENT
```
- At the time your program is compiled, `#define` goes through your code and replacement `NAME` with `REPLACEMENT`. 
    - If `#include` is similar to copy/paste, then `#define` is analogus to find/replace
- For example, if I wanted to define `pi` rather than use `3.14159265` in my code, I can do that as follows:
```
#define PI 3.14159265
```

The substitution isn't limited to numbers. You can use it for other things:
```
#define COURSE "CS50"
```

- Convention says to define your constants in CAPS. It helps make it clearer that it's a constant

This particular soution is better than either of the previous ones for the `deal_cards` problem, and we use constants to do this.

```
#define DECKSIZE 52

card deal_cards(deck name)
{
    for (int i = 0; i < DECKSIZE; i++)
    {
        // deal the card
    }
}
```

