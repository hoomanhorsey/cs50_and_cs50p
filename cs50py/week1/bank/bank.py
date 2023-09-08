
# Takes greeting, changes to lower case, strips leading chars if whitespace, and casts as string
greeting = str(input("Greeting: ").lower().strip())

# splits greeting so that each word is an item in a list
splitgreeting = greeting.split(" ", maxsplit=-1)


# prints $100 if greeting does not being with 'h'
if greeting[0] != "h":
    print("$100")

# identifies 'hellos' - splits greeting so that each word is an item in a list, compares to 'hello' or 'hello,'
elif (splitgreeting[0] == "hello") or (splitgreeting[0] == "hello,"):
    print("$0")

# all else are greetings that start with 'h' but aren't 'hello', so #20
else:
    print("$20")


