// Simulate genetic inheritance of blood type

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Seed random number generator
    srand(time(0));

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // TODO: Allocate memory for new person

    // Start the list, by declaring a a pointer to an empty list, of NULL value.
    // This will be the header for the list later.
    // person *pPerson = NULL;

   // Using malloc to declare dynamic memory for a temporary person struct, called 'temp'.
    person *temp = malloc(sizeof(person));

    if (temp == NULL)
    {
        printf("Not enough memory. Program aborted\n");
        return 0;
    }

    // copying over NULL values for pointers in temp, to make sure it's clean.
    //temp->parents[0] = NULL;
    //temp->parents[1] = NULL;
    //temp->alleles[0] = 'A'; // ## just allocate a value for temp->alleles[0] for now,

 printf("Value of temp alleles[0]: %c\n", temp->alleles[0]);

    // pPerson = temp; // copying temp over to pPerson.

    // free(temp); // don't need to free temp if i'm going to use it again.





    // If there are still generations left to create
    if (generations > 1)
    {
        // Create two new parents for current person by recursively calling create_family
        person *parent0 = create_family(generations - 1);
        person *parent1 = create_family(generations - 1);

        // TODO: Set parent pointers for current person

        temp->parents[0] = parent0; // #is the pointer used here the right name? should it just be 'parent' instead of parent0?
        temp->parents[1] = parent1;  // #do i need to malloc space for those 2 parents or is it done automatically in this recursive function?

        // TODO: Randomly assign current person's alleles based on the alleles of their parents

        temp->alleles[0] = random_allele(); //insert formula for random char based on parent's allelels
        temp->alleles[1] = random_allele();
        //## Need formula here to calculate a random char based on parent's alleles

        // Can probably consolidate this into a for loop with 2 iterations

        {
            int i = 0;
            for (i = 0; i < 2; i++)

            {
                char ran_allele = random_allele(); // creates random char of A, B or O, assigns to 'ran_allele'
                printf("ran_allele = %c\n", ran_allele);  //check print

                pPerson->alleles[i] = 0;

                while (pPerson->alleles[i] == 0)
                {
                    if (ran_allele == (parent0->alleles[0] || parent0->alleles[1]))
                    {
                        pPerson->alleles[i] = ran_allele;
                        printf("p->alleles[%i]: %c\n", i, pPerson->alleles[i]);
                    }
                }
            }
        }

// assign random alleles based on parents


    }

    // If there are no generations left to create
    else
    {
        // TODO: Set parent pointers to NULL
        temp->parents[0] = NULL; // parent pointers set to NULL, but not sure about the pPerson node.  Which node should I use?
        temp->parents[1] = NULL;

        // TODO: Randomly assign alleles
        temp->alleles[0] = random_allele();
        temp->alleles[1] = random_allele();
    }

    // TODO: Return newly created person


    return NULL;
}

// Free `p` and all ancestors of `p`.
void free_family(person *p)
{

    // 18m20s of linked singly liinked lists short video
    // TODO: Handle base case

    // TODO: Free parents recursively

    // TODO: Free child

}

// Print each family member and their alleles.
void print_family(person *p, int generation)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person
    if (generation == 0)
    {
        printf("Child (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Parent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Great-");
        }
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }

    // Print parents of current generation
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Randomly chooses a blood type allele.
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}


 //####
    // Do i need to do a loop to allocate memory for each iteration of person?  I seem to be only allocating memory for one person, 'p'.
    // Or does the recursive loop take this person 'p' as a placeholder for each successive person?
    // do i need to do a for loop to allocate memory for whichever person is subject to this create family function?
    // i.e. // for (j = 0; j < generation; j++)
    //  person *pPerson = (person *)malloc(sizeof(person));  // alt version with cast before malloc as a 'person *'. NOt sure if if makes a dif
    //###
