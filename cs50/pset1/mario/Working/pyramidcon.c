#include <stdio.h>
#include <cs50.h>

int main(void)


{
    int h;  
    
    do 
        {
            h = get_int("Height:\n");
        }
    
    while (h < 1 || h >  8);
    
    
    
    switch(h)
    {
        case 1:
            printf("#\n");
            break;
        case 2:
            printf("##\n");
        case 3:
            printf("###\n");
        case 4:
            printf("####\n");
        case 5:
            printf("#####\n");
        case 6:
            printf("######\n");
        case 7:
            printf("#######\n");
        case 8:
            printf("########\n");
        }


}
