#include <stdio.h>
#include <stdlib.h>

int main(void)
{
int a;
int b;
int c = 0;

int *pa = malloc(sizeof(int));
int *pb = malloc(sizeof(int));

a = 10;
b = 20;


pa = &a;
pb = &b;

c = *pa * *pb;

printf("c equals: %i\n", c);

free(pa);
free(pb);
 
}