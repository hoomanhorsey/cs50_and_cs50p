#include "helpers.h"
#include <math.h>
#include <stdio.h>

int test_pixel(int i, int j, int height, int width);

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
//int i = 0;
//int j = 0;

//for (i = 0; i < height; i++)
//    {
//        for (j = 0; j < width; j++)
//           {
//            copy[i][j].rgbtRed = image[i][j].rgbtRed;
//            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
//            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
//           }
//    }
//}

{
// Modifying the pixel
// If in copy[i][j].rgbtRed, (i <= 0) || (j <= 0) || (i >= height) || (i >= width) ||, then pixel does not qualify
// height = 5,    0 1 2 3 4     ,so last column = 4, or height - 1










int i = 0;
int j = 0;

for (i = 0; i < height; i++)   // looping height/row, width/column
    {
        for (j = 0; j < width; j++)

            {
                {
                // red

                copy[i][j].rgbtRed = 0;

                double counter = 0.0;

                int test_i_zero = i;
                int test_i_height = i;
                int test_j_zero = j;
                int test_j_width = j;


// possible function call

int pass = test_pixel(i, j, height, width);

if (pass > 0)
    {
        counter++;
        //then somehow iterate through the additions, but automate it?
        //copy[i][j].rgbtRed += image[i][j - 1].rgbtRed;
    }


                // [i]
                // [i][j - 1]
                if (test_i_zero >= 0 && test_i_height <= (height - 1) && (test_j_zero - 1) >= 0 && (test_j_zero - 1) <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtRed += image[i][j - 1].rgbtRed;
                    }
                // [i][j]
                if (test_i_zero >= 0 && test_i_height <= (height - 1) && test_j_zero >= 0 && test_j_zero <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtRed += image[i][j].rgbtRed;
                    }
                // [i][j + 1]
                if (test_i_zero >= 0 && test_i_height <= (height - 1) && (test_j_zero + 1) >= 0 && (test_j_zero + 1) <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtRed += image[i][j + 1].rgbtRed;
                    }

                // [i - 1]
                // [i - 1][j - 1]
                if ((test_i_zero - 1) >= 0 && (test_i_height - 1) <= (height - 1) && (test_j_zero - 1) >= 0 && (test_j_zero - 1) <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtRed += image[i - 1][j - 1].rgbtRed;
                    }
                // [i - 1][j]
                if ((test_i_zero - 1) >= 0 && (test_i_height - 1) <= (height - 1) && test_j_zero >= 0 && test_j_zero <= (width - 1))
                    {
                               counter++;
                        copy[i][j].rgbtRed += image[i - 1][j].rgbtRed;
                    }
                // [i - 1][j + 1]
                if ((test_i_zero - 1) >= 0 && (test_i_height - 1) <= (height - 1) &&  (test_j_zero + 1) >= 0 && (test_j_zero + 1) <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtRed += image[i - 1][j + 1].rgbtRed;
                    }

                // [i + 1]
                // [i + 1][j - 1]
                if ((test_i_zero + 1) >= 0 && (test_i_height + 1) <= (height - 1) && (test_j_zero - 1) >= 0 && (test_j_zero - 1) <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtRed += image[i + 1][j - 1].rgbtRed;
                    }
                // [i + 1][j]
                if ((test_i_zero + 1) >= 0 && (test_i_height + 1) <= (height - 1) && test_j_zero >= 0 && test_j_zero <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtRed += image[i+ 1][j].rgbtRed;
                    }
                // [i + 1][j + 1]
                if ((test_i_zero + 1) >= 0 && (test_i_height + 1) <= (height - 1) && (test_j_zero + 1) >= 0 && (test_j_zero + 1) <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtRed += image[i+ 1][j + 1].rgbtRed;
                    }

                    // printf("counter Red:%f\n", counter);
                    copy[i][j].rgbtRed = round(copy[i][j].rgbtRed / counter);  // should be 'counter' variable, but can't get it to count yet and so delivers a zero which creates a floating point problem.,so '9' fo rnow.
                }

            {   // Blue

                copy[i][j].rgbtBlue = 0;

                double counter = 0.0;

                int test_i_zero = i;
                int test_i_height = i;
                int test_j_zero = j;
                int test_j_width = j;

                // [i]
                // [i][j - 1]
                if (test_i_zero >= 0 && test_i_height <= (height - 1) && (test_j_zero - 1) >= 0 && (test_j_zero - 1) <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtBlue += image[i][j - 1].rgbtBlue;
                    }
                // [i][j]
                if (test_i_zero >= 0 && test_i_height <= (height - 1) && test_j_zero >= 0 && test_j_zero <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtBlue += image[i][j].rgbtBlue;
                    }
                // [i][j + 1]
                if (test_i_zero >= 0 && test_i_height <= (height - 1) && (test_j_zero + 1) >= 0 && (test_j_zero + 1) <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtBlue += image[i][j + 1].rgbtBlue;
                    }

                // [i - 1]
                // [i - 1][j - 1]
                if ((test_i_zero - 1) >= 0 && (test_i_height - 1) <= (height - 1) && (test_j_zero - 1) >= 0 && (test_j_zero - 1) <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtBlue += image[i - 1][j - 1].rgbtBlue;
                    }
                // [i - 1][j]
                if ((test_i_zero - 1) >= 0 && (test_i_height - 1) <= (height - 1) && test_j_zero >= 0 && test_j_zero <= (width - 1))
                    {
                               counter++;
                        copy[i][j].rgbtBlue += image[i - 1][j].rgbtBlue;
                    }
                // [i - 1][j + 1]
                if ((test_i_zero - 1) >= 0 && (test_i_height - 1) <= (height - 1) &&  (test_j_zero + 1) >= 0 && (test_j_zero + 1) <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtBlue += image[i - 1][j + 1].rgbtBlue;
                    }

                // [i + 1]
                // [i + 1][j - 1]
                if ((test_i_zero + 1) >= 0 && (test_i_height + 1) <= (height - 1) && (test_j_zero - 1) >= 0 && (test_j_zero - 1) <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtBlue += image[i + 1][j - 1].rgbtBlue;
                    }
                // [i + 1][j]
                if ((test_i_zero + 1) >= 0 && (test_i_height + 1) <= (height - 1) && test_j_zero >= 0 && test_j_zero <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtBlue += image[i+ 1][j].rgbtBlue;
                    }
                // [i + 1][j + 1]
                if ((test_i_zero + 1) >= 0 && (test_i_height + 1) <= (height - 1) && (test_j_zero + 1) >= 0 && (test_j_zero + 1) <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtBlue += image[i+ 1][j + 1].rgbtBlue;
                    }

                    // printf("counter Blue:%f\n", counter);
                    copy[i][j].rgbtBlue = round(copy[i][j].rgbtBlue / counter);  // should be 'counter' variable, but can't get it to count yet and so delivers a zero which creates a floating point problem.,so '9' fo rnow.
                }

                {   // green

                copy[i][j].rgbtGreen = 0;

                double counter = 0.0;

                int test_i_zero = i;
                int test_i_height = i;
                int test_j_zero = j;
                int test_j_width = j;

                // [i]
                // [i][j - 1]
                if (test_i_zero >= 0 && test_i_height <= (height - 1) && (test_j_zero - 1) >= 0 && (test_j_zero - 1) <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtGreen += image[i][j - 1].rgbtGreen;
                    }
                // [i][j]
                if (test_i_zero >= 0 && test_i_height <= (height - 1) && test_j_zero >= 0 && test_j_zero <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtGreen += image[i][j].rgbtGreen;
                    }
                // [i][j + 1]
                if (test_i_zero >= 0 && test_i_height <= (height - 1) && (test_j_zero + 1) >= 0 && (test_j_zero + 1) <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtGreen += image[i][j + 1].rgbtGreen;
                    }

                // [i - 1]
                // [i - 1][j - 1]
                if ((test_i_zero - 1) >= 0 && (test_i_height - 1) <= (height - 1) && (test_j_zero - 1) >= 0 && (test_j_zero - 1) <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtGreen += image[i - 1][j - 1].rgbtGreen;
                    }
                // [i - 1][j]
                if ((test_i_zero - 1) >= 0 && (test_i_height - 1) <= (height - 1) && test_j_zero >= 0 && test_j_zero <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtGreen += image[i - 1][j].rgbtGreen;
                    }
                // [i - 1][j + 1]
                if ((test_i_zero - 1) >= 0 && (test_i_height - 1) <= (height - 1) &&  (test_j_zero + 1) >= 0 && (test_j_zero + 1) <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtGreen += image[i - 1][j + 1].rgbtGreen;
                    }

                // [i + 1]
                // [i + 1][j - 1]
                if ((test_i_zero + 1) >= 0 && (test_i_height + 1) <= (height - 1) && (test_j_zero - 1) >= 0 && (test_j_zero - 1) <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtGreen += image[i + 1][j - 1].rgbtGreen;
                    }
                // [i + 1][j]
                if ((test_i_zero + 1) >= 0 && (test_i_height + 1) <= (height - 1) && test_j_zero >= 0 && test_j_zero <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtGreen += image[i + 1][j].rgbtGreen;
                    }
                // [i + 1][j - 1]
                if ((test_i_zero + 1) >= 0 && (test_i_height + 1) <= (height - 1) && (test_j_zero + 1) >= 0 && (test_j_zero + 1) <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtGreen += image[i + 1][j + 1].rgbtGreen;
                    }

                    //printf("counter Green:%f\n", counter);

                    copy[i][j].rgbtGreen = round(copy[i][j].rgbtGreen / counter);  // should be 'counter' variable, but can't get it to count yet and so delivers a zero which creates a floating point problem.,so '9' fo rnow.
                }
            }
    }
                    // printf("%i\n", noncounter);
}

