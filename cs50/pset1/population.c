#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    
    printf("I can tell you how many years it will take your llama population to reach a certain size. But first you gotta tell me how how many llamas are we talking here? A hundred? Two hundred? \n");
    
    // Ask for positive integer, but only accept greater than 9
    // n = initial llama population size
   
    int n;
    
    do
    {
        n = get_int("So how many llamas in your herd? \n");
    }
    while (n < 9);  

    // TODO: Prompt for end size
    // e = end llama population size
    
    int e;
    do
    {
        e = get_int("And how many llamas are in your final herd? \n");
    }
    while (e < n);  

    // TODO: Calculate number of years until we reach threshold

    // update n population each year
    // n = llama pop after 1 year =
    //                      llama pop - (llama pop divided by 4)
    //                      llama pop + (llama pop divided by 3)
    // = n+1, repeat, until n+1 is greater than y(ears)

    int y = 0;
    
    while (n < e)
    
    { 
        n = n + (n / 3) - (n / 4);
        y = y + 1;
    }

    // TODO: Print number of years
    
    printf("Years: %i", y);

}

