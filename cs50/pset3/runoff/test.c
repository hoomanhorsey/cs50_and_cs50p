#include <stdio.h>
#include <cs50.h>


int main(void)
{

int array[3][3];

array[0][0] = 1;
printf ("array [0][0]: %i,\n", array[0][0]);

array[1][0] = 2;
printf ("array [1][0]: %i,\n", array[1][0]);

array[2][0] = 3;
printf ("array [2][0]: %i,\n", array[2][0]);

int i;

for (i = 1; i < 11; i++)
    {


    printf("Value of 'i' variable: %i\n", i);
    }


bool eliminated = false;

eliminated = true; // or value of 1

    printf("bool value: %d\n", eliminated);  // bool printed as an integer, 0 = false, everything else = true

}