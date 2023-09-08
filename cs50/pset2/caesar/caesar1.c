#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])

// cmd line, requests input. Input as a string so 'key' needs to be converted to an int before use.

{
// Sends error if user enters more than 1 entry @ cmd line.
if (argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 0;
    }

// Sends error if user does not enter key in cmd line
if (argv[1] == 0)
    {
        printf("Usage: ./caesar key\n");
        return 0;
    }

// prints success if a single string is entered at cmd line, but can't distinguish if it's an interger or alpha
if (argv[1] != 0)
    {
    printf("Success\n");
    printf("%s\n", argv[1]);
    }

// examine if argv[1] is an alphanum

//if (isalnum((int)(argv[1])))

int i = 0;
int len = strlen(argv[1]);

{
for (i = 0; i < len; i++)
    {
        int alpha = isalnum(argv[1][i]);
        {
            printf("testprint%i\n", alpha);
        }
    }
}
{
    printf("Yay\n");
}



{
    string plaintext = get_string("plaintext:");
}

{
    printf("ciphertext:\n");
}

//return 0;

}
