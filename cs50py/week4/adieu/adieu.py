
import inflect

p = inflect.engine()

namelist = []

while True:

    try:
        name = input("Name: ")
        namelist.append(name)

    except EOFError:
        print()
        break

namelist = p.join(namelist)
print("Adieu, adieu, to " + namelist)
