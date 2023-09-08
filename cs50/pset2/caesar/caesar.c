#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// cmd line requests input.

int main(int argc, string argv[])

{
    
// sends error (non zero value) if user enters more than 1 entry @ cmd line || does not enter any key in cmd line

    {
        if ((argc > 2) || (argv[1] == 0))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

// examine if chars in argv[1] are alphanum. if argv[1][i] is alpha, returns non-zero error msg and ends.

    {
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
    }

// All the functions above stop program if anything other than alphanums are entered in cmd line.

// The cmd line entry string 'argv[1]' is converted to an integer with 'atoi', now called 'intkey'.
// Modulo of (intkey / 26) is retained. This reduces all keys greater than 26 to fall within 26.

    int intkey = atoi(argv[1]);
    intkey = intkey % 26;

// get_string used to obtain plaintext 'ptext'.

    string ptext = get_string("plaintext:");

// for loop to review ptext, convertings chars in ptext to ciphered char according to value of 'intkey'.
    {
        int u = 0;
        int plen = strlen(ptext);

        for (u = 0;  u < plen; u++)
        {
            
// Employs 'isalpha' to restrict ciphering to alpha chars only. Non-alpha, spaces, numbers left alone.

            int uchar = isalpha(ptext[u]); 
            if (uchar > 0)

// If 'isupper' catchs uppercase letters, employs 3 different formulas based on:
// sum of (char + key) < 'Z'/90, just add value of key
// sum of (char + key) > 'Z'/90, subtract 26, then add value of key
// sum of (char + key) = 'Z'/90, leave value as is.
// A to Z = 65 to 90, so the formula forces the values to 'wrap around'by resetting to 65 if the value is greater than 90

            {
                if (isupper(ptext[u]))
                
                {
                    if ((ptext[u] + intkey) < 'Z')
                    {
                        ptext[u] = (ptext[u] + intkey);
                    }

                    else if ((ptext[u] + intkey) > 'Z')
                    {
                        ptext[u] = ((ptext[u] - 26) + intkey);
                    }

                    else if ((ptext[u] + intkey) == 'Z')
                    {
                        ptext[u] = 'Z';
                    }

                }

// Same formula as the one used for uppercase chars applies, but adjusted for lowercase values, i.e. a to z = 97 to 122

                else if (islower(ptext[u]))

                {

                    if ((ptext[u] + intkey) < 'z')
                    {
                        ptext[u] = (ptext[u] + intkey);
                    }

                    else if ((ptext[u] + intkey) > 'z')
                    {
                        ptext[u] = ((ptext[u] - 26) + intkey);
                    }

                    else if ((ptext[u] + intkey) == 'z')
                    {
                        ptext[u] = 'z';
                    }
                }

            }

        }
    }
    
    printf("ciphertext: %s\n", ptext);

}
