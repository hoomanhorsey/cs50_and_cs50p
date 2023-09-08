
def main():

    menu = {
        "Baja Taco": 4.00,
        "Burrito": 7.50,
        "Bowl": 8.50,
        "Nachos": 11.00,
        "Quesadilla": 8.50,
        "Super Burrito": 8.50,
        "Super Quesadilla": 9.50,
        "Taco": 3.00,
        "Tortilla Salad": 8.00
    }

    subtotal = 0.00

    while True:
        try:
            item = input("Item: ").title()
            itemprice = float(menu.get(item))

        except TypeError:
            pass

        except EOFError:
            print()
            printtotal = format(subtotal, '.2f')
            print("$", printtotal, sep="")
            break

        else:
            subtotal = subtotal + itemprice
            printtotal = format(subtotal, '.2f')
            print("$", printtotal, sep="")

main()
