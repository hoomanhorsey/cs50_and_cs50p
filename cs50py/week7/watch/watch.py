"""
In a file called watch.py,

- implement a function called parse that
    - expects a str of HTML as input,
    - extracts any YouTube URL that’s the value of a src attribute of an iframe element therein, and
    - returns its shorter, shareable youtu.be equivalent as a str.

- Expect that any such URL will be in one of the formats below.
- Assume that the value of src will be surrounded by double quotes.
- And assume that the input will contain no more than one such URL.

If the input does not contain any such URL at all, return None.

http://youtube.com/embed/xvFZjo5PgG0
https://youtube.com/embed/xvFZjo5PgG0
https://www.youtube.com/embed/xvFZjo5PgG0

Structure watch.py as follows, wherein you’re welcome to modify main and/or implement other functions as you see fit, but you may not import any other libraries. You’re welcome, but not required, to use re and/or sys.
"""

import re
import sys


def main():
    print(parse(input("HTML: ")))


def parse(s):

    match = re.search(r"^<iframe\s(?:width=\"\d\d\d\"\sheight=\"\d\d\d\"\s)?(?:src=\")https?://(?:www.)?youtube.com/embed/(\w+)\"", s)

    try:
        address = match.group(1)

    except AttributeError:
        return None

    return("https://youtu.be/" + address)






if __name__ == "__main__":
    main()