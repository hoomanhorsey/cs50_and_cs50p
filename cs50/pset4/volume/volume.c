// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

// TODO: Copy header from input file to output file
// Declaring an array 'header', made up of 1 byte 'uint8_t' elements, for 44 bytes (header size)

    uint8_t header[HEADER_SIZE];

// Use 'fread' to read bytes from input and place into header array.
// Then use fwrite to take bytes from header array and write into  output file
// Note, size is number of total bytes to type.  So nmeb is 1 byte, and you want 44 of them, represented by the constant 'HEADER_SIZE'

    fread(header, HEADER_SIZE, 1, input);

    fwrite(header, HEADER_SIZE, 1, output);

// TODO: Read samples from input file and write updated data to output file

// Use uint16_t as the relevant size (2 bytes).
// create a 'buffer' by declaring the type int16_t and naming it 'buffer'
// Use a while loop to read each sample, multipy by the factor, then write each sample

    int16_t buffer;

    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        //function to multiply the item in buffer by the 'factor'
        buffer *= factor;

        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
