#include <cs50.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


// defining a 'BYTE' as 8 bits, 'utin8_t' for easier usage.
typedef uint8_t BYTE;
// declaring an array of blocks of 512 *BYTEs, used for reading data from image into a buffer for analysis.
BYTE BUFFER[512];
// # Do i need to use malloc to declare 512 bytes of memory for storage?#

// declaring FILE called image
// FILE img;


// FUNCTION PROTOTYPES
void readimagetobuffer(void); // not sure if I need a function here.
bool jpegcheck(int buffer0, int buffer1, int buffer2, int buffer3); //jpeg check function
int jpegname (char *filename, int jpegcounter); // function to create filename for jpeg file
void jpegopen(char *filename); // function to create jpeg file

// MAIN
int main(int argc, char *argv[])
{

// setting jpeg counter, for naming of jpeg files.
int jpegcounter = 0;
// blocks read counter
int blockcount = 0;

// creating char array for file name
char filename[8]; // create array for filename
// constant for jpeg numbers
const int JPEGS = 10000;

FILE *img;


// OPENING FILE
// Check for invalid usage. Program requies 1 arg only.
if (argc == 1 || argc > 2)
    {
        printf("Usage: recover [image ...]\n");
        return 1;
    }

// OPEN FILE

// Open file specified in cmd line, argv[1]
FILE *file = fopen(argv[1], "r");


// (1) MAIN LOOP

{
    int i = 0;

    for (i = 0; i < JPEGS; i++)
    {
        // (2) Read 512 blocks into buffer
        {
            int bytesread = 0;
            bytesread = fread(BUFFER, sizeof(BYTE), 512, file);
            blockcount++;
        }

        //  (3) Call jpegcheck function
        {
            {
            if (jpegcheck(BUFFER[0], BUFFER[1], BUFFER[2], BUFFER[3])) // If jpeg header is found
                {
                    if (jpegcounter == 0) // and there is no jpeg file / it is the first jpeg
                    {
                        // (3A) Call Jpegname file function
                        jpegcounter++;
                        jpegname(filename, jpegcounter);  //No need to pass in address of filename. As it is an array, it is already passing in the address!
                        {
                            img = fopen(filename, "w"); //
                        }
                    }

            else  // and there is an existing jpeg
                {
                    if ((jpegcounter == i) && (i > 0)) // jpeg is equal to i, but must be greater than 0, as if i = 0, it's before any jpegs are created
                        {
                            fclose(img);
                        }

                        {
                            // (3A) Call Jpegname file function
                            jpegcounter++;
                            jpegname(filename, jpegcounter);
                            {
                                img = fopen(filename, "w");
                            }
                        }
                }
            }

               // else // if no jpeg header file is found

                {
                   // no existing jpeg
                    if (jpegcounter == 0)
                    {
                        //printf("No Jpeg found, no jpeg file yet, back to buffer\n");
                        //printf("Counter i: %i\n", i);
                    }

                   else
                   {
                        // existing jpeg
                        if ((jpegcounter == i) && (i > 0))
                       continue;
                      // skips to Write function
                       // printf("Still cruisin'. Counter i: %i\n", i);
                    }
                }
          }
        }
                if (jpegcounter > 0)

                {
                    fwrite(BUFFER, sizeof(BYTE), 512, img); //write data from buffer, into new file.
                    //printf("512 blocks written\n");
                    //printf ("\n");
                }
        }
   // End of Key Loop
    fclose(file);
}
}

// FUNCTION DEFINITIONS

bool jpegcheck(int buffer0, int buffer1, int buffer2, int buffer3)
{
    if (BUFFER[0] == 0xff && BUFFER[1] == 0xd8 && BUFFER[2] == 0xff && (BUFFER[3] & 0xf0) == 0xe0)
    {
        return 1;
    }

    else
    return 0;
}

int jpegname(char *filename, int jpegcounter)
{
// char filename[7]; // create array for filename
sprintf(filename, "%03i.jpg", (jpegcounter - 1)); // create filename, with jpegnumber denoting no#
// printf("Function - Name of file is: %s\n", filename); // printfcheck
// FILE *img = fopen(filename, "w"); // open new file with filename
return 1;
}

// open jpeg file
void jpegopen(char *filename)
{
    FILE *img = fopen(filename, "w"); // open new file with filename
    //printf("file created\n");


}

