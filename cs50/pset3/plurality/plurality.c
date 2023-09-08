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
    // As defined in 'vote(name)' function, valid votes are recorded, invalid votes return a false which then prints 'invalid vote'

    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }

    }

    // Display winner of election
    print_winner();
}

// [ORIGINAL] Update vote totals given a new vote
bool vote(string name)
{

// 'for loop' that compares votes cast against candidate names
// For each valid match, adds vote to the array of votes. If it isn't a match, returns false, which then prints 'invalid vote'
// *NOTE*, I've not addressed uppercase or lowercase. Names must be exact match.

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

// [ORIGINAL] Print the winner (or winners) of the election
void print_winner(void)
{

// Sets an int 'highestvote' = 0, then compares variable against array of candidate votes to find highest vote.
// Updates 'highestvote' to the same value as the highest candidate[k]vote.

    int highestvote = 0;

    for (int k = 0; k < candidate_count; k++)
    {
        if (candidates[k].votes >= highestvote)
        {
            highestvote = candidates[k].votes;
        }
    }

// Loops over candidate[l].votes again. For those that == the 'highestvote', prints candidate[l].name
// Will print names of highest voting candidates, whether it is 1 or 2 or more.

    for (int l = 0; l < (candidate_count); l++)
    {
        if (candidates[l].votes == highestvote)
        {
            printf("%s\n", candidates[l].name);
        }
    }
    return;
}