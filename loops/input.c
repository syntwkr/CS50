#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int s;
    do
    {
        s = get_int("Введите число от 3 до 5 \n");
    } while ( s < 3 || s > 5 );
   printf ("Ввел %i\n", s);
}