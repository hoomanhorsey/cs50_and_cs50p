#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char ALPHA[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};


//int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: "); 

    // Score both words
    //int score1 = compute_score(word1);
    //int score2 = compute_score(word2);

int score1;
int score2;

    // TODO: Print the winner



// I'm trying to isolate each letter in a word by using the String as an array, and then equating each character with an equivalent points score in the POINTS array, and the creating an int called 'score' that tallies up the points. It does work, but not as a function.  And it's very inefficient.

//int compute_score(string word)


// uses strlen to get length of word1 and declares it as the variable 'length'

// creates loop, that iterates for the same number of times as the length of word1



for (int i = 0, wordlength1 = strlen(word1); i < wordlength1; i++)

// examines char number [i] of word1, which increase for each iteration of the loop (i.e starts at 0, then goes to 1)
// adds points based on teh points array, to the variable 'score'
{
//    char letter = word1[i];


    {
     int n;

     for (n = 0; n < 26; n++)

        {
            word1[i] = toupper(word1[i]);

            if (word1[i] == ALPHA[n])

        score1 = (score1 + POINTS[n]);
        }
    }


}

for (int i = 0, wordlength2 = strlen(word2); i < wordlength2; i++)

{
//    char letter = word1[i];


    {
     int m;

     for (m = 0; m < 26; m++)

        {
            word2[i] = toupper(word2[i]);

            if (word2[i] == ALPHA[m])

        score2 = (score2 + POINTS[m]);
        }
    }


}

if (score1 > score2)

{   
    printf("Player wins!");
}
if (score1 < score2)

{
    printf("Player2 wins!");
}

if (score1 == score2)
{
    printf("Tie");
    

}
        printf("\n");

        printf("%i\n", score1);
        
        printf("%i\n", score2);
        

// possible nested loop? for (char n = a; a < z; n++)

// or could you create a new function that inclues all the letters. a-z, for each of words? Create new inputs for the function?


}

// THE ABOVE WORKS> BUT CAN I CREATE ANOTHER LOOP THAT MAKES EACH ALPHABETICAL LETTER AN ITERATION? AND EACH POINTS[] AN ITERATION?
// CAN I MAKE THE 'a' in the 'if letter == 'a', a nested loop variable?
// Can I make the number in [Points[] a iterating variable too?
//scrabscratch3 tries to make a loop for these but doesn't work yet.








// TODO: Compute and return score for string



// NOTEs
// 'word1' and 'word2' are strings given to the function, 'compute_score'
// 'scorew1' and 'score2' are the output integers from the function 'compute_score'


// The function 'compute_score'needs to:
// - Identify each of the chars included in each string ('word1' and 'word2')




// - Match up the points assigned to each of those chars, via the values set in the array POINTS;





// Di i manually assign each of the points to the letters of another array, as per Doug Lloyd's Arrays video - 10m30s?', like an array of chars?


//       Then once you have the letter, you can assign each letter a corresponding point value in the array?  i.e. char a = [0], char b = [3]
        //  Q, do I have to map out the entire alphabet first? Or can I do it on an adhoc basis?





// - Add those points together for each of 'word1' and 'word2'

// - Determine which of 'word1' or 'word2'has the higher value, of if they are equal

    //   int 'sum1' and 'sum2', to represent the points sum for each of the words.
    // If (sum1 < sum2), then print Score 1 wins,   if (sum1 > sum 2), then print Score 1 wins, if (sum1 == sum2), then print 'Tie'

// - Print the result.





