#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");


for (int u = 0, wordlength = strlen(word1); u < wordlength; u++)

{
printf("%c", toupper(word1[u]));
}
printf("\n");

}