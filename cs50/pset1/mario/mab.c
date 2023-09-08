#include <stdio.h>
#include <cs50.h>

// Prototype for print#, a defined function
void printloophash(void);

int main(void)



    // Gets input for (h)eight, above 1 and less than 8
    int h;
    do
    {
        h = get_int("Height: ");
    }

    while (h < 1 || h > 8);

    // h = height

    // Loop A, keeps printing Loop B1-4 until rows == h. Loop A itself does not print anything.
    // Note: (r)ow begins at 0, as per convention, and repeats for the same number of (h).But as some loops are not printed at row 1, the loops require some compensation.
    // r = row
    
    {
        int r;
        {
            for (r = 0; r < h; r++)

     // Loop B1-4.
     // Within Loop B1-4 are Loops B1, B2, PrintB3 and Loop B4, and a \n (new line)
     // These loops print out the characters that form each row. The characters that are printed are determined by which row (1,2,3 etc), as determined by Loop A

        {
        // Loop B1 prints how many 'spaces', based on accumulating (r)ows (i.e. if h = 8, then for row 1, (x = 0; 0 <7; 1++), 7 spaces are printed).
            {
               int x;
                   {
                       for (x = r; x < (h - 1); x++)
                       {
                       printf(" ");
                       }
                   }
            }

          // Loop B2 calculates how many '#', on each row, based on (r)ow. Loop B2 is carried out by the printloop# function.
            
            {
                   printloophash;  
            }

            // Function B3 prints the two mandatory spaces.
            {
            printf("  ");
            }
            
            // Loop B4 calculates how many # on each row, based on (r)ow. Loop B2 is carried out by the printloop# function.
            {
                   printloophash;  
            }

            // Lastly, a new line is inserted after all of the functions in Loop B1-4 are completed

            {            
            printf("\n");  
            }

            // After the last curly brackets, Loop B1-4 is completed and the program returns to Loop A until the Loop A loop is satisfied (when R = h+1)
            }   
        }
    }

// Printloop#, a defined function

// Printloop# prints hashes for a number determined by the (h) and the (r). i.e. if h = 8, then for row 1, (z = (8-1); 7 <8+1; 1++), only 1 hash is printed before 'x < h + 1' becomes false, and printing stops.


void printloophash(void)
    
        int z;
            {
                for (z = (h - r); z < h + 1; z++)
                {
                    printf("#");
                }
            }
    


   