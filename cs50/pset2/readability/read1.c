#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int lettercount(string words);
int spacecount(string words);


int main(void)

{
// Get and print string
    string text = get_string("Text: ");
        {
        printf("%s\n", text);
        }

// Get and print string length (inc spaces)
    int len = strlen(text);
        {
        printf("%i\n", len);
        }

// Engage letter count function

int letters = lettercount(text);
{
    printf("Number of letters: %i\n", letters);
}

// Engage space count function

int spaces = spacecount(text);
{
    printf("Number of spaces %i\n", spaces);
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
            lettertally += +1;
            printf("lettertally%i\n", lettertally);
        }
    }
    
    return lettertally;
}


// Tally spaces
int spacecount(string words)
{
    int i = 0;
    int spacetally = 0;
    int len = strlen(words);

    {
        for (i = 0; i < len; i++)
        {
            if isspace(words[i])
            spacetally += + 1;
            printf("spacetally%i\n", spacetally);
        }
    }

int nospacelen = (len - spacetally);
printf("nospacelen%i\n", nospacelen);

return nospacelen;

}
