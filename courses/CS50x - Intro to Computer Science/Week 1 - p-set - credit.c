#include <stdio.h>
#include <cs50.h>

int main (void)
{
    // prompt user to enter credit card number and validate that it's a positive number
    
    long long credit;               // credit card number
    do
    {
        printf("Please enter the credit card number you wish to validate: ");
        credit = get_long_long();
    }
    while (credit <= 0);
    
    // get length of credit card number
    
    long long cclen;                        // variation of the credit card number used to find the length
    int len = 0;                            // the length of the credit card number
    cclen = credit;
    while (cclen > 0)
    {
        cclen /=10;
        len ++;
    }
    
    // get starting digits of credit card number
    
    long long visa = credit;
    long long mc = credit;
    long long amex = credit;
    
    while (visa >= 10)
    {
        visa /= 10;
    }
    
    while (mc >= 100)
    {
        mc /= 10;
    }
    
    while (amex >= 100)
    {
        amex /= 10;
    }
    
    // multiply every other digit, starting with the penultimate - find penultimate digit and multiply it by 2 unless sum >10. If sum >=10, add the products together
    
    long long ccmulti = credit;             // variation of the credit card number, used to fetch alternate digits
    int pen;                                // penultimate digit - setting this up over next two rows
    ccmulti = ccmulti /10;                  
    pen = ccmulti % 10;
    int multi = 0;                           // sum of multiplied digits
    if (pen * 2 < 10)
    {
        multi = multi + (pen * 2);
    }
    else
    {
        multi = multi + (((pen * 2) % 10) + 1);
    }
    
    // now move back to every other digit, multiplying by 2 unless sum >10. If sum >10, add the products together
    
    for (int i = 0; i <= (len-1); i+= 2)
    {
        ccmulti /= 100;
        pen = ccmulti % 10;
        if (pen * 2 < 10)
        {
            multi = multi + (pen * 2);
        }
        else
        {
            multi = multi + (((pen * 2) % 10) + 1);
        }
    }
    
    // now select and add remaining digits (counting back from the final digit, two at a time)
    
    long long ccadd = credit;               // variation of the credit card number, used to fetch alternate digits
    int final;                              // final digit - setting this up over next two rows
    int add = 0;                            // sum of added digits
    for (int j = 0; j <= len; j+= 2)
    {
        final = ccadd % 10;
        add = add + final;
        ccadd /=100;
    }
    
    // now combine both sets of numbers to create a checksum
    
    int checksum = multi + add;
    
    // begin validation of credit card number
    
    // validate checksum
    
    if (checksum % 10 != 0)
    {
        printf("INVALID\n");
    }
    // if checksum = 0, check 
    else if ((visa == 4) && (len == 13 || len == 16))
    {
        printf("VISA\n");
    }
    else if ((amex == 34 || amex == 37) && (len == 15))
    {
        printf("AMEX\n");
    }
    else if ((mc == 51 || mc == 52 || mc == 53 || mc == 54 || mc == 55) && (len ==16))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}