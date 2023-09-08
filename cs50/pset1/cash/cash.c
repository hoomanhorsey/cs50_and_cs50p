#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)

//NOTE - See Cashtest for full notes and test prints.

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


// 'c0' converts float 'change' into an integer, to avoid inaccuracies of floats, while also multiplying by 100 to preserve decimal values.
// Consequently, all the divisions following are conducted *100....dividing by 25, instead of .25.  This preserves the decimals, but carries it out via integers.
// rounds the amount to the nearest penny, i.e. .2092384723987 rounds to .20:

    int c0 = round(change * 100);

// Determine how many coins are needed to equal 'change' by dividing 'change' by coins in the following order and denominations of '.25', '.10', '.5' and '.1'

// 1st division, 'change' divided by '25', representing 25c.  Followed by calculating how much the remainder is:
// 'c1' = how many '.25' coins, 'r1'= the remainder.

    int c1;
    {
        c1 = c0 / 25;
    }

// Calculate remainder

    int r1;
    {
        r1 = c0 % 25;
    }

// 2nd division, changed divided by '.10'

    int c2;
    {
        c2 = r1 / 10;
    }

// Calculate remainder

    int r2;
    {
        r2 = r1 % 10;
    }

// 3rd division, changed divided by '.05'

    int c3;
    {
        c3 = r2 / 5;
    }

// Calculate remainder

    int r3;
    {
        r3 = r2 % 5;
    }

// 4th division, changed divided by '.01'

    int c4;
    {
        c4 = r3 / 1;
    }

// Calculate remainder

    int r4;
    {
        r4 = r3 % 1;
    }

// Print how many coins are required.
    {
        printf("%i\n", (c1 + c2 + c3 + c4));
    }

}

