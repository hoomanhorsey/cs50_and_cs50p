
def main():

    tweet = input("Input: ")

    vowels = ['a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U']

    for c in tweet

        if checkvowel(c, vowels) == True:
            print("", end="")
        else:
            print(c, end="")
    print()


def checkvowel(char, vowels):
    for vowel in vowels:
        if char == vowel:
            return True



main()
