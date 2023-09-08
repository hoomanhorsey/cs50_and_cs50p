#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // DEFINITIONAL
    // 'Preferences array' keeps track of voters + their votes by Candidate preference
    // 'Candidates array' is an array of the data struct 'Candidate', which  includes candidate (str)name, (int)number of votes they have, and whether they are eliminated.
    // 'voter_count' and 'candidate_count' are 2 global variables that are the actual counts, rather than the MAX.

// Check that each vote corresponds with a candidate name

    // Take 'name' input from voter. Compare name against list of candidates to determine if valid.
    // If 'name' is valid, then
    //      1) 'y' value is inserted into pref array as 'rank / 'pref[x][y]
    //      2) allocate vote to candidates[y].votes (*Not sure if this is correct*)
    //      3) and return true
    // If 'name' isn't valid, then return false.

    int x = 0, y = 0;

    for (x = 0; x < voter_count; x++) // looping for each voter, ie 1, 2, 3 etc
        {
            for (y = 0; y < candidate_count; y++) // looping each voter [i], for each candidate [j], 1, 2, 3 etc for each of the voters
                {
                    if (strcmp(name, candidates[y].name) == 0) //comparing name against candidate list, if matches then the following
                        {
                            preferences[x][y] = y;  // y acts as the reference index for candidate count. once there is a match, value of 'y' is inserted into pref array
                            // candidates[y].votes += 1; // adds vote to candiate

// Attempt to print the preferences array. not working.
    int p = 0, o = 0;

    for (p = 0; p < voter_count; p++)
            {
                printf("Voter:%i ", preferences[x][y]);

                for (o = 0; o < candidate_count; o++)
                {
                    printf("Pref[i][j]:%i, ", preferences[x][y]);
                }

                printf("\n");

   return true;
            }


                            printf("Candidate: %s: %i\n", candidates[y].name, preferences[x][y]);
                           // printf("Votes:%i\n", candidates[y].votes);


                        }
                }
        }


    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    return 0;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    return;
}