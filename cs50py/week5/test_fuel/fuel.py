import sys

def main():

    percentage = convert(input("Fraction: "))

    print(gauge(percentage))

def convert(x):

    # triggers ValueError exception, if inputs aren't able to turn into ints
    nom, denom = x.split("/", maxsplit=1)
    nom = int(nom)
    denom = int(denom)

    # calculates percentage, in the course of doing so creates a 'ZeroDivisionError' if demoninator is '0'
    percentage = round((nom/denom) * 100)

    # raiss ValueError if nom > denom
    if nom > denom:
        raise ValueError
    else:
        return percentage

    # don't appear to need try/excepts here because you aren't trying to get program to reinput.
    # if the error happens, then the program ends due to the error that is triggered automatically
    # no need to print out consequences if an particular error is triggered

def gauge(percentage):

    # test % to determine, F, E or % to be printed out
    if percentage >= 99:
        return("F")
    elif percentage <= 1:
        return("E")
    else:
        return(str(percentage) + "%")

if __name__ == "__main__":
    main()






    """

while True:
    # request fraction from user
        x = input("Fraction: ")

        # pass into convert function

        try:
            x = convert(x)
            if x == "Not Suitable Int": # previously returned 'False', but this caused an error when a value of 0 was returned as well
                continue
            else:
                break

        except ValueError:
            continue




    def convert(x):

    while True:
        try:
            # triggers ValueError exception
            nom, denom = x.split("/", maxsplit=1)
            nom = int(nom)
            denom = int(denom)

            # checks that nominator < denominator, else 'continue' reverts the loop back to 'while'
            if nom > denom:
                print("IF TEST VALUE ERROR")
                return "Not Suitable Int"

            # calculates percentage, in the course of doing so creates a 'ZeroDivisionError' if demoninator is '0'
            if (nom == denom) or (denom > nom):
                print("IF TEST ZERO ERROR")

                percentage = round((nom/denom) * 100)
                return percentage

        #except NameError:
        #    print("NE")
         #   return("Not Suitable Int")

        except ValueError:
            print("VE")
            print("goingtoreturn nonsuitableint message")

            return("Not Suitable Int")

        except ZeroDivisionError:
            print("ZDE")
            return("Not Suitable Int")
        else:
            break
        """