/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>


#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }
    
    // remember factor n
    int n = atoi(argv[1]);
    
    // ensure proper n
    if (n > 100 || n < 0)
    {
        printf("n must be a positive integer less than or equal to 100\n");
        return 2;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }
    
    
    int paddingIn =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    
    int width = bi.biWidth;
    int height = bi.biHeight;
    
    
    bi.biWidth = bi.biWidth * n;
    bi.biHeight = bi.biHeight * n;
    
    
    int paddingOut =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    
    bi.biSizeImage = (bi.biWidth * sizeof(RGBTRIPLE) + paddingOut) * abs(bi.biHeight);
    bf.bfSize = bi.biSizeImage + 54;
    

    
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);


    
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    
    for (int i = 0, biHeight = abs(height); i < biHeight; i++)
    {
    
        
        long positionIn = ftell(inptr);
        
        for (int k = 0; k < n; k++)
        {
        
            
            fseek(inptr, positionIn, SEEK_SET);
            
            
            for (int j = 0; j < width; j++)
            {
                
                RGBTRIPLE triple;

                
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);  
                    
                for (int m = 0; m < n; m++)
                {
                    
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
            
       

            
            fseek(inptr, paddingIn, SEEK_CUR);

            
            for (int k = 0; k < paddingOut; k++)
            {
                fputc(0x00, outptr);
            }
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}