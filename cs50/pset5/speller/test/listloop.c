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


node *tlist = NULL;
node *m;
int vnum = 0;


for (node *looptmp = tlist; looptmp != NULL; looptmp = looptmp->next)
{
    m = malloc(sizeof(node));
    if (m == NULL)
    {
        free(list);
        return 1;
    }
    m->number = vnum;
    m->next = NULL;

    m->next = tlist;
    tlist = m;
   printf("%i\n", looptmp->number);
}


node *n = malloc(sizeof(node));


have list (node *table[N}, or in other words each pointer is table[v])

make n node (n = malloc(sizeof(node));)
    insert value (n-word = tempword);
    insert point (n-next = NULL)
    insert n pointer into list (list = n;)

make n node (n = malloc(sizeof(node));)
    insert value (n-word = tempword);
    insert point (n-next = NULL)
    point n node to node 1 (n = list->next;)
    insert n pointer into list (list = n);

make n node (n = malloc(sizeof(node));)
    insert value (n-word = tempword);
    insert point (n-next = NULL)
    point n node to node 1 (n = list->next;)
    insert n pointer into list (list = n);

make n node (n = malloc(sizeof(node));)
    insert value (n-word = tempword);
    insert point (n-next = NULL)
    point n node to node 1 (n = list->next;)
    insert n pointer into list (list = n);

'Load' is giving us an array value ('table[v]') and a word value ('word').
We need to
- identify the array value,
- create a new node,
- insert the word into the new node
 insert NULL into the node.
- if it's the first node:
    - link the array value to the new node
- if a node already exists
    - link the new node to the existing first node
    - link the array value to the new node.


and an array value


}

// printf("Value of n->word: %s\n", n->word);
//printf("Value of table[0]->word: %s\n", table[0]->word);
