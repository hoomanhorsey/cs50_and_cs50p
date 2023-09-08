// Implements a dictionary's functionality

#include <stdio.h> // #I inserted this
#include <stdlib.h> // #I inserted this
#include <string.h> // #I inserted this


#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

//    int sizecounter = 0;
//    int *psizecounter = &sizecounter;
 //   int hashedcounter = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    // return toupper(word[0]) - 'A'; // original hash function.

    int value = 0;
    value = toupper(word[0]) - 'A';
    psizecounter++;
    hashedcounter++;
    printf("Value: %i, Hashes: %i\n", value, hashedcounter); // test print
//    printf("Sizecounter: %i\n", sizecounter);
    return value;


// Note, could improve hash function by splitting second letter by vowels, so 26 x 5,
// AA AB AC AD / AE AF AG AH / AI AJ AK AL AM AN / AO AP AQ AR AS AT /AU AV AW AX AY AZ
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
        {
            return false;
        }
  //   int sizecounter = 0;
   // int *psizecounter = &sizecounter;

    // Read strings from file
    char tword[LENGTH + 1];  //create char array to store string in variable 'tword'

    while (!feof(file))  // loops function to create node, until 'file' = EOF  #NOT SURE ABOUT THE ODER OF LOOP##
        {
            fscanf(file, "%s", tword); //scan word from file into 'word' array
            node *n = malloc(sizeof(node)); // declaring memory for a new temp node called 'n'
            if (n == NULL)
                {
                    return false;
                }
            strcpy(n->word, tword); // copy 'tword' into node at 'word'
            n->next = NULL; // set 'next' pointer to NULL

            // Call Hash function
            int hashnumber = hash(tword);

            // now insert node into hash table at that location given by hash function

            if (table[hashnumber] != NULL)
            {
                n = table[hashnumber]->next;
                table[hashnumber] = n;
            }
            else
            {
                table[hashnumber] = n;
            }
            // # but how to declare hashnumber as NULL for the first link to a node??!

            sizecounter++;


                // hashnumber
        }

    fclose(file); // closing file.


    return true;

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    printf("Sizecounter: %i\n", hashedcounter);
    printf("Sizecounter: %i\n", *psizecounter);
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
