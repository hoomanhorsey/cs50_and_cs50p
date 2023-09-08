#include <stdio.h>
#include <cs50.h>

int main(void)

{
// Prompt for height (h), must be greater than 1, less than 8
    int h;
    do
    {
        h = get_int("Height: \n");
    }
    while (h < 1 || h > 8);


    // Print 2 pyramids to the height reflected by the variable 'h'
    
    int j;
    
    // Repeat the entire function 'h' times
    for (j = 0; j < h; j++)
      
    {
    //first line..., 1st char

        {
          int s;
          
          for (s = 1; s < h; s++)
          {
          printf(".");
          } 
          
    //first line..., 2nd char
          {
          int t;
          
          for (t = 0; t < h; t++)
          {
          printf("#");
          }
          }
    //first line..., 3rd char

          printf("..");
          
     //first line..., 4th char

         {
          int u;
          
          for (u = 0; u < h; u++)
          {
          printf("?");
          }
        

          printf("\n");

        
         
         }
        }
  }    
}


 //   
//    {for (int j = 0; j < h; j++)
//        {
//        for (int w = 0; w < h; w++)
//            {
//                printf(".");
//            }
//            printf("#");
//            printf(".\n"); 
        

    
    
//    {
  //  for (int w = 0; w < h; w++)
    //    {    
      //  for (int i = 0; i < h; i++)
        //    {
          //  printf("#");
        //    }
    //    printf("\n");
      //  }
  






//  int i = 0,    then check if i<h, then execute print #, then add +1, 
//                  then chekc if i < h, then add another #, then print #, then add +





//do 

//print ("#  #\n");

//while (i < h);