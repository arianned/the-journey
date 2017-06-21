// this uses a modulo approach
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    // float change is the amount of change owed
    // int amount is the change x100 and turned into an integer to be used for calculation
    // int coins is the number of coins due back - starts at zero as we don't begin with any
    // int leftover is the amount leftover during our division process
    // int quarters is the amount of quarters handed out
    // int dimes is the amount of dimes handed out
    // int nickels is the amount of nickels handed out
    
    float change;
    int amount;
    int coins = 0;
    int leftovers;
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    
    do
    {
        printf("Hi! How much are you owed? ");
        change = get_float();
    }
    while (change <= 0);
    
    amount = (round(change * 100));
    
    //quarters sum
    quarters = amount / 25;
    leftovers = amount % 25;
    
    // dimes sum
    dimes = leftovers / 10;
    leftovers = leftovers % 10;
    
    // nickels sum
    nickels = leftovers / 5;
    leftovers = leftovers % 5;
    
    // work out total coins
    coins = quarters + nickels + dimes + leftovers;
    
    printf("%i\n", coins);
}