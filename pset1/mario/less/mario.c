#include <cs50.h>
#include <stdio.h>

// Draws a half-pyramid of a specified height

int main(void)
{
    int height, line_num, position;

    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0 || height > 8);

    // Outer loop to walk through the rows
    for (line_num = 1; line_num <= height; line_num++)
    {
        /* Inner loop to draw the line of spaces and hashes
           amount of spaces in each row equals to the height of the pyramid less number of the current line
           amount of hashes equals to the row number (counting from 1)
        */
        for (position = 0; position >= 0 && position < height - line_num; position++)
        {
            printf(" ");
        }

        for (position = height - line_num; position < height; position++)
        {
            printf("#");
        }

        printf("\n");
    }

}
