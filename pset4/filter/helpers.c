#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Average the colors to get grey
            int grey = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen = grey;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int MAX_VALUE = 255;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            image[i][j].rgbtRed = fmin(MAX_VALUE, sepiaRed);
            image[i][j].rgbtBlue = fmin(MAX_VALUE, sepiaBlue);
            image[i][j].rgbtGreen = fmin(MAX_VALUE, sepiaGreen);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through rows
    for (int i = 0; i < height; i++)
    {
        // Loop through pixels
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels on horizontally opposite sides
            RGBTRIPLE buffer = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = buffer;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a buffer image
    RGBTRIPLE buffer[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average_red = 0;
            int average_blue = 0;
            int average_green = 0;
            float counter = 0.00;

            // Find the neighbouring pixels in a row
            for (int x = -1; x < 2; x++)
            {
                // Find the neighbouring pixels in a column
                for (int y = -1; y < 2; y++)
                {
                    int rgb_x = i + x;
                    int rgb_y = j + y;

                    // check for valid neighbouring pixels
                    if (rgb_x < 0 || rgb_x > (height - 1) || rgb_y < 0 || rgb_y > (width - 1))
                    {
                        continue;
                    }

                    // Get the image value
                    average_red += image[rgb_x][rgb_y].rgbtRed;
                    average_green += image[rgb_x][rgb_y].rgbtGreen;
                    average_blue += image[rgb_x][rgb_y].rgbtBlue;
                    counter++;
                }

                // Get the average of pixels
                buffer[i][j].rgbtRed = round(average_red / counter);
                buffer[i][j].rgbtGreen = round(average_green / counter);
                buffer[i][j].rgbtBlue = round(average_blue / counter);
            }
        }
    }

    // Copy the blurred image to the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = buffer[i][j].rgbtRed;
            image[i][j].rgbtGreen = buffer[i][j].rgbtGreen;
            image[i][j].rgbtBlue = buffer[i][j].rgbtBlue;
        }
    }
    return;
}
