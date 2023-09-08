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

// The function passes in 3 arguments, (int voter, int rank, string name)

// Each call of the function operates as a voter, i.e. voter 0, 1, 2 and so on.
// Within the function, each 'i' iteration of the function represents a ranked vote by the voter, ie. rank 0, 1, 2 and so on.
// The function operates by:
// 1 - compare the vote (name) against 'candidates[i].name' to check if the vote is valid.
// 2 Each comparison is an iteration, and each iteration functions as an index that corresponds to the candidates name
// 3 Therefore, if the comparision is true, then the value of 'i' functions as an index, and is then inserted into the preferances array
// 4 The preferences array is denoted as 'preferences[voter][rank], as it passes in the arguments of 'voter' and 'rank' from main.

    for (int i = 0; i < candidate_count; i++)
        {
            if (strcmp(name, candidates[i].name) == 0)
                {
                    preferences[voter][rank] = i;
                    // test print
                    printf("%d, %d, %d\n", preferences[0][0], preferences[0][1], preferences[0][2]);
                    printf("%d, %d, %d\n", preferences[1][0], preferences[1][1], preferences[1][2]);
                    printf("%d, %d, %d\n", preferences[2][0], preferences[2][1], preferences[2][2]);
                    printf("preferences[i][j]: %i\n", preferences[voter][rank]);
                    printf("rank: %i\n", rank);

                return true;
                }
        }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{

// 1. Tally votes (from Pref array to Candidate.vote struct]

int i = 0;
int j = 0;

    for (i = 0; i < voter_count; i++)
        {
            for (j = 0; j < candidate_count; j++)
            {
                    if (preferences[i][0] == j) // if there is a match, candidates[i] votes = j, and then break. If no match, nothing happens.
                    {
                        candidates[j].votes += 1;

                        break;  // Once a match is found, loop can end.

                    }
            }
        }
printf("candidate name / votes: %s/%i\n", candidates[0].name, candidates[0].votes);
printf("candidate name / votes: %s/%i\n", candidates[1].name, candidates[1].votes);
printf("candidate name / votes: %s/%i\n", candidates[2].name, candidates[2].votes);
printf("candidate name / votes: %s/%i\n", candidates[3].name, candidates[3].votes);
printf("candidate name / votes: %s/%i\n", candidates[4].name, candidates[4].votes);


// Eliminate candidates with the least number of votes

int lowestvote = voter_count;
int k = 0;

    for (k = 0; k < voter_count; k++)  // loop that reviews candidate[i].votes, to find the lowest number of votes
        {
            if (candidates[k].votes <= lowestvote)
            {
                lowestvote = candidates[i].votes;
            }
        }

int l = 0;
    for (l = 0; l < candidate_count; l++)
        {
            if (candidates[l].votes == lowestvote)
            {
                candidates[l].eliminated = true;
            }
        }

printf("candidate name / eliminated: %s/%i\n", candidates[0].name, candidates[0].eliminated);
printf("candidate name / eliminated: %s/%i\n", candidates[1].name, candidates[1].eliminated);
printf("candidate name / eliminated: %s/%i\n", candidates[2].name, candidates[2].eliminated);
printf("candidate name / eliminated: %s/%i\n", candidates[3].name, candidates[3].eliminated);
printf("candidate name / eliminated: %s/%i\n", candidates[4].name, candidates[4].eliminated);

//3 Add 2nd pref votes of eliminated candidates.

// int m = 0;

// for (m = 0; m < candidate_count; m++)
// {
//     if (candidates[m].eliminated == true)
//        {
//            candidates[m].votes = 0;  // Note, check whether this overcomplicates the tally
//        }
//}

//4 Redistribution of votes for eliminated candidate

// int n = 0;

// for (n = 0; n < candidate_count; n++)
//{
//  if ((candidates[n].eliminated == true) == preferences[n][0]) // but what if an eliminated candidate received no votes at all, it won't show u p at pref[n][o]? Is a case for '||' or an 'else?'?
//    {
//        int p = 0;

//        for (p = 0; 0 < candidate_count; p++)
//        {
//              if (preferences[p][1] == p)
//              {
//                  candidates[p].votes += 1;
//             }
//        }
//    }
//}

// TO DO






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





// NOT USED
// Attempt to print the preferences array. not working.
//    int p = 0, o = 0;

//    for (p = 0; p < voter_count; p++)
//            {
//                printf("Voter:%i ", preferences[x][y]);

//                for (o = 0; o < candidate_count; o++)
//                {
//                    printf("Pref[i][j]:%i, ", preferences[x][y]);
//                }

//                printf("\n");



                            // printf("Candidate: %s: %i\n", candidates[y].name, preferences[x][y]);
                           // printf("Votes:%i\n", candidates[y].votes);
//                 printf("\n");
//                                    printf("%d, %d, %d\n", preferences[0][0], preferences[0][1], preferences[0][2]);
//                                    printf("%d, %d, %d\n", preferences[1][0], preferences[1][1], preferences[1][2]);
//                                    printf("%d, %d, %d\n", preferences[2][0], preferences[2][1], preferences[2][2]);


// tabulate print test
// int p = 0;
// for (p = 0; p < voter_count; p++)
// {
 // printf("%d, ", candidates[i].votes);
// }
