import csv
import sys


def main():

    print("")
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


    #TODO convert values to ints as they are read from CSV, but exclude the actual ascii name string value.
            #use range to exclude first row from integer casting?
            # for range(1-8)
            #   name

    #for thing in persons:
#        for j in thing:
 #           for k in range(0,8):
  #              j[k] = int(j[k])






    #test print
    print('full DNA csv as a dict')
    for nam in persons:
        print(nam)
    print("")

    # TODO: Read DNA sequence file into a variable
    # DNA sequence read into variable 'sequence'

    fileseq = sys.argv[2]
    with open(fileseq) as f:
        sequence = f.read()

    #test print sequence
    print('full dna sequence as text')
    print(sequence)

    # TODO: Find longest match of each STR in DNA sequence

    longdict = {}

    for name in persons[0]:
        longest = longest_match(sequence, name)
        # print('STR: {} - Longest run {}'.format(name, longest))
        longdict[name] = longest


    # TODO: Check database for matching profiles

    #test prints - compare details of longdict with persons
    #print("")
    #print("longdict")
    #print(longdict)
    #print("")
    #print("persons")
    #for name in persons:
    #    print(name)



    #remember to cast as int
    count = 0

    while count < 9:
        #a = persons[count]
        #b = longdict[count]
        #print ('Does {} = {}?'.format(a, b))
        count += 1


    print('Persons, DNA CSV numbers - Key:Value pairs - Dict printed out')
    for row in persons:
        for STR, personvalue in row.items():
            print("!", STR, personvalue)

    print("")

    print('Longdict Sequence. Key:Value pairs')
    for dna, seqvalue in longdict.items():
        print('?', dna, seqvalue)

    print('full DNA csv as a dict')
    for nam in persons:
        print(nam)
    print("")

    print(persons[0])
    print(persons[0]['AGATC'])
    print(persons[1])
    print(persons[2])
    print(persons[3])

    print('')
    print('longdict value for AGATC')
    print(longdict['AGATC'])

    print('')
    for x in persons:
        for y, z in x.items():
            print('key - ', y)
            print('value - ', z)

            if z == int(longdict['AGATC']):
                print('FUCKYES')
            if z == int(longdict['TTTTTTCT']):
                print('FUCKYES')
            if z == int(longdict['AATG']):
                print('FUCKYES')
            if z == int(longdict['TCTAG']):
                print('FUCKYES')
            if z == int(longdict['GATA']):
                print('FUCKYES')
            if z == int(longdict['TATC']):
                print('FUCKYES')
            if z == int(longdict['GAAA']):
                print('FUCKYES')
            if z == int(longdict['TCTG']):
                print('FUCKYES')

    # experimenting with (range)
    for i in range(1, 6):
        print(persons[i])

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


#SUCCESSFFULY CONVERTED VALUES INTO INTEGERS FOR ALL ROWs, but excluding the first row of names by creating a condition that excludes it!!!!
##!!!!

    for rows in persons:
        for key, values in rows.items():
            if len(values) < 3:
                rows[key] = int(rows[key])
            else:
                continue



  # for key, values in persons[1].items():
  #      if len(values) < 3:
   #         persons[1][key] = int(persons[1][key])
   #     else:
   #         continue
   # print(persons)

    #adding longdict to persons dict
    persons.append(longdict)

    for u in persons:
        for e, w in u.items():
            print(e , w)
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
