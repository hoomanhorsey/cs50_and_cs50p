#include "helpers.h"
#include <math.h>
#include <stdio.h>

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

// typedef struct  // Create new array 'copy' made up of 'RGBTRIPLE' struct types.
// {
//     BYTE  rgbtBlue;
//    BYTE  rgbtGreen;
//    BYTE  rgbtRed;
//} __attribute__((__packed__))

//RGBTRIPLE;
// An array of RGBTRIPLEs to store copies of the image, to be modified by the blur algo.

RGBTRIPLE copy[height][width];

for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
           {
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
           }
    }

int buffer;

 while (fread(&buffer, sizeof(int), 1, copy[i][j].rgbtRed))
    {
        // the item in buffer by the 'factor'
        // buffer *= factor;

        fwrite(&buffer, sizeof(int), 1, image[i][j].rgbtRed);
    }




int k = 0;
int l = 0;
int m = 0;
int n = 0;

int averagepixels = 0;
int sum = 0;
double averagepix = 0;
int counter = 0;

// Loop by height (k = rows), then by width (l = each column), then 'm' and 'n' are the 3x3 squares around each pixel

{
// Red
for (k=0; k < height; k++)
    {
    for (l = 0; l < width; l++)
        {
            counter = 0;

            for (m = -1; m < 2; m++)
            {
                for (n = -1; n < 2; n++)
                    {
                        if ((image[m][n].rgbtRed < 0) || (image[m][n].rgbtRed > 255)) // if the relevant pixel is 'null' then it is not counted
                            {
                                counter++; // each 'null' pixel is counted, to be subtracted from the average
                            }
                        else       // otherwise it's value is added to the sum
                        sum += image[m][n].rgbtRed;
                    }
            }
            image[m][n].rgbtRed = round(sum / (9.0 - counter));
        }
    }
}


    return;
}



// Blue
//for (k=0; k < height; k++)
//    {
//    for (l = 0; l < width; l++)
//        {
//            counter = 0;

//            for (m = -1; m < 2; m++)
//            {
//                for (n = -1; n < 2; n++)
 //                   {
  //                      if ((image[m][n].rgbtBlue < 0) || (image[m][n].rgbtBlue > 255)) // if the relevant pixel is 'null' then it is not counted
   //                         {
    //                            counter++; // each 'null' pixel is counted, to be subtracted from the average
     //                       }
      //                  else       // otherwise it's value is added to the sum
       //                 sum += image[m][n].rgbtBlue;
        //            }
 //           }
  //          image[m][n].rgbtBlue = round(sum / (9.0 - counter));
   //     }
 //   }
//}
