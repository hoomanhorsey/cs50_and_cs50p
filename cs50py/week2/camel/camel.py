
text = input("camelCase: ")

for i in text:
    if i.isupper():
        print("_" + i.lower(), end="")
    else:
        print(i, end="")
print()

