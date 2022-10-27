// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

typedef uint8_t b;
typedef int16_t a;

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
    b header[HEADER_SIZE]; //declaration of header
    fread(header, sizeof(uint8_t), HEADER_SIZE, input); //it reads input in header file,
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output); //it writes input in header file,



    // TODO: Read samples from input file and write updated data to output file
    a buffer; //declaration of buffer
    while (fread(&buffer, sizeof(int16_t), 1, input))  //reads input in buffer untill it will be equel 16 bites (2 bytes)
    {
        buffer = buffer * factor; //multply factor by 2
        fwrite(&buffer, sizeof(int16_t), 1, output);  //writes input in buffer untill it will be equel 16 bites (2 bytes)
    }


    // Close files
    fclose(input);
    fclose(output);
}
