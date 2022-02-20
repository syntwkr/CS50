#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int input, m1 = 1, m2 = 1;

    input = get_int("Give me an integer: ");

    for ( m2 = 1; m2 <= 10; m2++)
    {

        for ( m1 = 1; m1 <= input; m1++)

        {

            printf("%i X %i = %i\n", m1, m2, m1*m2);

        }

        printf("\n");
    }

}