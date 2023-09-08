from pyfiglet import Figlet
import sys
import random

figlet = Figlet()

fontlist = figlet.getFonts()

if (len(sys.argv) == 1):
    text = input("Input: ")
elif (len(sys.argv) == 3):
    if (sys.argv[1] == ("-f" or "-font") ) and (sys.argv[2] in fontlist):
        text = input("Input: ")
    else:
        sys.exit("Invalid usage")

else:
    sys.exit("Invalid usage")

if len(sys.argv) == 1:
    randofont = random.choice(fontlist)
    figlet.setFont(font=randofont)
    print(figlet.renderText(text))

else:
        f = sys.argv[2]
        figlet.setFont(font=f)
        print(figlet.renderText(text))
