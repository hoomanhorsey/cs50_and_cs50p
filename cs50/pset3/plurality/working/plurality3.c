 #include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // [ORIG] Loop over all voters
    // This simply goes through all voters to get their votes, and then it checks for invalid votes.
    // But does '(!vote(name)) also call the (vote(String name)) function?
    // I think it does. But if it calls the function, why is the 'invalid name' check also embedded in it?

    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }

// Note, after the bool vote(string name) function is called, the programs goes stright back to line 55.  Not sure why.
// But this creates a loop where it prints out 'Invalid vote' even though it has already done that.

        //? Is this where i call the function?
        // Do i need to even call it, as it's not outputting anytine, just allocating votes.
        // If I don't call it, how do I get it to operate?
    }

    // Display winner of election
    print_winner();
}

// [ORIGINAL] Update vote totals given a new vote
bool vote(string name)
{

// for loop that compares votes cast against candidate names, and then for each vote, adds it to the array of votes.

// *NOTE*; Do i need to take care of uppercase lowercase?

     for (int j = 0; j < candidate_count; j++)

     {
            if (strcmp(name, candidates[j].name) == 0)
            {
                candidates[j].votes += 1;

                return true;
            }
     }

            return false;

}


//OKAY - SO HOW DO I MAKE IT RETURN FALSE?

// How do I stop the program from advising 'Invalid vote'?  When the vote is valid?
// But if it returns a bool value, i.e. 'true' or 'false' how does that allow us to tally the results ?

    // TODO

//? How do I actually call the function to process the name? Revisit functions?
// practice
// Do i need to loop it each time?  Or is the loop triggered when the function is called?



// [ORIGINAL] Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO

                // Test prints for verification

int highestvote = 0;
//string candidatewinner[candidate_count];

for (int k = 0; k < candidate_count; k++)
    {
        if (candidates[k].votes >= highestvote)

            {
                highestvote = candidates[k].votes;
//                candidatewinner[k] = candidates[k].name;
            }
//        else
//        {
//            candidatewinner[k] = 0;
//        }

    }


//      for (int l = 0; l < (candidate_count); l++)
//{
//            if (candidatewinner[l] != 0)

//            printf("%s\n", candidatewinner[l]);
//}

for (int l = 0; l < (candidate_count); l++)
{
    if (candidates[l].votes == highestvote)

        printf("%s\n", candidates[l].name);

}


    return;
}


    //NOTE - need to find out how many entires in an array, and then print that.



///NOTE Program currently prints one winnner, but needs to print multiple winners.
//Create candidate winner as an array.






//for (int j = 0; j < candidate_count; j++)

//        {
//            printf("name %s\n", candidates[j].name);
//            printf("votes %i\n", candidates[j].votes);
//        }





