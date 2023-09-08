#include <stdio.h>
#include <cs50.h>

int main(void)
{

int i = 0;
int a;
int b;
int c;


    a = 2;
    b = 3;
    c = 0;

for (i = 0; i < 10000000; i++)
{


    c = (a * b);

a = c;


c = (a * b);

printf("Sum: %i\n", c);
}


}