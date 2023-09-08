
import random

def main():

    # Request level from user
    level = get_level()

    print(level)

    # reset score
    score = 0

    # set problem limit to 10
    problems = 0
    while problems < 9:

        algo = []
        algo.append(generate_integer(level))
        algo.append(generate_integer(level))

        # sets while loop limited at 3 attempts
        attempts = 0
        while attempts < 3:

            try:
                answer = int(input(f"{algo[0]} + {algo[1]} = "))    # asks the problem

                if answer == algo[0] + algo [1]:                    # adds +1 to score if correct, breaks
                    problems+= 1
                    score +=1
                    break

            except ValueError:
                attempts+=1                                         # adds +! to attemp for non int answer
                print("EEE")
                continue

            else:
                if attempts == 2:
                    print(f"{algo[0]} + {algo[1]} = {algo[0] + algo[1]}")   # print solution if attempts exhausted
                    break
                else:
                    attempts+= 1                                    # prints error if incorrect, and adds +1 to attempts
                    print("EEE")
                    continue

    print("Score: ", score)


#Prompt for level
def get_level():

    while True:

        try:
            level = int(input("Level: "))
            if (4 > level > 0):
                return level
        except ValueError:
            continue

# Randomly generates 10 problems
def generate_integer(level):

    start = 0
    if level == 1:
        start = 0
        level = 10
    elif level == 2:
        start = 10
        level = 100
    else:
        start = 100
        level = 999

    return random.randint(start, level)



if __name__ == "__main__":
    main()






"""
Mini plan for program flow

Ask 10 problems:

    Ask problem n, only up to 3 times:
        -      if correct:
                    - add 1 to 'score',
                    - break

        -      else,
                    if incorrect = 3 times, print solution,
                    else:
                        try again + 1 to attempts


"""