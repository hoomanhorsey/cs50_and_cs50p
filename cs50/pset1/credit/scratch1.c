#include <stdio.h>
#include <cs50.h>

int main(void)

{
    

float n; 

{
n = get_float("Number: \n");
}   

int divider;

{
divider = get_int("Divided by: \n");
}

float y; 

{
float n10, n11, n12, n13, n14;

    { 
    n10 = (n / divider);
    printf("%f\n", n10);
    
    n11 = (n10 / divider);
    printf("%f\n", n11);
    
     
    n12 = (n11 / divider);
    printf("%f\n", n12);
    
     
    n13 = (n12 / divider);
    printf("%f\n", n13);
    
    n14 = (n13 / divider);
    printf("%f\n", n14);
    
   
} 

}


}