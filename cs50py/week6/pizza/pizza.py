"""

In a file called pizza.py, implement a program that

- expects exactly one command-line argument,the name (or path) of a CSV file in Pinocchio’s format, and
- outputs a table formatted as ASCII art using tabulate, a package on PyPI at pypi.org/project/tabulate.

Format the table using the library’s grid format.

If the user:
- does not specify exactly one command-line argument, or
- if the specified file’s name does not end in .csv, or
- if the specified file does not exist, the program should instead exit via sys.exit.

"""
import sys
import csv
from tabulate import tabulate

def main():

    try:
        if len(sys.argv) > 2:
            sys.exit("Too many command-line arguments")
        if len(sys.argv) != 2:
            sys.exit("Too few command-line arguments")

        filelen = len(sys.argv[1])

        if sys.argv[1][(filelen - 4): (filelen)] != ".csv":
            sys.exit("Not a csv file")

    except FileNotFoundError:
        print("File does not exist")
        sys.exit(1)

    # Extracting header as a list using csv.reader
    header = []
    with open(sys.argv[1]) as file:
        thisreader = csv.reader(file)
        for item in thisreader:
            header.append(item)

    # Exctracting csv file, using csv.dictreader
    menu = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file, fieldnames = (header[0]))
        for row in reader:
            menu.append(row)

    print(tabulate(menu, headers="firstrow",  tablefmt="grid"))
    print()

if __name__ == "__main__":
    main()