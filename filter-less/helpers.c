#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    /*loop through each row*/
    for (int i = 0; i < height; i++)
    {
        /*loop for each pixel*/
        for (int j = 0; j < width; j++)
        {
            /*calculate the average of bit colors*/
            avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            /*update new values for filter*/
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    /*intialize temporary bit colors*/
    int tmpb, tmpg, tmpr;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            /*calculate for sepia*/
            tmpb = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));
            tmpg = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
            tmpr = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));

            /*update bit colors, if greater that 255; bit color equals 255*/
            if (tmpb > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = tmpb;
            }
            if (tmpg > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = tmpg;
            }
            if (tmpr > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = tmpr;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    /*create a temporary container for image pixels*/
    RGBTRIPLE tmp;

    /*reflect image*/
    for (int i = 0; i < height; i++)
    {
        int last_pos = width - 1;
        for (int j = 0; j < width / 2; j++)
        {
            tmp = image[i][j];
            image[i][j] = image[i][last_pos];
            image[i][last_pos] = tmp;
            last_pos--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    
    return;
}
