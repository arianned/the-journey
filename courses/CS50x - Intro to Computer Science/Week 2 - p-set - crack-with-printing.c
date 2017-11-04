// don't use make, use:     clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wshadow crack.c -lcrypt -lcs50 -lm -o crack

// this version prints out every line as it tries to crack passwords, so it takes a LOT longer to run

#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (int argc, string argv[])
{
    if (argc != 2)
    {
        // print error message if command line input is wrong
        printf("Please enter the programme name and the hashed password you wish to crack\n");
        return 1;
    }
    else
    {
        // get hashed password from the command line
        string hashed = argv[1];

        // create array to store brute force attempt
        char password[5] = {'\0','\0','\0','\0','\0'};
        char salt[2];

        // create array to store all of the letters we need to check
        char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};

        // copy salt from the first 2 characters of the hashed password
        strncpy(salt,argv[1],2);

        // start by checking single character password
        for (int i = 0, n = strlen(alphabet); i < n; i++)
        {
            password[0] = alphabet[i];

            // compare the encryped password to the hash
            string encrypted = crypt (password, salt);
            if (strcmp(encrypted, hashed) == 0)
            {
                // if they match, print out the password and return 0 to main
                printf("%s\n", password);
                return 0;
            }

            // print out the combinations that it tried
            else
            {
                printf("%s\n", password);
            }
        }

        // check two character passwords
        // first character
        for (int i = 0, n = strlen(alphabet); i < n; i++)
        {
            password[0] = alphabet[i];

            // second character
            for (int j = 0; j < n; j++)
            {
                password[1] = alphabet[j];

                // compare the encryped password to the hash
                string encrypted = crypt (password, salt);
                if (strcmp(encrypted, hashed) == 0)
                {
                    // if they match, print out the password and return 0 to main
                    printf("%s\n", password);
                    return 0;
                }

                // print out the combinations that it tried
                else
                {
                    printf("%s\n", password);
                }
            }
        }

        // check three character passwords
        // first character
        for (int i = 0, n = strlen(alphabet); i < n; i++)
        {
            password[0] = alphabet[i];

            // second character
            for (int j = 0; j < n; j++)
            {
                password[1] = alphabet[j];

                // third character
                for (int k = 0; k < n; k++)
                {
                    password[2] = alphabet[k];

                    // compare the encryped password to the hash
                    string encrypted = crypt (password, salt);
                    if (strcmp(encrypted, hashed) == 0)
                    {
                        // if they match, print out the password and return 0 to main
                        printf("%s\n", password);
                        return 0;
                    }

                    // print out the combinations that it tried
                    else
                    {
                        printf("%s\n", password);
                    }
                }
            }
        }

        // check four character passwords
        // first character
        for (int i = 0, n = strlen(alphabet); i < n; i++)
        {
            password[0] = alphabet[i];

            // second character
            for (int j = 0; j < n; j++)
            {
                password[1] = alphabet[j];

                // third character
                for (int k = 0; k < n; k++)
                {
                    password[2] = alphabet[k];

                    // fourth character
                    for (int l = 0; l < n; l++)
                    {
                        password[3] = alphabet[l];

                        // compare the encryped password to the hash
                        string encrypted = crypt (password, salt);
                        if (strcmp(encrypted, hashed) == 0)
                        {
                            // if they match, print out the password and return 0 to main
                            printf("%s\n", password);
                            return 0;
                        }

                        // print out the combinations that it tried
                        else
                        {
                            printf("%s\n", password);
                        }
                    }
                }
            }
        }
    }
}