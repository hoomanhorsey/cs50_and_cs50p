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

// typedef struct  // Create new array 'copy' made up of 'RGBTRIPLE' struct types.
// {
//     BYTE  rgbtBlue;
//    BYTE  rgbtGreen;
//    BYTE  rgbtRed;
//} __attribute__((__packed__))

//RGBTRIPLE;
// An array of RGBTRIPLEs to store copies of the image, to be modified by the blur algo.

RGBTRIPLE copy[height][width];
{
int i = 0;
int j = 0;

for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
           {
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
           }
    }
}

{
// Modifying the pixel
// If in copy[i][j].rgbtRed, (i < 0) || (j < 0) || (i > height) || (i > width) ||, then pixel does not qualify
int i = 0;
int j = 0;
int k = 0;
int l = 0;
int counter = 0;
int noncounter = 0;
int test = 0;



for (i = 0; i < height; i++)   // looping height/row, width/column
    {
        for (j = 0; j < width; j++)

            {
                noncounter = 0;
                counter = 0;

                



                for (k = 0; k < 3; k++)   // looping over each pixel
                    {
                        for (l = 0; l < 3; l++)
                            {

                             // if ((image[k > 0][l].rgbtRed) && (image[k][l > 0 ].rgbtRed) && (image[k < (height + 1)][l].rgbtRed) && (image[k][l < (width + 1)])

                                 // test for k + l to see if they are disqualified.


                                  // what can you use to make k negative?
                                  //image[k - 1][l - 1].rgbtRed

                                  // something like, if ((image[k - 1][l - 1].rgbtRed) < 0 || ((image[k + 1][l + 1].rgbtRed))> height and width)
                                int k_zerotest = 0;
                                int k_heighttest = 0;
                                int l_zerotest = 0;
                                int l_widthtest = 0;

                                k_zerotest = (k - 1);           // ** THESE VALUES ARE STILL TIED TO THE INNERMOST LOOPS, AND NOT positions I and J.
                                k_heighttest = (height - 1);
                                l_zerotest = (l - 1);
                                l_widthtest = (width - 1);

                                printf("k_zerotest:%i\n", k_zerotest);
                                printf("k_heighttest:%i\n", k_heighttest);
                                printf("l_zerotest:%i\n", l_zerotest);
                                printf("l_widthtest:%i\n", l_widthtest);

                                if (k_zerotest >= i && k_heighttest <= height && l_zerotest >= j && l_widthtest <= width)

                                // if (k >= i && k <= height && l >= j && l <= width)  // referring to the values in the very first loop, 'i' and 'j', which are the beginnings of the image, and height and width, the end.

                                    {
                                         counter++;
                                         copy[k][l].rgbtRed += image[k - 1][l - 1].rgbtRed;
                                         copy[k][l].rgbtBlue += image[k - 1][l - 1].rgbtBlue;
                                         copy[k][l].rgbtGreen += image[k - 1][l -1].rgbtGreen;
                                    }

                            }

                     printf("counter:%i\n", counter);

                        }

                    // printf("%i\n", noncounter);
                    // printf("%i\n", counter);
                    copy[k][l].rgbtRed = (copy[k][l].rgbtRed / counter);
                    copy[k][l].rgbtBlue = (copy[k][l].rgbtBlue / counter);
                    copy[k][l].rgbtGreen = (copy[k][l].rgbtGreen / counter);
            }
    }
}
{


    return;
}
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
