#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int i;
    
    
    // gets input
    
    string s = get_string("Input:  ");
    
    int t = strlen(s);
    
    //prints output
    
    printf("Output:\n");
    
        // loop to print out each char individually, but to string length (strlen)
    for (i = 0; i < strlen(s); i++)
    {
        printf("%c", s[i]);
       

    }
    // Consider variation in lecture 2 @ 1:47 where the a new variable is created that is n = strlen(s) and that is used to calculate the strlens and count the chars more efficiently.
    
    
    printf("\n");
    
        // prints i, which according to the loop above, adds +1 (i++), until the string ends. Which allows you to calculate the actual length of the string and print it.
    
    printf("The number of chars is: %i\n", i);
    
    printf("String length according to strlens is: %i\n", t);
    
}