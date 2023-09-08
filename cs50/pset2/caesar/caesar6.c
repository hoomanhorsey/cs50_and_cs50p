#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


// Array setting out the letters of the alphabet, in uppercase
//char AZUPPER[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

//char AZLOWER[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};


int main(int argc, string argv[])


{
// cmd line requests input. Input as a string so 'key' needs to be converted to an int before use.
// sends error if user does not enter any key in cmd line || user enters more than 1 entry @ cmd line

    if ((argc > 2) || (argv[1] == 0))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

// examine if argv[1] is an alphanum
// if argv[1][i] is alpha, returns non-zero and ends.

    int i = 0;
    int len = strlen(argv[1]);

    {
        for (i = 0; i < len; i++)
        {
            int alpha = isalpha(argv[1][i]);
            {
                if (alpha > 0)
                {
                    printf("Usage: ./caesar key\n");
                    return 1;
                }
            }
        }
    }


// temp - prints key if a single string is entered at cmd line. All the preceding exits mean that only alphanums are accepted.
// also, 'atoi' converts the string into an integer before printing.
// Divides intkey by 26 and retains modulo, to allow for keys greater than 26

    int intkey = atoi(argv[1]);
    intkey = intkey % 26;
   
   
string plaintext = get_string("plaintext:");

int u = 0;
int plainlen = strlen(plaintext);

for (u = 0; u < plainlen; u++)

    {
        int uchar = isalpha(plaintext[u]);

        if (uchar > 0)
        
        {
          if (isupper(plaintext[u]))
            {   
            
            if ((plaintext[u] + intkey) <= 90)
    
                
                    plaintext[u] = (plaintext[u] + intkey);
                
            else if (plaintext[u] > 90)
                
                    plaintext[u] = ((plaintext[u] - 26) + intkey);
          
            }
            
             else if (islower(plaintext[u]))
             
             {   
            
            if ((plaintext[u] + intkey) <= 122)
    
                
                    plaintext[u] = (plaintext[u] + intkey);
                
            else if (plaintext[u] > 122)
                
                    plaintext[u] = ((plaintext[u] - 26) + intkey);


            }

        }

    }
        printf("ciphertext: %s\n", plaintext);

// At the moment, the int key has been modified so that it stays within 26....however, the letters don't loop around by 26. Need to apply a loop of 26...i.e.z goes to some weird chars, it doesn't loop around just yet.
}
