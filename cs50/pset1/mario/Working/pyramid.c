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
    
    {

    if (h > 0 && h < 9)
        {
            printf("#\n");
        }
    }

    {
    if (h > 1 && h < 9)
        {
            printf("##\n");
        }
    }

    {
    if (h > 2 && h < 9)
        {
            printf("###\n");
        }
    }

    {   
    if (h > 3 && h < 9)
        {
            printf("####\n");
        }
    }

    {
    if (h > 4 && h < 9)
        {
            printf("#####\n");
        }
    }

    {
    if (h > 5 && h < 9)
        {
            printf("######\n");
        }
    }        

    {
    if (h > 6 && h < 9)
        {
            printf("#######\n");
        }
    }        

    {
    if (h > 7 || h == 9)
        {
            printf("########\n");
        }
        
}

}
