// get key from the command line
// turn key from a string to an int
// get plaintext input
// preserve letter case and keep numbers/punctuation
// encipher text, if alphabetical
// print cipher text
// return error to main if some of the requirements aren't met

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// declare encode function
char encode(char a, int i);

int main (int argc, string argv[])
{
    // check that argc = 2 - return an error if not
    if (argc == 2)
    {
        // get k from the array and turn it into an int
        string key = argv[1];
        int k = atoi (key);

        // get plaintext input from user
        printf("plaintext: ");
        string p = get_string();

        // print initial "ciphertext" output
        printf("ciphertext: ");

        // iterate over string
        for (int i = 0, n = strlen(p); i < n; i++)
        {
            //encode plaintext to encrypted text
            char e = encode(p[i], k);
            printf("%c", e);
        }

        // finish off with printed newline
        printf("\n");
    }

    else
    {
        // print error message if command line input is wrong
        printf("Please try again\n");
        return 1;
    }

}

char encode(char a, int i)
{
    // check if character is alphabetical
    if (isalpha (a))
    {

        // what to do if the character is upper case
        if (isupper (a))
        {
            char c = ((((a - 65) + i) % 26) + 65);
            return c;
        }

        // what to do if the character isn't upper case (is lower case)
        else
        {
            char c = ((((a - 97) + i) % 26) + 97);
            return c;
        }

    }

    // if not alphabetical, return the character as is
    else
    {
        return a;
    }

}