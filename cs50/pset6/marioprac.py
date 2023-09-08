for i in range(n):

    for j in range((n - 1) - i):
        print("*", end="")

    for k in range((n + 1) - (n - i)):
        print("@", end="")

    print("SS", end="")

    for m in range((n + 1) - (n - i)):
        print("#", end="")
    print("")




for i in range(n):
    j = 1
    for j in range(n - (n - i)):
        print("*", end="")

    for k in range(n - (n - i)):
        print("@", end="")

    z = 1
    for z in range(n - (n - i)):
        print("SS", end="")

    m = 0
    for m in range(n - (n - i)):
        print("#", end="")

    y = 1
    for y in range(n - (n - i)):
        print("")





