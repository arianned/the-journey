#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int height;
    int width;
    do
    {
        printf("How tall would you like the pyramid to be? Enter a value between 0 and 23: ");
        height = get_int();
    }
    while (height <0 || height >23);
    for (int i = 0; i < height; i++)
    {
        width = height-i;
        printf("%*s", width, "#");
            for (int j = 0; j < i; j++)
                {
                    printf("#");  
                }
        printf("#\n");
    }
}
