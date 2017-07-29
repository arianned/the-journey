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

