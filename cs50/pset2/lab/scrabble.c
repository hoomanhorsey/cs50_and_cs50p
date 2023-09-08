#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet, in an array
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Array setting out the letters of the alphabet, in uppercase
char ALPHA[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

// Prototyping the function
int compute_score(string word);

int main(void)

{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner

    if (score1 > score2)
    {
        printf("Player 1 Wins!\n");
    }
    if (score1 < score2)
    {
        printf("Player 2 Wins!\n");
    }
    if (score1 == score2)
    {
        printf("Tie!\n");
    }
}

// Defining the function. Note function sits outstide of main. The contents of function sits within it's own {}
// Even tho there are two inputs, the same function is used. The returned output is tied to the declared input, which means only one function is required

int compute_score(string word)

{

// 'funcscore' is declared as zero so that each time it is used it doesn't carry over the value from previous use
    int funcscore = 0;

// strlen gets length of 'word' and declares it 'wordlength1'
// creates a for loop, that iterates each char of word, i.e 'word[i]', for the duration of 'wordlength'

    for (int i = 0, wordlength = strlen(word); i < wordlength; i++)

// creates a nested for loop, for each char [i]:
// - changes any characters to uppercase
// - iterates it 26 times (equivalent to the ALPHABET array, 'A' to 'Z')
// - where word[i] = A-Z, adds the equivalent points from Points array to 'funcscore'
// the iterative value 'n', can be shared by the ALPHA and POINTS arrays as the ALPHA value determines the POINTS.

    {
        int n;
        for (n = 0; n < 26; n++)
        {
            word[i] = toupper(word[i]);
            if (word[i] == ALPHA[n])
            {
                funcscore = (funcscore + POINTS[n]);
            }
        }
    }
    return funcscore; // returns the value of funcsore to the variable named as the input, i.e. Score1 or Score2
}







