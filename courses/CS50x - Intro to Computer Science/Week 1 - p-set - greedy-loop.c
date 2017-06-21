// this uses a loop solution
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    // float change is the amount of change owed
    // int amount is the change x100 and turned into an integer to be used for calculation
    // int coins is the number of coins due back
    
    float change;
    int amount;
    int coins = 0;
    
    do
    {
        printf("Hi! How much are you owed? ");
        change = get_float();
    }
    while (change <= 0);
    
    amount = (round(change * 100));
    
    while (amount >= 25)
    {
        amount = (amount - 25);
        coins ++;
    }
    while (amount >= 10)
    {
        amount = (amount - 10);
        coins ++;
    }
    while (amount >= 5)
    {
        amount = (amount - 5);
        coins ++;
    }
    while (amount >= 1)
    {
        amount = (amount - 1);
        coins++;
    }

    printf("%i\n", coins);
}