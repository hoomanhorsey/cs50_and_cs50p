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

    #test print
    print(persons[0]['AGATC'])
    print(persons[0]['name'])
    print(persons[0])


    print(persons[1]['name'])
    print(persons[1])
    #Test print
    #for nam in persons:
    #    print(nam)

    # TODO: Read DNA sequence file into a variable

    sequences = []

    fileseq = sys.argv[2]
    with open(fileseq) as f:
        reader = csv.reader(f)
        for seq in reader:
            sequences.append(seq)

#Test print of Seq
    #for seqs in sequences:
    #   print(seqs)

    # TODO: Find longest match of each STR in DNA sequence

    #Testing using 2 loops, one for each person's name, then the entry of each person.

    for name in persons: #For each
        for nom in name:
            longestrun = longest_match(sequences, nom)
            print(name)
            print(longestrun)

    print("Longest Run:",longestrun)

    for name in persons:
        for nom in name:
            print(nom)


    for name in persons:
        for nom, value in name.items():
            print(value)


    ## the function we need to call "def longest_match(sequence, subsequence):"

        #identify the sequence, from CSV  -that is the full sequence?
        #the identify the subsequence, which mataches each particular STR?

        # So likely, you will need to loop the function, with the one sequence from the cmd line,
            # but then, looping over each of the subsequences in the CSV

    #In pseudocode:
        # Loop through CSV Dictionary, to extract each STR
            #for each STR, run function.

            #Function returns the longest match






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
