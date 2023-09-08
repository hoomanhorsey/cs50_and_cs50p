"""
In a file called seasons.py, implement a program that:
- prompts the user for their date of birth in YYYY-MM-DD format and
- then sings prints how old they are
    - in minutes,
    - rounded to the nearest integer,
    - using English words instead of numerals,
    - just like the song from Rent, without any and between words.

Since a user might not know the time at which they were born, assume, for simplicity, that:
- the user was born at midnight (i.e., 00:00:00) on that date. And:
- assume that the current time is also midnight.
In other words, even if the user runs the program at noon, assume that it’s actually midnight, on the same date.

Use datetime.date.today to get today’s date, per docs.python.org/3/library/datetime.html#datetime.date.today.

Structure your program per the below, not only with a main function but also with one or more other functions as well:
"""
import datetime
import inflect
import re
import sys

p = inflect.engine()

def main():
    date = input("Date of Birth (YYYY-MM-DD)")

    birthday = getdate(date)
    total = calcdate(birthday)
    print(total, "minutes")

def calcdate(birthday):

    today = datetime.date.today()
    deltadays = today - birthday
    deltamins = deltadays.days * 1440
    total = p.number_to_words(deltamins, andword="").capitalize()
    return(total)

def getdate(date):

    if re.search("\d\d\d\d-\d\d-\d\d", date):
        year, month, day = (date.split("-"))
        year, month, day = int(year), int(month), int(day)
        birthday = datetime.date(year, month, day)
        return birthday

    else:
        sys.exit(1)

if __name__ == "__main__":
    main()