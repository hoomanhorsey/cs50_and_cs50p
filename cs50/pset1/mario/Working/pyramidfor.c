#include <stdio.h>
#include <cs50.h>

int main(void)


{
    // Gets input
    
    int h;
    
    do 
        {
            h = get_int("Height:\n");
        }
    
    while (h < 1 || h >  8);
    
    
    
    //**NOTE THIS ONLY SEEMS TO WORK FOR HEIGHT OF 8** Haven't put in breaks yet)
    
    
    // Prints #


    // Prints line 1#
    
    int y;
    
    for (y = 0; y < (h - (h - 1)); y++)
           {
            printf("#");
           }    
    
    printf ("\n");
    

// Prints line 2#
       
    int w;
    
    for (w = 0; w < (h - (h - 2)); w++)
           {
            printf("#");
           }    
    
    printf ("\n");
    
    // Prints line 3#
       
    int q;
    
    for (q = 0; q < (h - (h - 3)); q++)
           {
            printf("#");
           }    
    
    printf ("\n");
    
       // Prints line 4#
       
    int r;
    
    for (r = 0; r < (h - (h - 4)); r++)
           {
            printf("#");
           }    
    
    printf ("\n");
    
       // Prints line 5#
       
    int s;
    
    for (s = 0; s < (h - (h - 5)); s++)
           {
            printf("#");
           }    
    
    printf ("\n");
    
    
       // Prints line 6#
       
    int t;
    
    for (t = 0; t < (h - (h - 6)); t++)
           {
            printf("#");
           }    
    
    printf ("\n");
    
    
       // Prints line 7#
       
    int u;
    
    for (u = 0; u < (h - (h - 7)); u++)
           {
            printf("#");
           }    
    
    printf ("\n");

// Prints line 8#

    int x;
    
        for (x = 0; x < h; x++)
           {
            printf("#");
           }
        
    printf ("\n");
    
   
        
        
}


