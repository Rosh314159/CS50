#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
#include <math.h> 

int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open\n");
        return 1;
    }
    
    char filename[8];
    FILE *current_output;
    FILE *prev_output;
    BYTE buffer[512];
    int counter = 0;
    while (true)
    {
        
        fread(buffer, sizeof(BYTE), 512, file);
         if (feof(file) != 0)
        {
            
            break;
        }
        if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0)))
        {
            
            if (counter == 0)
            {
                sprintf(filename, "%03i.jpg", counter);
                current_output = fopen(filename, "a");
                fwrite(buffer, sizeof(BYTE), 512, current_output);
                
            }
            else
            {
                fclose(current_output);
                sprintf(filename, "%03i.jpg", counter);
                current_output = fopen(filename, "a");
                fwrite(buffer, sizeof(BYTE), 512, current_output);
            }
            counter += 1;
        }
        else if (counter > 0)
        {
            fwrite(buffer, sizeof(BYTE), 512, current_output);
        }
       
    }
}