#include <stdio.h>
#include <cs50.h>




bool valid_triangle(float a, float b, float c);


int main(void)

{

float x = get_float ("Side 1:\n");

float y = get_float ("Side 2:\n");

float z = get_float ("Side 3:\n");


bool t = valid_triangle(x, y, z);

if (t == 0)

    {
        printf("false\n");
    }

else
{
    printf("true\n");
}

}

bool valid_triangle(float a, float b, float c)

{

    if ((a < 0) || (b < 0) || (c < 0))

    {
    return false;
    }


    if (((a + b) <= c) || ((b + c) <= a) || ((c + a) <= b))

    {
    return false;
    }
    else

    {
    return true;
    }

}
