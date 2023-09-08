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
    string word2 = get_string("Player 2: ");

    // Score both words
    //int score1 = compute_score(word1);
    //int score2 = compute_score(word2);

    // TODO: Print the winner



// I'm trying to isolate each letter in a word by using the String as an array, and then equating each character with an equivalent points score in the POINTS array, and the creating an int called 'score' that tallies up the points. It does work, but not as a function.  And it's very inefficient.

//int compute_score(string word)

int score = 0;


// scoring the first letter
    if (word1[0] == 'a')
        {
        score = score + POINTS[0];
        }
    if (word1[0] == 'b')
        {
        score = score + POINTS[1];
        }
    if (word1[0] == 'c')
        {
        score = score + POINTS[2];
        }
    if (word1[0] == 'd')
        {
        score = score + POINTS[3];
        }
        
        
      // scoring the second letter  
      if (word1[1] == 'a')
        {
        score = score + POINTS[0];
        }
    if (word1[1] == 'b')
        {
        score = score + POINTS[1];
        }
    if (word1[1] == 'c')
        {
        score = score + POINTS[2];
        }
    if (word1[1] == 'd')
        {
        score = score + POINTS[3];
        }
        
      // scoring the third letter
        if (word1[0] == 'a')
        {
        score = score + POINTS[0];
        }
    if (word1[2] == 'b')
        {
        score = score + POINTS[1];
        }
    if (word1[2] == 'c')
        {
        score = score + POINTS[2];
        }
    if (word1[2] == 'd')
        {
        score = score + POINTS[3];
        }
        
        
        
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





