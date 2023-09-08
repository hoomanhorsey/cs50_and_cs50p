from cs50 import get_string

# Get and print string
text = get_string("Text: ")

# Lettercount

lettertally = 0
wordtally = 1
sentencetally = 0
# Go through each letter, counting each letter, if it is a letter, add one to letter talley

for i in range(len(text)):
    if ((ord(text[i]) >= 65) and (ord(text[i]) <= 90) or ((ord(text[i]) >= 97) and (ord(text[i]) <= 122))):
        lettertally += 1
    if ord(text[i]) == 32:
        wordtally += 1
    if ((ord(text[i]) == 33) or (ord(text[i]) == 46) or (ord(text[i]) == 63)):
        sentencetally += 1

print(f"letter talley: {lettertally}")
print(f"word tally: {wordtally}")
print(f"sentence tally: {sentencetally}")

# Calculate readability
# L is the average number of letters per 100 words in the text
# S is the average number of sentences per 100 words in the text.
# index = 0.0588 * L - 0.296 * S - 15.8

L = ((lettertally / wordtally) * 100.00)

S = ((sentencetally / wordtally) * 100.00)

index = ((0.0588 * L) - (0.296 * S) - 15.8)

if (index >= 16):
    print("Grade 16+")

elif (index < 1):
    print("Before Grade 1")

elif ((index >= 1) or (index < 16)):
    print(f"Grade {int(round(index))}")