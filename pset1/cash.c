#include<stdio.h>
#include<math.h>
#include<cs50.h>

int main(void)
{
    float change;
    int coins = 0;
    int change_rem = 0;

    // Prompt user for a positive amount of change
    do
    {
        change = get_float("Change owed: ");
    }
    while (change <= 0.00);

    // Converting dollars to cents
    int cents = round(change * 100);

    // Keeping track of coins and remaining change owed
    coins = cents / 25;
    change_rem = cents % 25;

    coins += change_rem / 10;
    change_rem = change_rem % 10;

    coins = coins + change_rem / 5;
    change_rem = change_rem % 5;

    coins = coins + change_rem / 1;
    change_rem = change_rem % 1;

    printf("%i\n", coins);

}