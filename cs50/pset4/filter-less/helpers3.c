#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

int i = 0;
int j = 0;
double grey = 0;

for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
           {
                grey = ((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3.0);
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

for (i = 0; i < height; i++)
{
    for (j = 0; j < (trunc(width / 2)); j++)

        {
            int Rtmp = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width - (1 + j)].rgbtRed;
            image[i][width - (1 + j)].rgbtRed = Rtmp;

            int Gtmp = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width - (1 + j)].rgbtGreen;
            image[i][width - (1 + j)].rgbtGreen = Gtmp;

            int Btmp = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width - (1 + j)].rgbtBlue;
            image[i][width - (1 + j)].rgbtBlue = Btmp;
        }

}




    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
int i = 0;
int j = 0;
int k = -1;
int l = -1;

int averagepixels = 0;
int sum = 0;
double averagepix = 0;
int counter = 0;

{
// Loop by height (i = rows), then by width (j = each column), then 'k' and 'l' are the 3x3 squares around each pixel

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            counter = 0;  // 'k' and 'l' start at -1, as they are 1 pixel before the pixel that is being looped

            for (k = -1; k < 2; k++)
            {
                for (l = -1; l < 2; l++)
                    {
                        if (image[k][l].rgbtRed == 0) // if the relevant pixel is 'null' then it is not counted
                            {
                                counter++; // each 'null' pixel is counted, to be subtracted from the average
                            }
                        else       // otherwise it's value is added to the sum
                        sum += image[k][l].rgbtRed;
                    }
            }
            averagepix = round(sum / (9.0 - counter));
            image[k][l].rgbtRed = averagepix;
        }
    }
}


    return;
}



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