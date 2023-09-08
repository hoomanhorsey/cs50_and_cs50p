import sys

def main():

    try:
        if len(sys.argv) > 2:
            sys.exit("Too many command-line arguments")
        if len(sys.argv) != 2:
            sys.exit("Too few command-line arguments")

        filelen = len(sys.argv[1])

        if sys.argv[1][(filelen - 3): (filelen)] != ".py":
            sys.exit("Not a Python file")

    except FileNotFoundError:
        print("File does not exist")
        sys.exit(1)


    counter = 0
    with open (sys.argv[1]) as file:
        for line in file:
            line = line.lstrip()
            if (line.startswith("#") == True) or line == "":
                pass
            else:
                counter+=1

    print(counter)


if __name__ == "__main__":
    main()
