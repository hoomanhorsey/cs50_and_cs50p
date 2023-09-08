
def main():

# get input from user, infinite loop repeats if try conditions are met with exceptions
    while True:

        try:
            x = input("Fraction: ")

            # triggers ValueError exception
            nominator, denominator = x.split("/", maxsplit=1)
            nominator = int(nominator)
            denominator = int(denominator)

            # checks that nominator < denominator, else 'continue' reverts the loop back to 'while'
            if nominator > denominator:
                continue

            # calculates percentage, in the course of doing so creates a 'ZeroDivisionError' if demoninator is '0'
            percentage = round((nominator/denominator) * 100)

        except ValueError:
            #print("VE")
            pass

        except ZeroDivisionError:
            #print("ZDE")
            pass
        else:
            break

    # test % to determine, F, E or % to be printed out
    if percentage >= 99:
        print("F")
    elif percentage <= 1:
        print("E")
    else:
        print(percentage, "%", sep="")

def getinput(XY):
    return input(XY).split("/", maxsplit=1)

    # nominator, denominator = input("Fraction: ").split("/", maxsplit=1)

main()