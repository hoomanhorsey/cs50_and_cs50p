# Curly brakets identifies this as a 'dictionary'
# key - value pairs
pizzas = {
    "cheese": 9,
    "pepperoni": 10,
    "vegetable": 11,
    "buffalo chicken": 12
}
# Change value of cheese pizza
pizzas["cheese"] = 8

# if pizzas["vegetabe"] < 12:
    # do something

# Adding a new key-value pair, item
pizzas["bacon"] = 12

# pie is stand in for 'i', iterates over the key
for pie in pizzas:
    print(pie)

print(f"")

# use 'pizza.items()' to be able to iterate over the values.
# Keys are iterated automatically, but must transform dictionary into a list to iterate over values(???)
for pie, price in pizzas.items():
    print(price)

print(f"")

# To print both values, need to transform into a list temporarily to be able to iterate over it
for pie, price in pizzas.items():
    print("A whole {} pizza costs ${}".format(pie, price))

for pie, prices in pizzas.items():
    print(prices)


