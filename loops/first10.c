#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int n;
    int sum;
    sum = 0;
    printf("First 10 natural numbers are:\n");
    for (n = 1; n <= 10; n++)
    {
        printf("%i ", n);
        sum = sum + n;
    }
printf("\n%i", sum);
printf("\n");
}