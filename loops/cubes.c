#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int i, cube, input;

    input = get_int("Give me an integer: ");

    for ( i = 1; i <= input; i++ )
    {
        printf("Number is %i and the cube of %i is %i\n", i, i, i*i*i);
    }
    printf("\n");
}