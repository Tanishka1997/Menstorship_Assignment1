/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef uint8_t BYTE;

int main(void)
{
   
    
    FILE* file = fopen("card.raw", "r"); 
    if (file == NULL)
    {
        printf("Could not open card.raw\n");
        return 1;
    }
    BYTE buffer[512];
   int count = 0;
    char* title = malloc(sizeof(char));
    FILE* img = NULL;
    while (fread(&buffer, 512 * sizeof(BYTE), 1, file) == 1)
    {if (buffer[0] == 255 && buffer[1] == 216 && buffer[2] == 255 && (buffer[3] == 224 || buffer[3] == 225))
        {
            if (count != 0)
            {
                
                fclose(img);
            }
            
            count++;
            sprintf(title, "%.3d.jpg", (count - 1));
            img = fopen(title, "w");
            if (img == NULL) 
            {
                printf("could not create jpeg file\n");
                return 2;
            } 
            fwrite(&buffer, 512 * sizeof(BYTE), 1, img);
        }
        else if (count!= 0)
        {
            fwrite(&buffer, 512 * sizeof(BYTE), 1, img);
        }
    }
    
    // close memory card file
    fclose(file);

    // close JPG's file
    fclose(img);

    // that's all folks
    return 0; 
}