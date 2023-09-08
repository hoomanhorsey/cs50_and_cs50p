import csv
import sys


def main():

    # DONE Checks for command-line usage

    if len(sys.argv) != 3:
        sys.exit("Incorrect number of command-line arguments: python dna.py [STR counts].csv [DNA sequence].txt")

    # DONE Reads CSV database file into a variable

    personslist = []

    filecsv = sys.argv[1]
    with open(filecsv) as f:
        reader = csv.DictReader(f)
        for i in reader:
            personslist.append(i)
    print('personslist', personslist)
    print()

    # Casts values in key:value pair as integers, but excluding the first row, which is an ascii name string value.
    # Excludes first row of names, by use of a condition that excludes values of a length greater than 3
    for rows in personslist:
        for key, values in rows.items():
            if len(values) < 3:
                rows[key] = int(rows[key])
            else:
                continue
    print('personslist - note, values are now ints', personslist)
    print()

    # DONE: Read DNA sequence file into a variable 'sequence'

    fileseq = sys.argv[2]
    with open(fileseq) as f:
        sequence = f.read()

    # DONE: Find longest match of each STR in DNA sequence
    # Uses 'longest_match' function, to return variable 'longest'
    # Uses first row of 'personslist[0]', to populate new dictionary 'longdict' with key:value pair, 'STR:Longest repeats'

    longdict = {}

    for name in personslist[0]:
        longest = longest_match(sequence, name)
        longdict[name] = longest
    print('longdict', longdict)
    print()


    # TODO: Check database for matching profiles

    # Creates a counter that counts up the total STRs to count, should be 3 for small and 8 for large.
    matchcounter = -1
    for m in longdict:
        matchcounter += 1
    print('matchcounter', matchcounter)
    print()


    # The'persons' is a list of dicts, each dict represents a 'person'. So the first loop loops through each 'person'
    # The next loop, sets out the key (dnakey) and value (dnavalue) pair of each 'person'
    # The next loop iterates through a specific key:value pair of the person, testing to see if it matches with the value of longdict at [i].
        # It then itereates thorugh each of the longdict values, and if there is a match, it adds a number to the counterdna

    tally = {}

    for person in personslist:
        counterdna = 0

        for dnakey, dnavalue in person.items():

            for i in longdict:
                if longdict[i] == dnavalue:
                    counterdna += 1
                    print('Match! -', person['name'], ' - dnakey -', dnakey, 'dnavalue', dnavalue)
                    print('longdict[i]', longdict[i])
                    print('dnavalue', dnavalue)
                    break
                elif longdict[i] != dnavalue:
                    print('No Match! -', person['name'], ' - dnakey -', dnakey, 'dnavalue', dnavalue)
            print()

                #break
                #continue

            tally[person['name']] = counterdna

    #TALLYING NEEDS TO BE WORKED ON, COULB BE OKAY THOUGH AS IT SEEMS THE TEST IS AT FAULT.

    #Iterates through tally, to count the highest number of matches.
    # Creates 'finalcounter' counter that stores the highest numer. And also corresponding variable to store name of person

        finalwinner = 0
        finalcounter = 0

        for q, v in tally.items():
            if v > finalcounter:
                finalcounter = v
                finalwinner = q

    print('tally - ',tally)
    print('finalcounter', finalcounter)

    # Final check.  If the final count is not equal to the total number of STR matches, then there will be 'no match'.
    # Otherwise, the name with the highest count will be the final winner.

    if matchcounter != finalcounter:
        print('No Match')
    else:
        print(finalwinner)

    print(longdict)


                    # at this point, create new dictionary, and then insert all the totals?
                    # then later,  iterate through that dictionary to find the person with the highest totals?
                    #then and only then, do you declare the identity of the winner??!!!







#experimenting with extracting certain values.
    #for key in persons[1]:
    #    print(key)

    #for key, values in persons[1].items():
     #   if len(values) < 3:
      #      print(int(values))
      #  else:
      #      continue

    #for key, values in persons[1].items():
    #    print(key, values)

  # for key, values in persons[1].items():
  #      if len(values) < 3:
   #         persons[1][key] = int(persons[1][key])
   #     else:
   #         continue
   # print(persons)

    #adding longdict to persons dict
    #persons.append(longdict)

    #for u in persons:
    #    for e, w in u.items():
    #        print(e , w)
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

#pseudocode
    #   loop through persons, each a 'person'
    #       loop through STRs of each 'person', starting at [1], because [0] is the 'name' and not an STR'
    #           for each of the STR values, check to see if value matches value of longdict value.
    #               if there is a match, then +1 counter, if not a match, break to next person.
    #               while loop - while count < 9, keep comparing.
    #                   but if STR value != longdict value, break
    #               if count = 8, then return 'person' name?
