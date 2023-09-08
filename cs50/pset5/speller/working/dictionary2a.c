// TO DO
// - can't get the check function to succesfful traverse a linked list. Have a think about how to traverse a list. revisit the function.
// - it currently seems to check the first word in the list, and then bail, returning either true (Even if not) or false.
// it needs to check, and then if false, check the next one, and if false, check the next one....
// ...until it finds a match, and returns true, or finds NULL, in which case it returns false.


// revisit hash function when the spell check is proven to work.
// - clarify whether you need to make the first entry of table[hashumber] to equal 'NULL'

// - load - completed, I think.
// - hash - simple version, completed
// - size - completed, I think.
// - check - check isn't working.
            // Is the function correct?
            // Has load correctly loaded teh words in the dictionary?
// - unload


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
int *pdicsize = &dicsize;

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

//    int hashnum = hash(word);    // generate hash number for each word

    // for (node *tmp = table[hashnum]; tmp !=NULL; tmp = tmp->next)
    // {
    //     printf("check hashnum: %i, tmp->word: %s, check word: %s\n", hashnum, tmp->word, word);

        // if (strcasecmp(table[hashnum]->word, word) == 0)

   //      if (strcasecmp(tmp->word, word) == 0)
   //     {
   //         printf("Correct\n");
   //         return true;
   //      }
   //  }

// printf("misspelt\n");
// return false;
// }


int hashnum = hash(word);

node *tmp = table[hashnum];

while (tmp != NULL)
{
    if (strcasecmp(tmp->word, word) == 0)
    {
        // printf("tmp->word: %s - word: %s\n", tmp->word, word);
        // printf("Correct\n");
        return true;
    }

    else
    {
        // printf("before - tmp->word: %s\n", tmp->word);
        tmp = tmp->next;
        // printf("after - tmp->word: %s\n", tmp->word);

    }
 }

// printf("misspelt\n");
return false;

// printf("check hashnum: %i, table[hashnum]->word: %s, check word: %s\n", hashnum, table[hashnum]->word, word);

}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    // return toupper(word[0]) - 'A'; // original hash function.

    int value = 0; // revised function, made into one additional step to see how it works.
    value = toupper(word[0]) - 'A';

    //hashedcounter++;
    //printf("Value: %i, Hashes: %i\n", value, hashedcounter); // test print
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

    node *n; // declaring a temp node 'n'

    while (!feof(file))  // while content of 'file' is != NULL, function loops
    {
        fscanf(file, "%s", tword); //scan word from file into 'tword' array
        n = malloc(sizeof(node)); // declaring memory for a temp node
        if (n == NULL)
            {
                return false;
            }

        dicsize++; // iterates dictionary counter each time a word is copied,for size function.
        // printf("Dictionary Size: %i\n", dicsize); // ## print test,delete later

        strcpy(n->word, tword); // copy 'tword' into n
        n->next = NULL; // set 'next' pointer to NULL

        // printf("strcpy: %s\n", n->word);

        // Call Hash function. Function takes 'tword' as input, generates the integer 'hashnum'.
        int hashnum = hash(tword);

        // Inserts n into hashtable at the location given by hashnum. 26 different locations, 0-25.
        if (table[hashnum] != NULL)
        {
            n->next = table[hashnum];
            table[hashnum] = n;
            // printf("%s\n", table[hashnum]->word);
            // printf("Loaded word\n");
        }
        else
        {
            table[hashnum] = n;
        }

         //if (table[hashnum] != NULL)
        // {
          //  n = table[hashnum]->next;
          //  table[hashnum] = n;
        // }
        //    printf("%s\n", table[hashnum]->word);
         //   printf("Loaded word\n");
       // }
        //else
        // {
        //    table[hashnum] = n;
            // printf("hashnum %i, word: %s\n", hashnum, table[hashnum]->word);
        //}
        // # Do i need to declare table[hashnum] as NULL to begin with? For the first link of a node?
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
    // TODO

//node *temp = NULL;
//node *cursor = NULL;

// for loop, to go thorugh each hash? 0 to 25

    int i = 0;

    for (i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {

        node *cursor = table[i]->next;
        node *tmp;

        //for (node *tmp = table[i]; tmp != NULL; tmp = tmp->next)
        {
            while (cursor != NULL)
            {
                tmp = cursor;
                cursor = cursor->next;
                free(tmp);
            }
            return true;
        }
        // for (temp = cursor->next; cursor->next !=NULL; temp = cursor->next)
            //{
            //  temp = cursor;
            // cursor = cursor->next;
                //free(temp);
        // }
        }
    }
return false;
}
