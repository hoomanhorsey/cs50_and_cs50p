// TO DO
// - revisit hash function when the spell check is proven to work.

// - load - completed,
// - hash - simple version, completed
// - size - completed,
// - check - completed
// - unload - completed, however, mem issues according to valgrind.


// Implements a dictionary's functionality

#include <stdio.h> // #I inserted this
#include <stdlib.h> // #I inserted this
#include <string.h> // #I inserted this
#include <strings.h> // #I inserted this

#include <ctype.h>
#include <stdbool.h>
#include "dictionary.h"

// ###GLOBAL COUNTER VARIABLES
int dicsize = 0; // dictionary size counter
int *pdicsize = &dicsize; // pointer to dicsize

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
    int hashnum = hash(word);  // generate hash number for each word
    node *tmp = table[hashnum]; // tmp node, pointing at head of linked list

    while (tmp != NULL) // if tmp is not pointing at NULL, then end of the list, then while loop operates
    {
        if (strcasecmp(tmp->word, word) == 0) // compares 'word' with word from table[hashnum], if a match, returns true...
        {
            return true;
        }

        else
        {
            tmp = tmp->next; // ...but if not true, advances the word in tmp to the next one in the linked list, and loops around.
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    // return toupper(word[0]) - 'A'; // original hash function.

    int value = 0; // revised function, made into one additional step to see how it works.
    value = toupper(word[0]) - 'A';

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

    // Read strings from file
    char tword[LENGTH + 1];  //create char array to store string in variable 'tword'

    // node *n = 0; // declaring a temp node 'n'

    while (!feof(file))  // while content of 'file' is != NULL, function loops
    {
        fscanf(file, "%s", tword); //scan word from file into 'tword' array

        if (feof(file)) // returns function if file is EOF...(note, while loop does not continue if file is EOF, but it continues one last scan and copy, if it isn't expressly ended)
        {
            fclose(file);
            return true;
        }

        node *n = malloc(sizeof(node)); // declaring memory for a temp node
        if (n == NULL)
        {
            //free(n);
            return false;
        }

        strcpy(n->word, tword); // copy 'tword' into n
        n->next = NULL; // set 'next' pointer to NULL

        // Call Hash function. Function takes 'tword' as input, generates the integer 'hashnum'.
        int hashnum = hash(tword);

        dicsize++; // iterates dictionary counter each time a word is copied,for size function.

        // Inserts n into hashtable at the location given by hashnum. 26 different locations, 0-25.
        n->next = table[hashnum];
        table[hashnum] = n;
    }

    fclose(file); // closing file.
    return true;

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // ## How do I determine if the dictionary is loaded or not?  I.e. How do I trigger the function to return 0?
    //printf("Dictionary Size: %i - delete msg later\n", *pdicsize);
    return *pdicsize;

    //return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    int i = 0;

    for (i = 0; i < N; i++) // for loop to iterate over each linked list (represented by a hashnum)
    {
        node *cursor = table[i];
        node *tmp;

        while (cursor != NULL)
        {
            tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;

    return false;
}



// Test prints
// printf("before - tmp->word: %s\n", tmp->word);
// printf("after - tmp->word: %s\n", tmp->word);
//     printf("check hashnum: %i, tmp->word: %s, check word: %s\n", hashnum, tmp->word, word);
// printf("tmp->word: %s - word: %s\n", tmp->word, word);
// printf("Correct\n");
// printf("misspelt\n");

// printf("check hashnum: %i, table[hashnum]->word: %s, check word: %s\n", hashnum, table[hashnum]->word, word);

//printf("Value: %i, Hashes: %i\n", value, hashedcounter); // test print


// printf("Dictionary Size: %i\n", dicsize); // ## print test,delete later

// printf("strcpy: %s\n", n->word);

// printf("%s\n", table[hashnum]->word);
// printf("Loaded word\n");
// printf("hashnum %i, word: %s\n", hashnum, table[hashnum]->word);
