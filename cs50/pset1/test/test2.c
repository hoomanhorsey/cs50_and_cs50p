#include <stdio.h>
#include <cs50.h>

int main(void)

{  
    
    // Prompty user for x
    
    int x = get_int("x: ");
    
    // Prompty user for y
    
    int y = get_int("y: ");
    
    // Compare x and y
    
    if (x < y)
    {
        printf("x is less than y\n");
    }
    
    else if (x > y)
    
    {
        printf("x is greater than y\n");
        
    }
    
    else
    
    {
        printf("x is equal to y\n");
    }
}


