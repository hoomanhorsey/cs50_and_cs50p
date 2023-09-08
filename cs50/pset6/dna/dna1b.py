import csv
import sys


def main():

    # DONE Check for command-line usage

    if len(sys.argv) != 3:
        sys.exit("Incorrect number of command-line arguments: python dna.py [STR counts].csv [DNA sequence].txt")

    #TODO:Read database file into a variable

    #Database file read into variable 'persons'
    persons = []

    filecsv = sys.argv[1]
    with open(filecsv) as f:
        reader = csv.DictReader(f)
        for name in reader:
            persons.append(name)

    #test print
    #print(persons[0]['AGATC'])
    #print(persons[0]['name'])
    #print(persons[0])

    #print(persons[1]['name'])
    #print(persons[1])
    #Test print
    #for nam in persons:
    #    print(nam)

    # TODO: Read DNA sequence file into a variable
    # DNA sequence read into variable 'sequence'

    fileseq = sys.argv[2]
    with open(fileseq) as f:
        sequence = f.read()
    #test print sequence
    #print(sequence)

    # TODO: Find longest match of each STR in DNA sequence

    print('Person 0')
    print(persons[0])

    longdict = {}

    for name in persons[0]:
        #print(name)
        longest = longest_match(sequence, name)
        # print('STR: {} - Longest run {}'.format(name, longest))
        longdict[name] = longest



        #TO IMPELEMNET
        #Now you just want to implement the results of the test in a new dictionary, with key-value relationships.
        #So that you can compare this with the database later.



    #for name in persons:
    #       print(name)

    #longestrun = longest_match(sequence, 'AGATC')
    #print(longestrun)

    #longestrun = longest_match(sequence, 'TTTTTTCT')
    #print(longestrun)

    #Testing using 2 loops, one for each person's name, then the entry of each person.

    #for name in persons: #For each
        #print (name)
        #for nom in name:
            #longestrun = longest_match(sequence, nom)
            #print(name)
            #print(longestrun)

    #print("Longest Run:",longestrun)

    #for name in persons:
        #for nom in name:
            #print(nom)

    #for name in persons:
        #for nom, value in name.items():
            #print(value)

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

    #compare details of longdict with persons
    print("")
    print("longdict")
    print(longdict)
    print("")
    print("persons")
    for name in persons:
        print(name)

    #pseudocode
    #   loop through persons, each a 'person'
    #       loop through STRs of each 'person', starting at [1], because [0] is the 'name' and not an STR'
    #           for each of the STR values, check to see if value matches value of longdict value.
    #               if there is a match, then +1 counter, if not a match, break to next person.
    #               while loop - while count < 9, keep comparing.
    #                   but if STR value != longdict value, break
    #               if count = 8, then return 'person' name?

    #remember to cast as int
    count = 0

    while count < 9:
        #a = persons[count]
        #b = longdict[count]
        #print ('Does {} = {}?'.format(a, b))
        count += 1

    for row in persons:
        for STR, value in row.items():
            print(STR, value)

            #if int(value) == longdict(value)):
            count += 1

    #while count < 9:


    print("")
    print('Match Print Test')
    print(longdict['name'])
    print(persons[0]['name'],"-", value)

    counter = 0
    while counter < 9:
        #a = persons[count]
        #b = longdict[count]
        #print ('Does {} = {}?'.format(a, b))
        for name, value in longdict.items():
            print(value)
        print(persons[counter]['name'])
        counter += 1

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
