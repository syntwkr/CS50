#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int a = 3;
    int b = a;
    a = 4;
    printf("a is %i, b is %i \n", a, b);
    printf("address of a is %p, address of b is %p \n", &a, &b);
}