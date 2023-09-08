#include <stdio.h>
#include <cs50.h>



int main(void)

{

// Prompt for heigh, greater than 1 (h)

    int h;
    do
    {
        h = get_int("Height: \n");
    }
    while (h < 1 || h > 8);


    // Print 2 pyramids to the height reflected by the variable 'h'
    
 //   do 
   // {   
    //    printf(" ");
//    }
  //  while (h < 8);
    
    
    {for (int j = 0; j < h; j++)
        {
        for (int w = 0; w < h; w++)
            {
                printf(".");
            }
            printf("#");
            printf(".\n"); 
        }

    }
    
//    {
  //  for (int w = 0; w < h; w++)
    //    {    
      //  for (int i = 0; i < h; i++)
        //    {
          //  printf("#");
        //    }
    //    printf("\n");
      //  }
  
}   





//  int i = 0,    then check if i<h, then execute print #, then add +1, 
//                  then chekc if i < h, then add another #, then print #, then add +





//do 

//print ("#  #\n");

//while (i < h);