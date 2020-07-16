#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avr;
    for (int i = 0; i < height; i++) 
    {
        for (int j = 0; j < width; j++)
        {
           avr = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3);
           image[i][j].rgbtRed = avr;
           image[i][j].rgbtGreen = avr;
           image[i][j].rgbtBlue = avr;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sRed, sGreen, sBlue;
    for (int i = 0; i < height; i++) 
    {
        for (int j = 0; j < width; j++)
        {
           sRed = round(.393 * image[i][j].rgbtRed 
                                        + .796 * image[i][j].rgbtGreen 
                                        + .189 * image[i][j].rgbtBlue);
           sGreen =  round(.393 * image[i][j].rgbtRed 
                                        + .686 * image[i][j].rgbtGreen 
                                        + .168 * image[i][j].rgbtBlue);
           sBlue =  round(.272 * image[i][j].rgbtRed 
                                        + .534 * image[i][j].rgbtGreen 
                                        + .131 * image[i][j].rgbtBlue);
            if (sRed > 255)
            {
                image[i][j].rgbtRed = 255;
            } else
            {
                image[i][j].rgbtRed = sRed;
            }
            if (sGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            } else
            {
                image[i][j].rgbtGreen = sGreen;
            }
            if (sBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            } else
            {
                image[i][j].rgbtBlue = sBlue;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int rRed, rGreen, rBluer;
    RGBTRIPLE tmp;
    for (int i = 0; i < height; i++) 
    {
        for (int j = 0; j < width / 2; j++)
        {
            tmp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    
    return;
}
