#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)

//NOTE - Test version, includes many more printouts than necessary
// NOTE - Test gives WRONG results, I think due to variance between floats when calculating division. Can't quite figure out how to sor that out.


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

// 'c0 converts float 'change' into an integer, to avoid inaccuracies of floats, while also multiplying by 100 to preserve decimal values.
// Consequently, all the divisions following are conducted *100....dividing by 25, instead of .25.  This preserves the decimals, but carries it out via integers.
// rounds the amount to the nearest penny, i.e. .2092384723987 rounds to .20:
int c0 = round (change * 100);


// Determine how many coins are needed to equal 'change' by dividing 'change' by coins in the following order and denominations of '.25', '.10', '.5' and '.1'

// 1st division, 'change' divided by '.25'.  Followed by calculating how much the remainder is:
// 'c1' = how many '.25' coins, 'r1'= the remainder.

    int c1;

    {   c1 = c0 /25;

        {
            printf(".25 - %i\n", c1);
        }
    }

// Calculate remainder

    int r1;

    {
        r1 = c0 - (c1 * 25);

        {
            printf("%i\n", r1);
        }
    }


// 2nd division, changed divided by '.10'

 int c2;

    {   c2 = r1 / 10;

        {
            printf(".10 - %i\n", c2);
        }
    }

// Calculate remainder
// NOTE - Uses the modulus operator, instead of the formula for calculating remainder. Modulus operator is used in final.
// Previously had great difficulty getting it to work as I didn't convert and round numbers to integers.

    int r2;

    {
        r2 = r1 % 10;

        {
            printf("%i\n", r2);
        }
    }

// 3rd division, changed divided by '.05'

    int c3;

    {   c3 = r2 / 5;

        {
            printf(".05 - %i\n", c3);
        }
    }

// Calculate remainder

    int r3;

    {
        r3 = r2 - (c3 * 5);

        {
            printf("%i\n", r2);
        }
    }

// 4th division, changed divided by '.01'

    int c4;

    {   c4 = r3 / 1;

        {
            printf(".01 - %i\n", c4);
        }
    }

// Calculate remainder

    int r4;

    {
        r4 = r3 - (c4 * 1);

        {
            printf("%i\n", r4);
        }
    }


// Print how many coins are required.
    {
        printf("%i\n", (c1 + c2 + c3 + c4));
    }


}


//int x;
//int change = 20;



  //      int q = 20 % .25;


    //    {
      //  printf("%i\n", q);
    //    }




