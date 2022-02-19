#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    //Making sure the program is executed with one command-line argument, the key. Otherwise print an error message
    if (argc != 2)
    {
        printf("Errare humanum est.\n");
        return 1;
    }

    //Making sure the characters of the "key" are decimal digits. Otherwise reminds of proper usage
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    //Converting a string that looks like a number into that number
    int k = atoi(argv[1]);

    //Getting the input from the user
    string plaintext = get_string("plaintext: ");

    //Prepairing to print the output
    printf("ciphertext: ");

    //Doing the job
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
            continue;
        }

        //Preserving upper-/lowercase with the ascii chart
        int ascii;
        if isupper(plaintext[i])
        {
            ascii = 65;
        }
        else
        {
            ascii = 97;
        }

        //Converting ASCII to alphabetical index
        int plain = plaintext[i] - ascii;

        // Alternating the letters, wrapping around last and first letters of the alphabet within the index
        int cipher = (plain + k) % 26;

        //Print the output, converting index back to ASCII
        printf("%c", cipher + ascii);
    }

    printf("\n");
    return 0;
}