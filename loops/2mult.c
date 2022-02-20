#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int i, input, mult = 1;

    input = get_int("Give me an integer: ");

    for ( i = 1; i <= input; i++ )
    {
        printf("%i X %i is %i\n", input, i, input*i);
    }
}
