#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) //iteration over image rows
    {
        for (int j = 0; j < width; j++) //iteration over image columns
        {

            float p = image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;
            float av = ((round)(p / 3));

            //setting calculated sum to be new value of each pixel
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = av;

        }
    }

    return;
}


int box(int rgb)
{
if(rgb > 255)
{
    rgb = 255;
}
return rgb;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    //float sepiaRed, sepiaGreen, sepiaBlue;

    for(int i = 0; i < height; i++)
    {
        for( int j = 0; j < width; j++)
        {
            float sepiaRed, sepiaGreen, sepiaBlue;

             sepiaRed = box(round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue));
             sepiaGreen = box(round( 0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue));
             sepiaBlue = (round( 0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue));



            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;

        }
    }

   return;
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width / 2; j++)
        {

            RGBTRIPLE tem = image[i][j];


            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = tem;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tem[height][width];


    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            float tGreen = 0;
            float tRed = 0;
            float tBlue = 0;

            float average = 0.0;

            for(int x = -1; x < 2; x++)
            {
                for(int k = -1; k < 2; k++)
                {
                    int withi = i + x;
                    int withj = j + k;
                    if(withi < 0 || withi > height -1 || withj < 0 || withj > width -1)
                    {
                       continue;
                    }

                    tGreen += image[i+x][j+k].rgbtGreen;
                    tRed += image[i+x][j+k].rgbtRed;
                    tBlue += image[i+x][j+k].rgbtBlue;

                    average++;
                }

            }

            tem[i][j].rgbtGreen = round(tGreen / average);
            tem[i][j].rgbtRed = round(tRed / average);
            tem[i][j].rgbtBlue = round(tBlue / average);
        }
    }


    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j].rgbtGreen = tem[i][j].rgbtGreen;
            image[i][j].rgbtRed = tem[i][j].rgbtRed;
            image[i][j].rgbtBlue = tem[i][j].rgbtBlue;
        }
    }
    return;
}