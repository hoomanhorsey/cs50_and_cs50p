import re
import sys


def main():
    print(validate(input("IPv4 Address: ")))

def validate(ip):

    try:
        ip = ip.strip()

        address = re.search(r"^(\d+).(\d+).(\d+).(\d+)$", ip)
        if (int(address.group(1)) < 256) and (int(address.group(2)) < 256) and ((int(address.group(3))) < 256) and ((int(address.group(4)) < 256)):
            return True
        else:
             return False
    except AttributeError:
        return False


if __name__ == "__main__":
    main()