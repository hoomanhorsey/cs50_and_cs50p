
months = [
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
]
while True:
    try:
        date = input("Date MM-DD-YYYY, Month--DD-YYYY format: ").strip() # cleans up whitespace

        # checks for date with an alpha month
        if (date[0].isalpha()):
            month, day, year = date.split()

            day, comma = day.split(",")   # split day from comma, if no comma then value error

            if (month not in months) or (int(day) > 31):
                continue

        #checks for dates with a numerical month
        elif (date[0].isdigit()) or (date(0) == "-"): # check for negative date doesn't work!
            month, day, year = date.split("/")
            if (int(month) > 12) or (int(month) < 0) or (int(day) > 31):
                continue

    except ValueError:
        pass

    else:
        break

# adds leading 0 digit to single date days
if int(day) < 10:
    day = "0" + str(day)

# uses dict index to convert month to number
if (month in months):
    month = months.index(month) + 1

# adds leading 0 digit to single date months

if int(month) < 10:
    month = "0" + str(month)

print(year, "-", month, "-", day, sep="")


