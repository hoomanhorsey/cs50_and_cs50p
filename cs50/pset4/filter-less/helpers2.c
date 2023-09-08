#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

int i = 0;
int j = 0;
float grey = 0;

for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
           {
                grey = ((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3);
                grey = round(grey);
                image[i][j].rgbtBlue = grey;
                image[i][j].rgbtGreen = grey;
                image[i][j].rgbtRed = grey;
            }
    }
    return;
}

void sepia(int height, int width, RGBTRIPLE image[height][width])

{
int i = 0;
int j = 0;
float sepiaRed = 0;
float sepiaGreen = 0;
float sepiaBlue = 0;
int originalRed;  // Creating placeholder ints, as the formula
int originalBlue;
int originalGreen;

for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
           {
            sepiaRed = (.393 * image[i][j].rgbtRed) + (.769 * image[i][j].rgbtGreen) + (.189 * image[i][j].rgbtBlue);
            sepiaRed = round(sepiaRed);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            sepiaGreen = (.349 * image[i][j].rgbtRed) + (.686 * image[i][j].rgbtGreen) + (.168 * image[i][j].rgbtBlue);
            sepiaGreen = round(sepiaGreen);

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            sepiaBlue = (.272 * image[i][j].rgbtRed) + (.534 * image[i][j].rgbtGreen) + (.131 * image[i][j].rgbtBlue);
            sepiaBlue = round(sepiaBlue);

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
           }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

int i = 0;
int j = 0;
int k = 0;
int l = 0;

typedef struct
{
    BYTE  rgbtBlue;
    BYTE  rgbtGreen;
    BYTE  rgbtRed;
} __attribute__((__packed__))

bufferstruct;

bufferstruct tempimage[height][width];

for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
           {
            tempimage[i][width - (1 + j)].rgbtRed = image[i][j].rgbtRed;
            tempimage[i][width - (1 + j)].rgbtGreen = image[i][j].rgbtGreen;
            tempimage[i][width - (1 + j)].rgbtBlue = image[i][j].rgbtBlue;
           }
    }

for (k=0; k < height; k++)
{
    for (l = 0; l < width; l++)
    {
        image[k][l].rgbtRed = tempimage[k][l].rgbtRed;
        image[k][l].rgbtGreen = tempimage[k][l].rgbtGreen;
        image[k][l].rgbtBlue = tempimage[k][l].rgbtBlue;
    }
}

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
