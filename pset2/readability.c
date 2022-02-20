#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Prototypes of functions
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int count_grade_level(int letters, int words, int sentences);
void print_result(int grade_level);

int main(void)
{
    // Get input text from the user
    string text = get_string("Text: ");

    //Calling functions
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    //Calling Coleman-Liau formula function
    int grade_level = count_grade_level(letters, words, sentences);

    //Finally
    print_result(grade_level);
}

//Counting letters
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }
    }
    return letters;
}

//Counting words
int count_words(string text)
{
    int words = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words += 1;
        }
    }
    return words + 1;
}

//Counting sentences
int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences += 1;
        }
    }
    return sentences;
}

//Plugging into the Coleman-Liau formula
int count_grade_level(int letters, int words, int sentences)
{
    float L = ((float) letters / (float) words) * 100;
    float S = ((float) sentences / (float) words) * 100;
    return round(0.0588 * L - 0.296 * S - 15.8);
}

//Printing the result!
void print_result(int grade_level)
{
    if (grade_level <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade_level >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade_level);
    }
}