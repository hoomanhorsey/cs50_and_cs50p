#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");






    //i.e.   Identify the position of each letter in the string?
            // How does one do that?


            do
            {

            }
            while


            /// upercase? Do i need to conver the chars to upper case to simplify the calculation? Thatway, for example, I'd only need to deal with one ascii value.



            // only include characters (exclude non letter chars)

            // if charcters in word1 are NOT
            // equal to or greater than 65 and equal to or less than 90
            // equal to or greater than 97 and equal to or less than 122
                // then ignore.




            // Get length of word1 amd call it 'length1'

            int length1 = strlen(word1);

            // print it to test
            printf("Length of word: %i\n", length1);

            for (int i = 0; i < length1; i++)
                {
            printf("%c\n", word1[i]);
                }

            printf("ASCII values\n");

            for (int i = 0; i < length1; i++)
                {

            printf("%i, ", word1[i]);

                }


            // using a loop to extract each of the chars for word1

          //  for (int i = 0; i < length1; i++);
        //    {
        //        printf("%c", word1[i]);
         //   }

///   So this declares a variable called Score, which is set at 0.
// The if, states that if the letter is 'a', then the points in the points array associated with a Points[0], should be added to score.
// It currently does this for each char (0, 1, 3), going through the 26 letters for each char.
// There should be a way of looping this as it's iterative.

    int score = 0;

            if (word1[0] == 'a');
            printf("yes");
            then (score + points[0]);

            if (word1[0] == 'b');
            printf("yes");
            then (score + points[1]);

            if (word1[0] == 'c');
            printf("yes");
            then (score + points[2]);




            if (word1[1]) == 'a');
            printf("yes");
            then (score + points[1]);









}
