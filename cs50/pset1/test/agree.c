#include <stdio.h>
#include <cs50.h>

int main(void)

{

  char c = get_char("Do you agree? 'Y/y' or 'N/n' ");
  
    // Check whether agreed
    if (c =='Y' || c == 'y')
    
    {
        printf("Agreed.\n");
    }
    
    else if (c =='N' || c == 'n')
    
    {
        printf("Not agreed.\n");
    }
}