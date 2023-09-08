#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int lettercount(string words);
int wordcount(string words);
int sentencecount(string words);

int main(void)

{
// Get and print string
    string text = get_string("Text: ");

// Engage letter count function

    int letters = lettercount(text);

// Engage word count function

    int words = wordcount(text);

// Engage sentence count function

    int sentences = sentencecount(text);

// Calculate readability
// L is the average number of letters per 100 words in the text
// S is the average number of sentences per 100 words in the text.
// index = 0.0588 * L - 0.296 * S - 15.8

    float L = (((float)letters / words) * 100.00);

    float S = (((float)sentences / words) * 100.00);

    float index = ((0.0588 * L) - (0.296 * S) - 15.8);

    if (index >= 16)
    
    {
        printf("Grade 16+\n");
    }

    else

        if (index < 1)
    
        {
            printf("Before Grade 1\n");
        }
    
        else

            if ((index >= 1) || (index < 16))
            {
                printf("Grade %i\n", (int) round(index));
            }

}



// Function descriptions

int lettercount(string words)

{
    int lettertally = 0;
    int i = 0;
    int len = strlen(words);
    {
        for (i = 0; i < len; i++)

        {
            if (isalpha(words[i]))
            {
                lettertally += +1;
            }
        }
    }

    return lettertally;
}

int wordcount(string words)

// Counts spaces as a proxy for words.  Starts at 1, as one word will not have a space. Still dosn't work cos if there is no entry, it counts it as one.
{

    int i = 0;
    int len = strlen(words);
    int wordtally = 1;

    // word tally calculates 0 tally if there is no entry. But later, defaults at 1, as if there is only 1 word there is no space to count.
    // word tally still counts numbers which could be an issue.

    if (len == 0)
    {
        wordtally = 0;
        {
            return wordtally;
        }
    }

    else

    {
        for (i = 0; i < len; i++)
        {
            if (isspace(words[i]))
            {
                wordtally += +1;
            }
        }
    }
    return wordtally;
}

int sentencecount(string words)

{
    int sentencetally = 0;
    int i = 0;
    int len = strlen(words);
    {
        for (i = 0; i < len; i++)
        {
            if ((words[i] == '.') || (words[i] == '!') || (words[i] == '?'))
            {
                sentencetally += +1;
            }
        }
    }

    return sentencetally;
}





