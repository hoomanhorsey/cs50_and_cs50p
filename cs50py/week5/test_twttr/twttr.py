
def main():

    tweet = input("Input: ")

    print(shorten(tweet))

def shorten(tweet):

    vowels = ['a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U']
    newtweet = []

    #check for vowel, if not a vowel add to newtweet list
    for char in range(len(tweet)):
        if tweet[char] not in vowels:
            newtweet.append(tweet[char])

    #change from list to string
    tweet = "".join(newtweet)
    return(tweet)


if __name__ == "__main__":
    main()


