from cs50 import get_float

# Begin Program

# Asking for float via 'while True' loop (float, greater than zero (or, will not accept inputs that are less than or equal to zero)):

while True:
    change = get_float("Change Owed: ")
    if change >= 0:
        break


# 'change' multiplies change by 100 to preserve decimal values, but so that they can be calculated as whole numbers. rounds down. then converts into integers again.
# Consequently, all the divisions following are conducted *100....dividing by 25, instead of .25.  This preserves the decimals, but carries it out via integers.
# rounds the amount to the nearest penny, i.e. .2092384723987 rounds to .20:

change = (int(round(change * 100)))

print(f"Change in whole numbers: {change}")

# Determine how many coins are needed to equal 'change' by dividing 'change' by coins in the following order and denominations of '.25', '.10', '.5' and '.1'

# 1st division, 'change' divided by '25', representing 25c.  Followed by calculating how much the remainder is:
# 'change_quarter' = how many '.25' coins, 'r1'= the remainder.
# "int' before the calculation to round result down to whole numbers, which are effectively whole coinage.

change_quarter = int(change / 25)

print(f"Change in quarters: {change_quarter}")

# Calculate remainder

remainder1 = (change % 25)

print(f"Remainder after quarters: {remainder1}")


# 2nd division, changed divided by '.10'

change_dime = int(remainder1 / 10)

# Calculate remainder

remainder2 = (remainder1 % 10)

# 3rd division, changed divided by '.05'

change_nickel = int(remainder2 / 5)

# Calculate remainder

remainder3 = (remainder2 % 5)

# 4th division, changed divided by '.01'

change_penny = int(remainder3 / 1)

# Calculate remainder

remainder4 = remainder3 % 1

# Print how many coins are required.

coins = change_quarter + change_dime + change_nickel + change_penny
print(f"{coins}")