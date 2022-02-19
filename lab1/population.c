#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int s;
    do
    {
        s = get_int("What do we start with? \n");
    }
    while (s < 9);

    // Prompt for end size
    int e;
    do
    {
        e = get_int("What do we end up with? \n");
    }
    while (e < s);

    // Keep track of number of years
    int y = 0;

    // Calculate number of years until we reach threshold
    // int y = 0, n = s;

    while (e > s)
    {
        s = s + (s / 3) - (s / 4);
        y++;
    }

    // Print number of years
    printf("Years: %i\n", y);

}
