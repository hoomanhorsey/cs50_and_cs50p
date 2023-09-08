# Square brackets identifies this as a 'list'

# A 'list' of 'tuples', parentheses indicating beginning and end of a 'tuple'
presidents = [
    ("George Washingon", 1789),
    ("John Adams", 1797),
    ("Thomas Jefferson", 1801),
    ("James Madison", 1809)
]

for prez, year in presidents:
    print("In {1}, {0} took office".format(prez, year))

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

for pie in pizzas:
    print(pie)

n = 4
for i in range(n):
    print("?" * n)
    n = n - 1

from cs50 import get_string

before = get_string("Before:  ")
print("After:  ", end="")
for c in before:
    print(c.upper(), end="")
print()