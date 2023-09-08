
grocerylist = {}

while True:
    try:
        item = input().upper()

    except EOFError:


        alphalist = sorted(grocerylist)
         # using 'sorted()' strips a dict of its values and returns a list.
         #but I can then use that list to print out the items!!!

        for a in alphalist:
            if a in grocerylist:
                print(grocerylist[a], a)

        break

    else:
        if item in grocerylist:
            grocerylist[item] = grocerylist[item] + 1
        else:
            grocerylist[item] = 1

