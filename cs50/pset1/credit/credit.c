#include <stdio.h>
#include <cs50.h>

int main(void)

// Ask for ccnumber

{
    float ccnumber = get_float("Credit Card Number: \n");




// A. Check sum of ccnumber

// Note. If we have to identify the numbers by analysing each column of digit, then the define function tool will come in handy if I can get it to work


// A.1 Extract numbers

// Experiment to see if division truncates number and rounds up or down.  Doesn't do any rounding, just cuts it down.
// It does work, but making it in comments for now
// printf("%li", ccnumber/1000);


// Loops that divides ccnumber by 10 (ccd10), then checks to see if product is less than one, if greater, then divides ccd10 by 10, (ccd10_2) then checks if cc10_2 is less than one, if greater divides again...



// Loop that divides ccnumber by 10, and then loops it by dividing it again 5 times.  What I would like to do is divide the sum of what's divided however!

float divisionsum;

int columns;
int divider;
{
for (columns = 0; columns < 5 ; columns++)

    {
        divider = 10;
        divisionsum = (ccnumber / divider);
        printf("%f\n", divisionsum);
    }
        divider = divider * 10;
}




{
    float moredivision;

    int columnsplus;

    for (columnsplus  = 0; columnsplus < 5; columnsplus++)

        {
                moredivision = printf("%f\n", moredivision / 10);
        }
}



// Try to calculate how many columns are in a number (i.e 53462 has 5 columns. Potentially useful in being able to extract specific numbers, by column, from a number.

//    long divisionsum;

//do

//    {
//        divisionsum = printf("%li\n", ccnumber / 10);
//    }

//while (divisionsum > 1);


}




