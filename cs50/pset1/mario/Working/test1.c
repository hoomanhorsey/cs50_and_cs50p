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
  
    int j = 0;
  
  {
    if (h < 1)
    {
    for (j = 0; j < h; j++)
    
        {   
        printf(".");
        }
    }
    
    for (j = 0; j < h; j++)
        
        {
          printf("#");
        }
    
        {   
            printf("..");
        }
     
    for (j = 0; j < h; j++)
        
        {
          printf("?");
        }
    
        printf("\n");
        
   
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