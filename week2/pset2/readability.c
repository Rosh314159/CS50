#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);
    //printf("Letters: %f\n", letters);
    //printf("Words: %f\n", words);
    //printf("Sentences: %f\n", sentences);
    float L = ((letters) / words) * 100;
    float S = (sentences / words) * 100;
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    int grade = round(index);
    if ((grade >= 1) && (grade <= 16))
    {
        printf("Grade %i\n", grade);
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (((text[i] >= 65) && (text[i] <= 90)) || ((text[i] >= 97) && (text[i] <= 122)))
        count += 1;
    }
    return count;
}
int count_words(string text)
{
    int count = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 32)
        count += 1;
    }
    return count;
}
int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] == 46) || (text[i] == 63) || (text[i] == 33))
        count += 1;
    }
    return count;
}