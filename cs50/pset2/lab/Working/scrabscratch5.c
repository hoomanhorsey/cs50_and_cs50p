#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
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

// Defining the function

int compute_score(string word)

{

 int funcscore = 0;
 
// strlen gets length of 'word1' and declares it 'wordlength1'
// creates for loop, that iterates each char 'i', for the duration of 'wordlength1'

        for (int i = 0, wordlength = strlen(word); i < wordlength; i++)

// creates for loop, for each specific letter 'word[i]'
// changes any characters to uppercase
// iterates it 26 times (equivalent to the ALPHABET array, 'A' to 'Z'
// where word[i] = to a letter, adds the equivalent points from Points array to 'score'

        {
           
        int n;
        for (n = 0; n < 26; n++)
                {
                word[i] = toupper(word[i]);
                if (word[i] == ALPHA[n])
                funcscore = (funcscore + POINTS[n]);
                }
                
                  
        }
     return funcscore; 
     
}


// TODO: Compute and return score for string






