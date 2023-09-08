#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

//int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    //string word2 = get_string("Player 2: "); //reinstate once its fixed.

    // Score both words
    //int score1 = compute_score(word1);
    //int score2 = compute_score(word2);

    // TODO: Print the winner



// I'm trying to isolate each letter in a word by using the String as an array, and then equating each character with an equivalent points score in the POINTS array, and the creating an int called 'score' that tallies up the points. It does work, but not as a function.  And it's very inefficient.

//int compute_score(string word)

int score = 0;

// uses strlen to get length of word1 and declares it as the variable 'length'
int length = strlen(word1);

// creates loop, that iterates for the same number of times as the length of word1

for (int i = 0; i < length; i++)

// examines char number [i] of word1, which increase for each iteration of the loop (i.e starts at 0, then goes to 1)
// adds points based on teh points array, to the variable 'score'
{
    char letter = word1[i];
    
    
    //trying to get the char to iterate from a-z in a loop
   
   
    for (char n = 97; 97 < 122; n++)
    

    {  
    if (letter == 'n') //|| (letter == 'A'))
}

// need to also get the points to iterate from 0-25, with each pass of the loop.
// 'p' needs to be another variable that goes up by 1.
    for (int p = 0; p < 25; p++)

    {
        score = score + POINTS[p];
    }
}
    //if (letter == 'b')

}

// THE ABOVE WORKS> BUT CAN I CREATE ANOTHER LOOP THAT MAKES EACH ALPHABETICAL LETTER AN ITERATION? AND EACH POINTS[] AN ITERATION?
// CAN I MAKE THE 'a' in the 'if letter == 'a', a nested loop variable?
// Can I make the number in [Points[] a iterating variable too?


    printf("%i\n", score);

}





    // TODO: Compute and return score for string



// NOTEs
// 'word1' and 'word2' are strings given to the function, 'compute_score'
// 'scorew1' and 'score2' are the output integers from the function 'compute_score'


// The function 'compute_score'needs to:
// - Identify each of the chars included in each string ('word1' and 'word2')




// - Match up the points assigned to each of those chars, via the values set in the array POINTS;




//i.e.   Identify the position of each letter in the string?
            // How does one do that?


            // Get length of word1 amd call it 'length1'






        //#Can I declare the value of each item in the array like this?
        //    letters 'a' and 'A' = POINTS[1]

// Di i manually assign each of the points to the letters of another array, as per Doug Lloyd's Arrays video - 10m30s?', like an array of chars?


//       Then once you have the letter, you can assign each letter a corresponding point value in the array?  i.e. char a = [0], char b = [3]
        //  Q, do I have to map out the entire alphabet first? Or can I do it on an adhoc basis?





// - Add those points together for each of 'word1' and 'word2'

// - Determine which of 'word1' or 'word2'has the higher value, of if they are equal

    //   int 'sum1' and 'sum2', to represent the points sum for each of the words.
    // If (sum1 < sum2), then print Score 1 wins,   if (sum1 > sum 2), then print Score 1 wins, if (sum1 == sum2), then print 'Tie'

// - Print the result.





