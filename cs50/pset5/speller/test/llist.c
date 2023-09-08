#include <stdio.h>
#include <stdlib.h>





int main(void)

// Declare struct node
{
typedef struct node
    {
        int n;
        struct node *next;
    }
node;


// malloc mem for node 'temp'
{
node *temp = malloc(sizeof(node));
if (temp == NULL)
    {
        printf ("Out of memory error");
        return 0;
    }

// assigning values to temp variables.
temp->n = 1;
temp->next = NULL;

// node root = *temp;
printf("Node temp value = %i\n", temp->n);
printf("Temp Node address = %p\n", temp->next);


node *root = malloc(sizeof(node));
if (root == NULL)
    {
        printf ("Out of memory error");
        return 0;
    }

root = temp;

printf("Root Node value = %i\n", root->n);
printf("Root Node address = %p\n", root->next);


// 2nd node


node *branch = malloc(sizeof(node));
if (branch == NULL)
    {
        printf ("Out of memory error");
        return 0;
    }

branch->n = 2;
branch->next = NULL;

root->next = branch;


printf("Branch Node value = %i\n", branch->n);
printf("Branch Node address = %p\n", branch->next);

printf("Branch Node address, actual = %p\n", branch);

printf("Root Node address = %p\n", root->next);

// 3rd node


node *branch2 = malloc(sizeof(node));
if (branch2 == NULL)
    {
        printf ("Out of memory error");
        return 0;
    }

branch2->n = 5;
branch->next = NULL;

root->next->next = branch2;


printf("Branch2 Node value = %i\n", branch2->n);
printf("Branch2 Node address = %p\n", branch2->next);

printf("Branch Node address = %p\n", branch->next);

printf("Branch2 Node address, actual = %p\n", branch2);

// free(temp);
// free(root);
// free(branch);



{
    printf("\n");
    printf("Contents of linked list, values\n");
    int i;

    for (i = 0; i < ##; i++)
    printf("Contents of node[%i]: \n", i, root branch2);


    if (branch->next != NULL)
    printf("Contents of node[%i]: \n", i, root branch2);

// use a node as a pointer node to be able to print down the line?

}

}
return 0;
}
