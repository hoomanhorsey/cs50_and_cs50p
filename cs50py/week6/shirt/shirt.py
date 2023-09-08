"""
In a file called shirt.py, implement a program that expects exactly two command-line arguments:

in sys.argv[1], the name (or path) of a JPEG or PNG to read (i.e., open) as input
in sys.argv[2], the name (or path) of a JPEG or PNG to write (i.e., save) as output

The program should then overlay shirt.png (which has a transparent background) on the input after resizing and cropping the input to be the same size, saving the result as its output.

Open the input with Image.open, per pillow.readthedocs.io/en/stable/reference/Image.html#PIL.Image.open, resize and crop the input with ImageOps.fit, per pillow.readthedocs.io/en/stable/reference/ImageOps.html#PIL.ImageOps.fit, using default values for method, bleed, and centering, overlay the shirt with Image.paste, per pillow.readthedocs.io/en/stable/reference/Image.html#PIL.Image.Image.paste, and save the result with Image.save, per pillow.readthedocs.io/en/stable/reference/Image.html#PIL.Image.Image.save.

The program should instead exit via sys.exit:

if the user does not specify exactly two command-line arguments, TODO DONE
if the input’s and output’s names do not end in .jpg, .jpeg, or .png, case-insensitively, TODO DONE
if the input’s name does not have the same extension as the output’s name, or TODO DONE
if the specified input does not exist. TODO "FILE NOT FOUND" DONE>
Assume that the input will be a photo of someone posing in just the right way, like these demos, so that, when they’re resized and cropped, the shirt appears to fit perfectly.

If you’d like to run your program on a photo of yourself, first drag the photo over to VS Code’s file explorer, into the same folder as shirt.py. No need to submit any photos with your code. But, if you would like, you’re welcome (but not expected) to share a photo of yourself wearing your virtual shirt in any of CS50’s communities!

"""
import os
import sys
from PIL import Image, ImageOps

def main():

    getinput()

    shirt = Image.open("shirt.png")

    try:
        personimage  = Image.open(sys.argv[1])

    except FileNotFoundError:
        sys.exit("Input does not exist")

    shirtsize = shirt.size



    personimage = ImageOps.fit(personimage, shirtsize, method=Image.BICUBIC, bleed=0, centering=(0.5, 0.5))


    shirt = ImageOps.fit(shirt, shirtsize, method=Image.BICUBIC, bleed=0, centering=(0.5, 0.5))


    #personimage = ImageOps.fit(personimage, (800, 800), method=Image.BICUBIC, bleed=0, centering=(0.5, 0.5))


    #shirt = ImageOps.fit(shirt, (800,800), method=Image.BICUBIC, bleed=0, centering=(0.5, 0.5))

    personimage.paste(shirt, shirt)
    personimage.save(sys.argv[2])


def getinput():

    if len(sys.argv) > 3:
        sys.exit("Too many command-line arguments")
    if len(sys.argv) != 3:
        sys.exit("Too few command-line arguments")

    _, ext1 = os.path.splitext(sys.argv[1])
    _, ext2 = os.path.splitext(sys.argv[2])

    filetypes = ['.jpeg', '.jpg', '.png']

    if (ext2 not in filetypes):
        sys.exit("Invalid output")

    if ext1 != ext2:
        sys.exit("Input and output have different extensions")

    return

if __name__ == "__main__":
    main()

