#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)

{
    char letter;


    letter = get_char("Letter:\n");

    printf("Your character is: %c\n", letter);
    printf("The ASCII value is: %i\n", letter);

    string word = get_string("Word:\n");

  


    {
        printf("The first letter is: %c\n", word[0]);
        printf("The ASCII value is: %i\n", word[0]);

        printf("The second letter is %c\n", word[1]);
        printf("The ASCII value is: %i\n", word[1]);

    }

    printf("Output:  ");
    for (int i = 0; word[i] != '\0'; i++)
    {
        printf("%c", word[i]);
    }
    
    printf("\n");
    
    printf("String Length: ");
    for (int a = 0; a < strlen(word); a++)
    {
        printf("%c", word[a]);
        
    }

    printf("\n");
    






}