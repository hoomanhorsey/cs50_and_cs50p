#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)

//testing conversion of input float, into integers for calculation.


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
        printf("%f\n", (change*100));
    }

int c0 = (change * 100);

int c1;

    {   c1 = c0 /25;

        {
            printf(".25 - %i\n", c1);
        }
    }

    
    
    
}


