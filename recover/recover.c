#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //declaring variables
    unsigned char buffer[512];
    int img_counter = 0;
    FILE *outfile = NULL;
    char *filename = malloc(8 * sizeof(char));
    //check for only one command line argument
    if (argc != 2)
    {
        printf("input only one file name.\n");
        return 1;
    }
    //check if file passed as argument is valid
    if (!(fopen(argv[1], "r")))
    {
        printf("File not opening, input correct file name.\n");
        return 1;
    }
    //open file
    FILE *infile = fopen(argv[1], "r");

    //iterate through the file
    while (fread(buffer, sizeof(char), 512, infile))
    {
        //check if its a jpeg file in each 512 block
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //give jpeg file a name
            sprintf(filename, "%03i.jpg", img_counter);
            //file that saves jpeg
            outfile = fopen(filename, "w");
            //increment image counter
            img_counter++;
        }
        //check for null file
        if (outfile != NULL)
        {
            //write jpeg into outfile
            fwrite(buffer, sizeof(char), 512, outfile);
        }
    }
    //free allocated memory
    free(filename);
    //close all files
    fclose(infile);
    fclose(outfile);
    return 0;
}
