"""

In a file called working.py, implement a function called convert that

- expects a str in either of the 12-hour formats below and
- returns the corresponding str in 24-hour format (i.e., 9:00 to 17:00).

Expect that
- AM and PM will be capitalized (with no periods therein) and
- that there will be a space before each.

Assume that these times are representative of actual times, not necessarily 9:00 AM and 5:00 PM specifically.

- 9:00 AM to 5:00 PM
- 9 AM to 5 PM

Raise a ValueError instead if
- the input to convert is not in either of those formats or
- if either time is invalid (e.g., 12:60 AM, 13:00 PM, etc.).

But do not assume that someone’s hours will start ante meridiem and end post meridiem; someone might work late and even long hours (e.g., 5:00 PM to 9:00 AM).

Structure working.py as follows, wherein you’re welcome to modify main and/or implement other functions as you see fit, but you may not import any other libraries. You’re welcome, but not required, to use re and/or sys.

"""
import re
import sys

def main():
    print(convert(input("Hours: ")))

def convert(s):
    if re.search(r"^(\d\d?)(?::)?(\d\d?)?\s(?:AM|PM)\sto\s(\d\d?)(?::)?(\d\d?)?\s(?:AM|PM)", s):
        pass

    else:
        raise ValueError

    try:
        matches =  re.search(r"^(\d\d?)(?::)?(\d\d?)?\s(AM|PM)?\sto\s(\d\d?)(?::)?(\d\d?)?\s(AM|PM)?", s)

        # test for invalid values, ie. 12 60am, 13:00pm
        starth = matches.group(1)
        startm = matches.group(2)
        startmerid = matches.group(3)
        endh = matches.group(4)
        endm = matches.group(5)
        endmerid = matches.group(6)

        #if starth == "12" or "12:00":
        #    starth = "0"
        #if endh == "12" or "12:00":
        #    endh = "0"



    except ValueError:
        sys.exit(ValueError)
    if startm == None:
        if (int(starth) > 12) or (int(endh) > 12):
            raise ValueError

    # checking that types are within hour/min limits
    else:
        if (int(starth) > 12) or (int(endh) > 12) or (int(startm) > 59) or (int(endm) > 59):
            raise ValueError


    # checking for meridien to determine conversion, accounting for 24 hour time
    if startmerid == "AM":
        if (starth == "12"):
            starth = "00"
        else:
            starth = "0" + starth
    else:
        if starth != 12:
            starth = int(starth) + 12
        else:
            starth = "12"

    if endmerid == "AM":
        if endh == "12":
            endh = "00"
        else:
            endh = "0" + endh
    else:
        if endh != "12":
            endh = int(endh) + 12
        else:
            endh = "12"




    if startm == None:
        return(f"{starth}:00 to {endh}:00")
    else:
        return(f"{starth}:{startm} to {endh}:{endm}")


if __name__ == "__main__":
    main()



"""
#PSUEDO CODE
    - CHECK AM or PM of time
    - Check that time is actually valid, else value error
    - convert 12 hour time to 24 eqivalent
    return

"""
