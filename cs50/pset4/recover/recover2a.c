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
int jpegname (char *filename, int jpegcounter); // function to create file, with filename

// MAIN
int main(int argc, char *argv[])
{

// setting jpeg counter, for naming of jpeg files.
int jpegcounter = 0;
// blocks read counter
int blockcount = 0;

// creating char array for file name
char filename[7]; // create array for filename
// constant for jpeg numbers
const int JPEGS = 51;

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
    printf("Not a file. Not sure why this isn't working!\n");  // ##delete later. remember to close file evenutally
    return 1;
}
//##prob superfluous . delete later.##
if (file != NULL)
{
    // printf("File successfully opened!\n"); #delete later#
}


/// (1) READING DATA INTO BUFFER

{
    int i = 0;
    int j = 0;

    for (i = 0; i < JPEGS; i++)
    {
        // (2) Read 512 blocks into buffer
        {
            int bytesread = 0;
            bytesread = fread(BUFFER, sizeof(BYTE), 512, file);
            printf ("Number of BYTES read: %i\n", bytesread);
            blockcount++;
            printf ("blockcount: %i\n", blockcount);
            printf ("\n");
        }

        //  (3) Call jpegcheck function
        // for (j = 0; j < i; j++)

        {
            {
                if (jpegcheck(BUFFER[0], BUFFER[1], BUFFER[2], BUFFER[3])) // If jpeg is found
                {
                    if (jpegcounter == i) // check for jpeg, no jpeg

                    // (3A) Call Jpegname file function
                    {
                        jpegcounter++;
                        jpegname(filename, jpegcounter);  //No need to pass in address of filename. As it is an array, it is already passing in the address!
                        {
                            printf("Jpeg found, filename created is %s\n", filename); // print check
                            printf ("\n");
                        }

                    }
                     // Can put file create here and it works

                    else  // existing jpeg (!jpeg counter = 0), note, or should be jpegcounter !0 as well as not equal to some other jpeg counter.
                    {
                        if (jpegcounter > i)

                        // Function to close file
                        {
                            fclose(file); //##BUT I THINK IT SHOULD BE 'img' that is the file being closed.
                            printf("File closed!");// but which file?
                        }
                        // Then Jpeg create function // shoulb e able to skp the write function, and loop it back to go , or swap the order??
                        {
                            jpegcounter++;
                            jpegname(filename, jpegcounter);  //No need to pass in address of filename. As it is an array, it is already passing in the address!
                            {
                                printf("Function Working\n Name of file is: %s\n", filename); // printfcheck
                            }
                        }
                            return 1; // skips to Write function
                    }

                }

                else

                {
                    if (!(jpegcheck(BUFFER[0], BUFFER[1], BUFFER[2], BUFFER[3]))) // If no jpeg is found
                    {
                        // no existing jpeg
                        if (jpegcounter == i)
                            {
                                printf("No Jpeg found, no jpeg file yet, back to buffer\n");
                                printf("Counter i: %i\n", i);
                            }
                        else
                            {                      // existing jpeg
                                if (jpegcounter > i)
                                continue;// return 1; // skips to Write function
                                printf ("still cruising\n");

                            }
                    }
                }

                // Open jpegfile and write buffer, consider turning into function

                // (4) Open jpeg file
                FILE *img = fopen(filename, "w"); // open new file with filename
                printf("file created\n");


                // (5) Write buffer to jpeg file
                fwrite(BUFFER, sizeof(BYTE), 512, img); //write data from buffer, into new file.
                printf("512 blocks written\n");
                printf ("\n");

        }

    }// End of Key function

fclose(file);


}
}
}
//END OF MAIN


// FUNCTION DEFINITIONS

bool jpegcheck(int buffer0, int buffer1, int buffer2, int buffer3)
{
    if (BUFFER[0] == 0xff && BUFFER[1] == 0xd8 && BUFFER[2] == 0xff && (BUFFER[3] & 0xf0) == 0xe0)
    {
        printf("Function jpegcheck - Working!\n");
        printf ("\n");

        // printf("%i:\n", BUFFER[0]); // using 0-3 instead of i-(i+3)
        // printf("%i:\n", BUFFER[1]);
        // printf("%i:\n", BUFFER[2]);
        // printf("%i:\n", BUFFER[3]);

        return 1;
    }

    else
    return 0;
}



int jpegname(char *filename, int jpegcounter)
{

// char filename[7]; // create array for filename
sprintf(filename, "%03i.jpg", jpegcounter); // create filename, with jpegnumber denoting no#

// printf("Function - Name of file is: %s\n", filename); // printfcheck
// FILE *img = fopen(filename, "w"); // open new file with filename
return 1;

}





//##fread now returns how many elements it reads, which it prints as n.
//how do I found out how many elements it reads?

// Checking first four BYTES of data in buffer to determine if file is the beginning of a jpeg
// ## Currently using a for loop, but this probably isn't necessary at the moment##
//    int i = 0;
//    for (i = 0; i < sizeof(file); i++)


//    {
//        if (BUFFER[0] == 0xff && BUFFER[1] == 0xd8 && BUFFER[2] == 0xff && (BUFFER[3] & 0xf0) == 0xe0)
        // you could use a while loop?  While 'BUFFER' meets condition, then step 1, create file, copy file.
        // Or maybe, if it meets condition, then trigger a while loop that copies data over until a new jpeg is found?
//        {
//            printf("Possible Jpeg beginning at byte BUFFER[0]!\n");

//            printf("%i:\n", BUFFER[0]); // using 0-3 instead of i-(i+3)
//            printf("%i:\n", BUFFER[1]);
//            printf("%i:\n", BUFFER[2]);
//            printf("%i:\n", BUFFER[3]);
//            printf("Next step, copy buffer into new image.\n");

//            jpegcounter++; // Adds 1 to jpegcounter for file naming.

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





// #fread#
// https://manual.cs50.io/3/fread
// The opened file “remembers” the number of bytes that were successfully read, such that subsequent calls to this function for stream will return bytes after those already read.





// Reading from file for blocks of 512 BYTES (and printing it)
// fread(BUFFER, sizeof(BYTE), 512, file);

// int i = 0;
// for (i = 0; i < sizeof(BUFFER); i++)
// {
 //   printf("%i, ", BUFFER[i]);
// }





//

// Dynamic Memory allocation - we may need to use dynamic memory allocation because we don't know how much memory we will need at compilation.
// i.e the size of each jpeg!
// malloc(size of future(type/jpeg))
// maybe the size of mem allocation would be (512 Bytes * no. of blocks in pic)?





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