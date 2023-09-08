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
bool jpgcheck(int buffer0, int buffer1, int buffer2, int buffer3); //jpg check function
int jpgname (char *filename, int jpgcounter); // function to create filename for jpg file

// MAIN
int main(int argc, char *argv[])
{

// setting jpg counter, for naming of jpg files.
int jpgcounter = 0;
// blocks read counter
int blockcount = 0;

// creating char array for file name
char filename[8]; // create array for filename
// constant for jpg numbers
const int jpgS = 10000;

FILE *img;


// OPENING FILE
// Check for invalid usage. Program requies 1 arg only.
if (argc == 1 || argc > 2)
    {
        printf("Usage: recover [image ...]\n");
        return 1;
    }

// Open file specified in cmd line, argv[1]
FILE *file = fopen(argv[1], "r");


// (1) MAIN LOOP

while (jpgcounter < 50)

// (2) Read 512 blocks into buffer
    {
        fread(BUFFER, sizeof(BYTE), 512, file);
        blockcount++;  //#superflous##

    //  (3) Call jpgcheck function

        {
            if (BUFFER[0] == 0xff && BUFFER[1] == 0xd8 && BUFFER[2] == 0xff && (BUFFER[3] & 0xf0) == 0xe0)


//            if (jpgcheck(BUFFER[0], BUFFER[1], BUFFER[2], BUFFER[3])) // If jpg header is found
            {
                if (jpgcounter == 0) // and there is no jpg file / it is the first jpg
                {
                    // (3A) Call jpgname file function
                    jpgcounter++;
                    jpgname(filename, jpgcounter);  //No need to pass in address of filename. As it is an array, it is already passing in the address!
                    {
                        img = fopen(filename, "w");
                        fwrite(BUFFER, sizeof(BYTE), 512, img); //write data from buffer, into new file.
                    }
                }

                else  // and there is an existing jpg
                {
                    fclose(img);
                    // (3A) Call jpgname file function
                    jpgcounter++;
                    jpgname(filename, jpgcounter);
                    {
                        img = fopen(filename, "w");
                        fwrite(BUFFER, sizeof(BYTE), 512, img); //write data from buffer, into new file.
                    }
                }
            }

             // if no jpg header file is found + there is an existing jpg
            else if (jpgcounter > 0)
            {
                fwrite(BUFFER, sizeof(BYTE), 512, img); //write data from buffer, into new file.
            }
        }
    }
// End of Key Loop
fclose(file);

}

// FUNCTION DEFINITIONS

bool jpgcheck(int buffer0, int buffer1, int buffer2, int buffer3)
{
    if (BUFFER[0] == 0xff && BUFFER[1] == 0xd8 && BUFFER[2] == 0xff && (BUFFER[3] & 0xf0) == 0xe0)
    {
        return 1;
    }
    else
    return 0;
}

int jpgname(char *filename, int jpgcounter)
{
// char filename[7]; // create array for filename
sprintf(filename, "%03i.jpg", (jpgcounter - 1)); // create filename, with jpgnumber denoting no#
return 1;
}


