import csv
import sys


def main():

    # DONE Check for command-line usage

    if len(sys.argv) != 3:
        sys.exit("Incorrect number of command-line arguments: python dna.py [STR counts].csv [DNA sequence].txt")


    #TODO:Read database file into a variable

    persons = []

    filecsv = sys.argv[1]
    with open(filecsv) as f:
        reader = csv.DictReader(f)
        for name in reader:
            persons.append(name)

    #print(persons[0]['name'])
    #print(persons[1]['name'])

    for nam in persons:
        print(nam)

    #Create empty list
    #for name in persons:

    ## Print and access experiments.
    #for team in teams:
    #    if team["rating"] < 1000:
    #        print("Loser team, with rating less than 1000, is", team["team"])
    #print("Full dictionary, for teams[0]", teams[0])
    #print(teams[0]['team'])
    #print(teams[0]['rating'])

    # TODO: Read DNA sequence file into a variable

    sequences = []

    fileseq = sys.argv[2]
    with open(fileseq) as g:
        seqreader = csv.reader(g)
        for seq in seqreader:
            sequences.append(seq)

    for seqs in sequences:
        print(seqs)




    # TODO: Find longest match of each STR in DNA sequence

    # TODO: Check database for matching profiles

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
