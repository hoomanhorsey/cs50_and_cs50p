

def main():

    text = input("Give us a smile darlin' ")

    text = convert(text)

    print(text)


def convert(text):

    text = text.replace(":)", "🙂")
    text = text.replace(":(", "🙁")

    return text


main()