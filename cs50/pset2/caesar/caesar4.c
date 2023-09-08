#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])

// cmd line, requests input. Input as a string so 'key' needs to be converted to an int before use.

{

// Sends error if user does not enter any key in cmd line || user enters more than 1 entry @ cmd line

    if ((argc > 2) || (argv[1] == 0))
    {
        printf("Usage: ./caesar key\n");
        return 0;
    }

// examine if argv[1] is an alphanum

    int i = 0;
    int len = strlen(argv[1]);

// if argv[1][i] is alpha, returns non-zero.
    {
        for (i = 0; i < len; i++)
        {
            int alpha = isalpha(argv[1][i]);
            {
                if (alpha > 0)
                {
                    printf("Usage: ./caesar key\n");
                    return 0;
                }
            }
        }
    }


// prints success if a single string is entered at cmd line. All the preceding exits mean that only alphanums are accepted.
// also, 'atoi' converts the string into an integer before printing.
    int intkey = atoi(argv[1]);

    {
        printf("Success\n");
        printf("%i\n", intkey);
    }
    
// Divides intkey by 26 and retains moduls, to allow for keys greater than 26
   
    intkey = intkey % 26;
    {
    printf("modulo of intkey: %i\n", intkey);
    }

string plaintext = get_string("plaintext:");


int u = 0;
int plainlen = strlen(plaintext);


for (u = 0; u < plainlen; u++)

    {
        plaintext[u] = plaintext[u] + intkey;
    }

        printf("ciphertext: %s\n", plaintext);


// need to confine ciper to alphaonly, and exclude numbers and puncuation.


}
