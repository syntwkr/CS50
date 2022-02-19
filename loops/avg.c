#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int i, sum;
    float avg;

    sum = i = 0;

    for ( i = 1; i < 11; i++)
    {
        sum = sum + get_int("Give me %i number: ", i);
    }
    avg = sum / 10.0;

    printf("Sum is: %i\n", sum);
    printf("Average is: %f\n", avg);
}