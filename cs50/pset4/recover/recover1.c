#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


// defining a 'BYTE' as 8 bits, 'utin8_t' for easier usage.
typedef uint8_t BYTE;

BYTE BUFFER[512]; // declaring an array of blocks of 512 *BYTEs, used for reading image from data.


int main(int argc, char *argv[])
{
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
    printf("Not a file. Not sure why this isn't working!\n");  // ##delete later. remember to close file evenutally
    return 1;
}

if (file != NULL)
{
    printf("File successfully opened!\n");  // ##prob superfluous . delete later.
}




// Making a copy of the file, into an array, so the bytes are addressable

// BYTE copy[] - I don't think I can do this as I can't find out the size of the file based on current knowledge.....




// ## To do.## <<<<>>><<<<Consider making jpeg check a sep function.
// make a jpeg check array called 'jchk', size of 4 BYTEs

BYTE jchk[4];

BYTE *chk1byte = malloc(sizeof(uint8_t) * 512);


// setting jpeg counter, for naming of jpeg files.
int jpegcounter = 0;

/// Checking BUFFER for jpeg header
{
fread(BUFFER, sizeof(BYTE), 512, file);

//fread returns how many elements it reads. If it less than 255, then the file is finished.
//how do I found out how many elements it reads?

    int i = 0;
    for (i = 0; i < sizeof(file); i++)
    {
        if (BUFFER[i] == 0xff && BUFFER[i + 1] == 0xd8 && BUFFER[i + 2] == 0xff && (BUFFER[i +3] & 0xf0) == 0xe0)
        // you could use a while loop?  While 'BUFFER' meets condition, then step 1, create file, copy file.
        // Or maybe, if it meets condition, then trigger a while loop that copies data over until a new jpeg is found?
        {
            printf("Possible Jpeg beginning at byte BUFFER[%i]!\n", i);

            printf("%i:\n", BUFFER[0]); // using 0-3 instead of i-(i+3)
            printf("%i:\n", BUFFER[1]);
            printf("%i:\n", BUFFER[2]);
            printf("%i:\n", BUFFER[3]);
            printf("Next step, copy buffer into new image.\n");

            jpegcounter++;

            // Also, the action at this point should
            // - create a new name for a jpeg file
            // - create a new jpeg file.
            // - copy data from the buffer to the new file in the first block.
            // - check data for jpeg in the next block.
            // If jpeg header in new file, then close off existing file, create a new file.
            // if not jpeg header, then copy.
                // Or do you look for series of 000000s to determine if file is ended?

                char filename[7]; // create array for filename

                sprintf(filename, "%03i.jpg", jpegcounter); // create filename, with jpegnumber denoting no#

                printf("Name of file is: %s\n", filename);

FILE *img = fopen(filename, "w");

fwrite(BUFFER, sizeof(BYTE), 512, img);



            return 1;
        }
    }
}



// Read file that is opened, store 4 bytes in jchk array (from 2:21 of lecture vid/notes on file)

// Note, is it better to just search for the first value of a file that is == to oxff and then check the first 4 bytes after that?
// So iterate through each byte, when ([i]th byte == [0xff]), then use jchk to look at [i], [i +1], [i+2] and [i+3} bytes?

fread(jchk, sizeof(BYTE), 4, file);

// Check first four BYTES
if (jchk[0] == 0xff && jchk[1] == 0xd8 && jchk[2] == 0xff && (jchk[3] & 0xf0) == 0xe0)
{
    printf("Jpeg!\n");
    printf("%i:\n", jchk[0]);


}

else
{
    printf("No jpeg in selected block\n");
    // return 1; // prob more relevant if this is a separate function.
}
printf("%i:\n", jchk[0]);
printf("%i:\n", jchk[1]);
printf("%i:\n", jchk[2]);
printf("%i:\n", jchk[3]);



// Reading from file for blocks of 512 BYTES (and printing it)
fread(BUFFER, sizeof(BYTE), 512, file);

int i = 0;
for (i = 0; i < sizeof(BUFFER); i++)
{
 //   printf("%i, ", BUFFER[i]);
}






// Check that image is a jpeg [DONE]
// This check is part of the longer check I think, checking first 4 bytes. [DONE]
// return 1; if it isn't a jpeg

// Open Memory Card file

// Look for Jpeg

// Open a new Jpeg
//Create file name


// Write bytes until a Jpeg a new jpeg is found.

// See Pseduo Code from walk through to plan it better





//

// Dynamic Memory allocation - we may need to use dynamic memory allocation because we don't know how much memory we will need at compilation.
// i.e the size of each jpeg!
// malloc(size of future(type/jpeg))
// maybe the size of mem allocation would be (512 Bytes * no. of blocks in pic)?

fclose(file);

}


//Pseudocode
// Open Memory Card
// Repeat [some proceess]  until end of card
//   - Read 512 bytes into a buffer
//     Look at 512 buffer,
        // If start of new jpeg
           // If first jpeg
           //   . .
           // Else
           // ...
    // Else
    // If already found jpeg
    //... keep writing.
    // Close any open files