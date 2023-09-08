
import sys
import csv


def main():


    getinput()


    temp = [{"first": "first", "last": "last", "house": "house"}] # inserting header

    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)

        for row in reader:
            last, first = (row['name']).split(",")
            first = first.strip()
            last = last.strip()
            temp.append({"first": first, "last": last, "house": row['house']})

    with open(sys.argv[2], "w", newline='') as writefile:
        writer = csv.DictWriter(writefile, fieldnames=["first", "last", "house"])
        for trow in temp:
            writer.writerow({"first": trow['first'], "last": trow['last'], "house": trow['house']})


def getinput():

    try:
        if len(sys.argv) > 3:
            sys.exit("Too many command-line arguments")
        if len(sys.argv) != 3:
            sys.exit("Too few command-line arguments")

        filelen = len(sys.argv[1])

        if sys.argv[1][(filelen - 4): (filelen)] != ".csv":
            sys.exit("Not a csv file")

    except FileNotFoundError:
        print("Could not read invalid_file.csv")
        sys.exit(1)

    else:
        return



if __name__ == "__main__":
    main()


