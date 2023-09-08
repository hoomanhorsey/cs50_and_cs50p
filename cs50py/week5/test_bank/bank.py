

def main():

    # Takes greeting, changes to lower case, strips leading chars if whitespace, and casts as string
    greeting = str(input("Greeting: "))

    # calls function with greeting as an argument
    payment = value(greeting)

    # prints the result of function
    print(f"${payment}")


def value(greeting):

    greeting = greeting.lower().strip()

    # splits greeting so that each word is an item in a list
    splitgreeting = greeting.split(" ", maxsplit=-1)
    # identifies 'hellos' - splits greeting so that each word is an item in a list, compares to 'hello' or 'hello,'
    if (splitgreeting[0] == "hello") or (splitgreeting[0] == "hello,"):
        return 0

    # all else are greetings that start with 'h' but aren't 'hello', so #20
    elif (greeting[0] == "h"):        # , [0] first letter in string
        return 20

    # everything else does not begin with 'h', so  $100
    else:
        return 100

if __name__ == "__main__":
    main()