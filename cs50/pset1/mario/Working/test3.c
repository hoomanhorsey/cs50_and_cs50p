#include <stdio.h>
#include <cs50.h>

int main(void);

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
          
          for (s = h - (h-1); s < h; s++)
          {
          printf("#");
          
          } 
          
          printf("\n");
         }
        
  }    
}
