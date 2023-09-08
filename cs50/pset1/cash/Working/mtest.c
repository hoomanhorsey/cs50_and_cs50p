#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)

// Begin Program
{

//Asking for input function (float, greater than zero (or, will not accept inputs that are less than or equal to zero)):

// float 'change' sits outside the curly brackets of the function.

    float change;

    {
        do
        {
            change = get_float("Change Owed: \n");
        }
        while (change <= 0);
    }
    
    // prints change, just as a test.
    {
        printf("%f\n", change);
    }
    
// Determine how many coins are needed to equal 'change' by dividing 'change' by coins in the following order and denominations of '.25', '.10', '.5' and '.1'

// 1st division, 'change' divided by '.25'.  Followed by calculating how much the remainder is:
// 'c1' = how many '.25' coins, 'r1'= the remainder.

    int c1;
    
    {   c1 = change /.25;
        
        {
            printf("%i\n", c1);
        }
    }
    
// Calculate remainder

    float r1;
    
    {
        r1 = change % .25;
       
        {
            printf("%f\n", r1);
        }
    }
    
    
// 2nd division, changed divided by '.10' 

 int c2;
    
    {   c2 = r1 /.10;
        
        {
            printf("%i\n", c2);
        }
    }
    
// Calculate remainder

    float r2;

    {
        r2 = r1 - (c2 * .10);
       
        {
            printf("%f\n", r2);
        }
    }

// 3rd division, changed divided by '.05' 

    int c3;
    
    {   c3 = r2 /.05;
        
        {
            printf("%i\n", c3);
        }
    }
    
// Calculate remainder

    float r3;

    {
        r3 = r2 - (c3 * .05);
       
        {
            printf("%f\n", r2);
        }
    }

// 4th division, changed divided by '.01' 

    int c4;
    
    {   c4 = r3 /.01;
        
        {
            printf("%i\n", c4);
        }
    }
    
// Calculate remainder

    float r4;

    {
        r4 = r3 - (c4 * .01);
       
        {
            printf("%f\n", r4);
        }
    }

    
    
// Modulus sample function:
    {
        float m = 19 % 4;
        
        {
            printf("%f\n", m);
        }
    }





}


//int x;
//int change = 20;



  //      int q = 20 % .25;


    //    {
      //  printf("%i\n", q);
    //    }




