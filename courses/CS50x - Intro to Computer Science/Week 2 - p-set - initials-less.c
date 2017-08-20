// need to prompt a user for their name using get_string
// print the user's intials in capital letters (use toupper function) with no spaces or full stops followed by a newline

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // ask user for input
    string name = get_string();
    
    // ensure that get_string returned a string
    if (name != NULL)
    {
        // print 1st character in name
        printf("%c", toupper(name[0]));
        
        // iterate over the characters in name one at a time
        for (int i = 0, n = strlen(name); i < n; i++)
        {
            
            //print initials after a single space
            if (name[i] == ' ')
            printf("%c", toupper(name[i+1]));
                
        }
        
        // print final space at the end of the initials
        printf("\n");
        
    }
}