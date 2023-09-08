# Optional way of importing specific function, "from cs50 import get_int"

# Must prefix function with library, if importing entire library "cs50.get_int"

import cs50

while True:
    h = cs50.get_int("Height: ")
    if (h > 0) and (h < 9):
        break

# Note, 'i' iterator starts at 0.  The math gets a bit tricky as it has to accomodate the iterator starting at 1.
for i in range(h):

    # Print first space
    for j in range((h - 1) - i):
        print(" ", end="")

    # Print first hash
    for k in range((h + 1) - (h - i)):
        print("#", end="")

    # Print double empty space
    print("  ", end="")

    # Print second hash
    for m in range((h + 1) - (h - i)):
        print("#", end="")

    # Print new line
    print("")

