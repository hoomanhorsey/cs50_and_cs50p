#include <cs50.h>
#include <stdio.h>




bool validtriangle(int sidea, int sideb, int sidec);



int main(void)




int a;
int b;
int c;

{
    

do

    {
    int a = get_int("First Side\n,");
    }
    while (a < 0);

do
    {
    int b = get_int("Second Side\n,");
    }
    while (b < 0);

do
    {
    int c = get_int("Third Side\n,");
    }
    while (c < 0);


printf("") 



bool validtriangle(int sidea, int sideb, int sidec);


    if (((sidea + sideb) <= sidec) || ((sideb + sidec) <= sidea) || ((sidec + sidea) <= sideb));
       
    {
    return false;
    }
    
    return true;

    
}




