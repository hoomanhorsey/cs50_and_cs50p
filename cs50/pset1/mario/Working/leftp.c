#include <stdio.h>
#include <cs50.h>

int main(void)


{
    // Gets input for (h)eight

    int h;

    do
        {
            h = get_int("Height:\n");
        }

    while (h < 1 || h >  8);

    // h = height, r = row

    // Loop A, keeps printing Loop B1-4 until rows == h. Loop A itself does not print anything.
    // Note:(r)ow begins at 0, as per convention.  But second function adds 1 to 'h', otherwise, for the first row, row == 1 already, and then the second function is satisfied and it wouldn't print anything

        {

        int r;

        {
            for (r = 0; r < (h + 1); r++)


        // Beginning of Loop B1-4.
        // Within Loop B1-4 are Loops B1, B2, PrintB3 and Loop B4, and a \n (new line)
        // These loops print out the characters that form each row. The characters that are printed are determined by which row (1,2,3 etc), as determined by Loop A

           {

            // Loop B1 prints how many 'spaces', based on accumulating (r)ows (i.e. if h = 8, then for row 1, (x = 1; 1 <8; 1++). A 'space' is printed 7 times. )

               {
                    int x;

                    {
                        for (x = r; x < h; x++)

                        {
                        printf(" ");
                        }
                    }


                }

            // Loop B2 calculates how many '#', on each row, based on (r)ow

                {
                    int y;

                    {
                        for (y = (h - r); y < h; y++)

                        {
                        printf("#");
                        }
                    }

                }


            // Function B3 prints the two mandatory spaces.

            printf("  ");

            // Loop B4 calculates how many # on each row, based on (r)ow

                {

                    int z;

                    {
                        for (z = (h - r); z < h; z++)

                        {
                        printf("#");
                        }

                    }
                }

            // Lastly, a new line is inserted after all of the functions in Loop B1-4 are completed
           printf ("\n");

            }

            // After the last curly brackets, Loop B1-4 is completed and the program returns to Loop A until the Loop A loop is satisfied (when R = h+1)
    }
    }
}