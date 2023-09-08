// TO DO.  Created a function for jpeg check as well as creating Jpeg file. But can't seem to get the name of the file to leave the function. Read up on pointers to see how we do that.


#include <cs50.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


// defining a 'BYTE' as 8 bits, 'utin8_t' for easier usage.
typedef uint8_t BYTE;
// declaring an array of blocks of 512 *BYTEs, used for reading data from image into a buffer for analysis.
BYTE BUFFER[512];
// # Do i need to use malloc to declare 512 bytes of memory for storage?#



// Function prototypes
void readimagetobuffer(void); // not sure if I need a function here.
bool jpegcheck(int buffer0, int buffer1, int buffer2, int buffer3); //jpeg check function
int jpegcreate (char *filename, int jpegcounter); // function to create file, with filename






int main(int argc, char *argv[])
{


// SETTING UP VARIABLES
// jpeg counter, for naming of jpeg files.
int jpegcounter = 0;
// char array for file name
char filename[7]; // create array for filename



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
    printf("Not a file. Program terminated\n");
    return 1;
}




/// Reading data from raw image 'file' into BUFFER, 512 * BYTES
{
int bytesread = 0;
bytesread = fread(BUFFER, sizeof(BYTE), 512, file);
printf ("Number of BYTES read: %i\n", bytesread);  // Temp to track, delete print later.
}


// Jpegcheck function
{
    if (jpegcheck(BUFFER[0], BUFFER[1], BUFFER[2], BUFFER[3]))
    {
        jpegcounter++;
        printf("yes, jpeg\n");
        printf("jpegcounter: %i\n", jpegcounter);
    }
    else
    {
        printf("no, jpeg\n");
    }
}

if (jpegcounter > 0) // note, set at if jpeg > 0 for now just to trigger the function,

// Jpegcreate file function
{
    jpegcreate(filename, jpegcounter);  //No need to pass in address of filename. As it is an array, it is already passing in the address!
    {
        printf("Function Working\n Name of file is: %s\n", filename); // printfcheck
    }
}

// Write Jpeg file - 512 block from buffer to jpeg file.
{
    fwrite(BUFFER, sizeof(BYTE), 512, img); //write data from buffer, into new file.
    // ##Insert a counter here?
}














// #fread#
// https://manual.cs50.io/3/fread
// The opened file “remembers” the number of bytes that were successfully read, such that subsequent calls to this function for stream will return bytes after those already read.



// Checking first four BYTES of data in buffer to determine if file is the beginning of a jpeg
// ## Currently using a for loop, but this probably isn't necessary at the moment##
//    int i = 0;
//    for (i = 0; i < sizeof(file); i++)


// Reading from file for blocks of 512 BYTES (and printing it)
// fread(BUFFER, sizeof(BYTE), 512, file);

// int i = 0;
// for (i = 0; i < sizeof(BUFFER); i++)
// {
 //   printf("%i, ", BUFFER[i]);
// }










fclose(file);

}



            // Also, the action at this point should
            // ##- create a new name for a jpeg file - CHECK
            // ##- create a new jpeg file.- CHECK
            // ##- copy data from the buffer to the new file in the first block. CHECK
            // ##- check data for jpeg in the next block. HOW?
            // ## If jpeg header in new file, then close off existing file, create a new file.
            // ## if not jpeg header, then copy.
                // Or do you look for series of 000000s to determine if file is ended?

             // ## How do I know how big the file you are opening in fopen should be?
             // Do i need to declare it with malloc



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



// Dynamic Memory allocation - we may need to use dynamic memory allocation because we don't know how much memory we will need at compilation.
// i.e the size of each jpeg!
// malloc(size of future(type/jpeg))
// maybe the size of mem allocation would be (512 Bytes * no. of blocks in pic)?


// FUNCTION DEFINITIONS


bool jpegcheck(int buffer0, int buffer1, int buffer2, int buffer3)
{
    if (BUFFER[0] == 0xff && BUFFER[1] == 0xd8 && BUFFER[2] == 0xff && (BUFFER[3] & 0xf0) == 0xe0)
// you could use a while loop?  While 'BUFFER' meets condition, then step 1, create file, copy file.
// Or maybe, if it meets condition, then trigger a while loop that copies data over until a new jpeg is found?
    {
    printf("Function - Possible Jpeg beginning at byte BUFFER[0]!\n");

    printf("%i:\n", BUFFER[0]); // using 0-3 instead of i-(i+3)
    printf("%i:\n", BUFFER[1]);
    printf("%i:\n", BUFFER[2]);
    printf("%i:\n", BUFFER[3]);
    printf("Function - Next step, copy buffer into new image.\n");


    // jpegcounterr++; // Adds 1 to jpegcounter for file naming.
    //printf("jpegcounter: %i\n", jpegcounter);
   return 1;
    }
    else
    return 0;
}



int jpegcreate(char *filename, int jpegcounter)
{

// char filename[7]; // create array for filename
sprintf(filename, "%03i.jpg", jpegcounter); // create filename, with jpegnumber denoting no#

// printf("Function - Name of file is: %s\n", filename); // printfcheck
FILE *img = fopen(filename, "w"); // open new file with filename
return 1;

}