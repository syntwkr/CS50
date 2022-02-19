#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

const int BLOCK = 512;
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check for argument count
    if (argc != 2)
    {
        printf("Usage: ./recover filename\n");
        return 1;
    }

    // Open raw in read mode
    FILE *raw = fopen(argv[1], "r");

    // Check for validity of file to open
    if (raw == NULL)
    {
        printf("Cannot open the file.\n");
        return 1;
    }

    // Make a buffer for a block and filename; create the counter for the found files
    BYTE buffer[BLOCK];
    FILE *recovered;
    char filename[8];
    int counter = 0;

    // Search for jpegs until the eof
    while (fread(buffer, BLOCK, 1, raw) != 0)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (counter != 0)
            {
                fclose(recovered);
            }
            sprintf(filename, "%.03i.jpg", counter++);
            recovered = fopen(filename, "w");
            fwrite(buffer, BLOCK, 1, recovered);
        }
        else if (counter > 0)
        {
            fwrite(buffer, BLOCK, 1, recovered);
        }
    }
}