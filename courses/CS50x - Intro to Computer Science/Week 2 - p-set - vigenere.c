// get key from the command line
// check that all arguments are valid
// get plaintext input
// preserve letter case and keep numbers/punctuation
// encipher text, if alphabetical - skip if character is number, punctuation, symbol or space
// print cipher text
// return error to main if some of the requirements aren't met

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main (int argc, string argv[])
{
    if (argc != 2)
    {
        // print error message if command line input is wrong
        printf("Please enter two command line arguments\n");
        return 1;
    }
    else
    {
       // check that argv[1] is alphabetical
        for (int a = 0, b = strlen(argv[1]); a < b; a++)
        {
            if (!isalpha (argv[1][a]))
            {
                printf("Please enter an alphabetic key\n");
                return 1;
            }
        }
    }

    // get key from the array and find out its length
    string key = argv[1];
    int len = strlen(key);

    // get plaintext input from user
    printf("plaintext: ");
    string plain = get_string();

    // print initial "ciphertext" output
    printf("ciphertext: ");

    // iterate over string where i relates to the plaintext and j relates to the key
    for (int i = 0, j = 0, n = strlen(plain); i < n; i++)
    {
        // encode plaintext to encrypted text
        // retrieve letter of key to use
        int k = tolower(key[j % len]) - 'a';

        // what to do if character is upper case
        if (isupper (plain[i]))
        {
            printf("%c", (((plain[i] - 'A') + k) % 26) + 'A');
            j++;
        }

        // what to do if character is lower case
        else if (islower (plain[i]))
        {
            printf("%c", (((plain[i] - 'a') + k) % 26) + 'a');
            j++;
        }

        // what to do if character is neither
        else
        {
            printf("%c", plain[i]);
        }
    }

    // finish off with printed newline
    printf("\n");

}