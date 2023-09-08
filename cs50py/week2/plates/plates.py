def main():
    plate = input("Plate: ")

    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")

def is_valid(s):

    # check for char number
    if (len(s) < 2) or (len(s) > 6 ):
        return False

    # check for period, spaces or punctuation marks
    for i in s:
        if (i.isalpha() != True) and (i.isdigit() != True):
            return False

    # check first two chars are alpha
    j = 0
    while j < 1:
        if (s[j].isalpha() != True):
            return False
        else:
            j = j + 1

    # The first number used cannot be a ‘0’.

    numbercount = 0
    numbers = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '0']

    for k in s:
        for n in numbers:
            if k == n:
                if numbercount == 0 and k == '0':
                    return False
                else:
                    numbercount = numbercount + 1

    # check location of numbers
    # numbers cannot be used in the middle of a plate, must come at the end.
    # For example, AAA222 would be an acceptable … vanity plate; AAA22A would not be acceptable.

y    digitcount = 0

    for l in s:

        if (l.isalpha() == True) and digitcount > 0:
            return False
        elif (l.isdigit() == True):
            digitcount = digitcount + 1

    else:
        return True


main()

