#include <cs50.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// defining a 'BYTE' as 8 bits, 'utin8_t' for easier usage.
typedef uint8_t BYTE;
// declaring an array of blocks of 512 *BYTEs, used for reading data from image into a buffer for analysis.
BYTE BUFFER[512];

// MAIN
int main(int argc, char *argv[])
{

    int jpgcounter = 0; // setting jpg counter, for naming of jpg files.
    char filename[8]; // create array for filename
    FILE *img; // declaring File named 'image'

// OPENING FILE
// Check for invalid usage. Program requies 1 arg only.
    if (argc == 1 || argc > 2)
    {
        printf("Usage: recover [image ...]\n");
        return 1;
    }

// Open file specified in cmd line, argv[1]
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        return 2;
    }

// (1) MAIN LOOP

    while (!feof(file))

// (2) Read 512 blocks into buffer
    {
        fread(BUFFER, sizeof(BYTE), 512, file);

        if (feof(file))
        {
            return 0;
        }

//  (3) Call jpgcheck function

        {
            if (BUFFER[0] == 0xff && BUFFER[1] == 0xd8 && BUFFER[2] == 0xff && (BUFFER[3] & 0xf0) == 0xe0)
            {
                if (jpgcounter == 0) // and there is no jpg file / it is the first jpg
                {
                    // (3A) Call jpgname file function
                    jpgcounter++;
                    sprintf(filename, "%03i.jpg", (jpgcounter - 1));
                    img = fopen(filename, "w");
                    fwrite(BUFFER, sizeof(BYTE), 512, img); //write data from buffer, into new file.
                }

                else  // and there is an existing jpg
                {
                    fclose(img); // close file
                    // (3A) Call jpgname file function
                    jpgcounter++;
                    sprintf(filename, "%03i.jpg", (jpgcounter - 1));
                    img = fopen(filename, "w");
                    fwrite(BUFFER, sizeof(BYTE), 512, img); //write data from buffer, into new file.
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



