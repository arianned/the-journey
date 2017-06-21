#include <stdio.h>
#include <cs50.h>

int main (void)
{
    printf ("How long do you shower for? Enter the time in minutes: ");
    int minutes = get_int();
    int bottles = (minutes * 12);
    printf("Your shower uses approximately %i bottles of water\n", bottles);
}
