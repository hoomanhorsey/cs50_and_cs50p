
def main():

    time = input("What time is it? ")

    time = convert(time)

    if 8.0 >= time >= 7.0:
        print ("breakfast time")
    elif 13.0 >= time >= 12.0:
        print ("lunch time")
    elif 19.0 >= time >= 18.0:
        print("dinner time")
    else:
        print("")


def convert(time):
    h, m = time.split(":", maxsplit = 1)
    time = float(h) + float(int(m)/60)
    return time



if __name__ == "__main__":
    main()

