#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
// int per100(int sumLetters);

int main(void)
{
    // Prompt user for text
    string text = get_string("Text: ");

    // count number of words
    int totalWords = count_words(text);
 week_2
 
    // count number of letters
    int letters = count_letters(text);

    // count number of sentences
    int sentences = count_sentences(text);

    // calculate averages
    float L = ((letters * (float)100) / totalWords);

    float S = ((sentences * (float)100) / totalWords);

    // calculate index grade level
    float rawIndex = ((0.0588 * L) - (0.296 * S) - 15.8);
    int index = roundf(rawIndex);

    // determine grade level and print
    int GRADE[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        int gradeLevel = GRADE[index - 1];
        printf("Grade %i\n", gradeLevel);
    }
}

int count_words(string text)
{
    int sumWords = 1;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isblank(text[i]))
        {
            sumWords++;
        }
    }
    // printf("number of words is %i\n", sumWords);
    return (sumWords);
}

int count_letters(string text)
{
    int sumLetters = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            sumLetters++;
        }
    }
    // printf("number of letters is %i\n", sumLetters);
    return (sumLetters);
}

int count_sentences(string text)
{
    int sumSetences = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if ((text[i] == '.' || text[i] == '!' || text[i] == '?') && (isblank(text[i + 1]) || (text[i + 1] == 0)))
        {
            sumSetences++;
        }
    }
    // printf("number of sentences is %i\n", sumSetences);
    return (sumSetences);
}
