#include <stdio.h>
#include <cs50.h>

int main(void)
{

    // Names (strings)
    string answer = get_string("What's your name? ");
    
    printf("hello, %s\n", answer);

    // Integers
    
    printf("Adding integers. Give me 2 integers\n");
  
    int x = get_int("x: ");
    int y = get_int("y: ");
    
    printf("%i\n", x + y);


    // Long Integers

    printf("Adding long integers. Give me 2 long integers\n");

    long a = get_long("long integer a: ");
    long b = get_long("long integer b: ");

    printf("%li\n", a + b);

    // Floating point numbers

    printf("Dividing integers. Give me 2 integers to divide into floating point fractions\n");
    
    int c = get_int("c: ");
    int d = get_int("d: ");
    
    float z = (float)c / (float)d;
    printf("%f\n", z);
    
}