{
int i = 0;
int j = 0;

for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
           {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
           }
    }
}
            }
    return;


}

// function definition
// ** NOTE the definition only runs the variables through one of the tests, i.e. [i][j-1]. needs to go through all 9 to be useful, and then somehow report the results!

int test_pixel(i, j, height, width)
    {
        if (i >= 0 && i <= (height - 1) && (j - 1) >= 0 && (j - 1) <= (width - 1))
        {
            return 1;
        }

    else  // this return false may be redundant, as the counter + pixel adding is only triggered on true.
        {
            return 0;
        }
    }








 }


                // [i]
                // [i][j - 1]
                if (i >= 0 && i <= (height - 1) && (j - 1) >= 0 && (j - 1) <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtRed += image[i][j - 1].rgbtRed;
                    }
                // [i][j]
                if (i >= 0 && i <= (height - 1) && (j) >= 0 && (j) <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtRed += image[i][j].rgbtRed;
                    }
                // [i][j + 1]
                if (i >= 0 && i <= (height - 1) && (j + 1) >= 0 && (j + 1) <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtRed += image[i][j + 1].rgbtRed;
                    }

                // [i - 1]
                // [i - 1][j - 1]
                if ((i - 1) >= 0 && (i - 1) <= (height - 1) && (j - 1) >= 0 && (j - 1) <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtRed += image[i - 1][j - 1].rgbtRed;
                    }
                // [i - 1][j]
                if ((i - 1) >= 0 && (i - 1) <= (height - 1) && j >= 0 && j <= (width - 1))
                    {
                               counter++;
                        copy[i][j].rgbtRed += image[i - 1][j].rgbtRed;
                    }
                // [i - 1][j + 1]
                if ((i - 1) >= 0 && (i - 1) <= (height - 1) &&  (j + 1) >= 0 && (j + 1) <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtRed += image[i - 1][j + 1].rgbtRed;
                    }

                // [i + 1]
                // [i + 1][j - 1]
                if ((i + 1) >= 0 && (i + 1) <= (height - 1) && (j - 1) >= 0 && (j - 1) <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtRed += image[i + 1][j - 1].rgbtRed;
                    }
                // [i + 1][j]
                if ((i + 1) >= 0 && (i + 1) <= (height - 1) && j >= 0 && j <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtRed += image[i+ 1][j].rgbtRed;
                    }
                // [i + 1][j + 1]
                if ((i + 1) >= 0 && (i + 1) <= (height - 1) && (j + 1) >= 0 && (j + 1) <= (width - 1))
                    {
                        counter++;
                        copy[i][j].rgbtRed += image[i+ 1][j + 1].rgbtRed;
                    }

                    // printf("counter Red:%f\n", counter);
                    copy[i][j].rgbtRed = round(copy[i][j].rgbtRed / counter);  // should be 'counter' variable, but can't get it to count yet and so delivers a zero which creates a floating point problem.,so '9' fo rnow.
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
