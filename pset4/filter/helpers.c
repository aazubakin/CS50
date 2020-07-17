#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avr;
    for (int i = 0; i < height; i++) 
    {
        for (int j = 0; j < width; j++)
        {
            avr = ((image[i][j].rgbtRed 
                    + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = round(avr);
            image[i][j].rgbtGreen = round(avr);
            image[i][j].rgbtBlue = round(avr);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sRed, sGreen, sBlue;
    for (int i = 0; i < height; i++) 
    {
        for (int j = 0; j < width; j++)
        {
            //formula for sopia filter
            sRed = (.393 * image[i][j].rgbtRed 
                    + .769 * image[i][j].rgbtGreen 
                    + .189 * image[i][j].rgbtBlue);
            sGreen = (.349 * image[i][j].rgbtRed 
                      + .686 * image[i][j].rgbtGreen 
                      + .168 * image[i][j].rgbtBlue);
            sBlue = (.272 * image[i][j].rgbtRed 
                     + .534 * image[i][j].rgbtGreen 
                     + .131 * image[i][j].rgbtBlue);
            //checks if value more than 255
            if (sRed > 255)
            {
                image[i][j].rgbtRed = 255;
            } 
            else
            {
                image[i][j].rgbtRed = round(sRed);
            }
            if (sGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            } 
            else
            {
                image[i][j].rgbtGreen = round(sGreen);
            }
            if (sBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            } 
            else
            {
                image[i][j].rgbtBlue = round(sBlue);
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
        for (int j = 0; j < width / 2; j++) //needs only half of width 
        {
            //swap pixels 
            tmp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = tmp;
        }
    }
    return;
}

// Blur image
// define 9 pixel around of every pixel, exept coreners and last lines
// return average of color what is recieved in RGB
int blurpixel(int i, int j, int height, int width, RGBTRIPLE image[height][width], int RGB)
{
    int color = 0;
    float counter = 0;
    //loops for 9 pixels of each pixel
    for (int a = i - 1; a <= i + 1; a++)
    {
        for (int b = j - 1; b <= j + 1; b++)
        {
            //cheks if outside of image
            if (a >= 0 && a < height && b <  width && b >= 0)
            {
                if (RGB == 0)
                {
                    color = color + image[a][b].rgbtRed;
                } 
                else if (RGB == 1)
                {
                    color += image[a][b].rgbtGreen;
                } 
                else 
                {
                    color += image[a][b].rgbtBlue;
                }
                counter++;
            }
        }
    }
    return round(color / counter); // return average number of each color
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copyImage[height][width];
    for (int i = 0; i < height; i++) 
    {
        for (int j = 0; j < width; j++)
        {
            copyImage[i][j] = image[i][j]; // make copy of image
        }
    }

    for (int i = 0; i < height; i++) 
    {
        for (int j = 0; j < width; j++)
        {
            //change original image to blur
            image[i][j].rgbtRed = blurpixel(i, j, height, width, copyImage, 0); 
            image[i][j].rgbtGreen = blurpixel(i, j, height, width, copyImage, 1);
            image[i][j].rgbtBlue = blurpixel(i, j, height, width, copyImage, 2);
        }
    }
    return;
}
