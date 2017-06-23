#include <stdio.h>
#include <cs50.h>


int main()
{
    long long credit;           // credit card number
    long long len;              // used to work out len of card number
    int count = 0;              // count to work out credit card number
    long long ccmulti;          // credit card number used for addition sum
    int pen;                    // penultimate digit
    int multi = 0;              // sum of alternate digits, starting with penultimate
    long long ccadd;            // credit card number used for addition sum
    int end;                    // end digit
    int add = 0;                // added digits
    int checksum;               // combo of multi and add
    
    
    // get credit card number from user and validate it's a positive integer
    do
    {
        printf("Please enter the credit card number you wish to validate: ");
        credit = get_long_long();
    }
    while (credit <= 0);
    
    // validate length of credit card number and get length of card

    len = credit;
    while (len > 0)
    {
        len = len / 10;
        count ++;
    }
    
    // select and multiply alternate digits, beginning with pentultimate
    ccmulti = credit;
    
    ccmulti = ccmulti / 10;
    pen = ccmulti % 10;
    if (pen * 2 < 10)
    {
        multi = multi + (pen * 2);
    }
    else
    {
        multi = multi + ((pen * 2) % 10)+1;
    }
    for (int j = 0; j <= count; j++)
    {
        ccmulti = ccmulti / 100;
        pen = ccmulti % 10;
        if (pen * 2 < 10)
        {
            multi = multi + (pen * 2);
        }
        else
        {
            multi = multi + ((pen * 2) % 10)+1;
        }
    } 
    
    // select and add alternate digits, beginning with last one
    ccadd = credit;
    for (int i = 0; i <= count; i++)
    {
        end = ccadd % 10;
        ccadd = ccadd / 100;
        add = add + end;
    }

    // combine add and multi for checksum

    checksum = (multi + add) % 10;
    if (checksum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
     printf("%i\n", checksum); 
    }
    
    
    
    return 0;
}

