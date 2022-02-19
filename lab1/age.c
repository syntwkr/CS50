#include <stdio.h>

int main(void)

{
    double input;
    printf("What's your age? ");
    scanf("%lf", &input);
    printf("You'll be %lf in a year\n", input + 1);
}