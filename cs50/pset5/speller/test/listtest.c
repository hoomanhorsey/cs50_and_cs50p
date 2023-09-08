// Test linked lists
#include <stdio.h> // #I inserted this
#include <stdlib.h> // #I inserted this
#include <string.h> // #I inserted this

const int LENGTH = 100;
int main(void)

{
// Represents a node in a hash table
typedef struct node
{
    int number;
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
// node *table[N];


// Setting starting pointer

node *list = NULL;

// Setting up first node
node *n = malloc(sizeof(node));
if (n == NULL)
{
    return 1;
}

n->number = 3;
n->next = NULL;

list = n;

// Setting up second node

n = malloc(sizeof(node));
if (n == NULL)
{
    free(list);
    return 1;
}
n->number = 2;
n->next = NULL;

n->next = list;
list = n;


// Setting up third node

n = malloc(sizeof(node));
if (n == NULL)
{
    free(list->next);
    free(list);
    return 1;
}

n->number = 1;
n->next = NULL;
n->next = list;
list = n;






for (node *tmp = list; tmp != NULL; tmp = tmp->next)
{
   printf("%i\n", tmp->number);
}

}

// printf("Value of n->word: %s\n", n->word);
//printf("Value of table[0]->word: %s\n", table[0]->word);
