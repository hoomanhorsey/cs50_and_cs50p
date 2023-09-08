"""In a file called game.py, implement a program that:

Prompts the user for a level,
n
. If the user does not input a positive integer, the program should prompt again.
Randomly generates an integer between 1 and n, inclusive, using the random module.
Prompts the user to guess that integer. If the guess is not a positive integer, the program should prompt the user again.
If the guess is smaller than that integer, the program should output Too small! and prompt the user again.
If the guess is larger than that integer, the program should output Too large! and prompt the user again.
If the guess is the same as that integer, the program should output Just right! and exit.
"""

"""
Prompt for level

- Prompt for level_int, check for int,

[While True]

Prompt for guess
- Prompt for guess_int ('gi'), check for int, check gi > 0, gi < n +1

- select random number ('rn')

- check number

check, if gi > rn,
    Too large
    continue

check, if gi < rn
    Too small
    continue

else:
    Just right,
    exit
    break
"""

import random

while True:

    try:
        level = int(input("Level: "))
        if level < 1:
            continue
        else:
            break

    except ValueError:
        continue

rn = random.randint(1, level)

while True:

    try:
        guess = int(input("Guess: "))
        if guess < 1:
            continue

    except ValueError:
        continue

    else:
        if guess > rn:
            print("Too large!")
        elif guess < rn:
            print("Too small!")
        else:
            print("Just right!")
            break



