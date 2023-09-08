"""

In a file called um.py, implement a function called count that
- expects a line of text as input as a str and
- returns, as an int, the number of times that “um” appears in that text, case-insensitively, as a word unto itself, not as a substring of some other word.

For instance, given text like hello, um, world, the function should return 1. Given text like yummy, though, the function should return 0.

Structure um.py as follows, wherein you’re welcome to modify main and/or implement other functions as you see fit, but you may not import any other libraries. You’re welcome, but not required, to use re and/or sys.


re.findall(pattern, string, flags=0)¶
Return all non-overlapping matches of pattern in string, as a list of strings or tuples. The string is scanned left-to-right, and matches are returned in the order found. Empty matches are included in the result.

The result depends on the number of capturing groups in the pattern. If there are no groups, return a list of strings matching the whole pattern. If there is exactly one group, return a list of strings matching that group. If multiple groups are present, return a list of tuples of strings matching the groups. Non-capturing groups do not affect the form of the result.

>>>
"""
import re
import sys


def main():
    print(count(input("Text: ")))


def count(s):
    count = re.findall(r"\bum\b", s, flags=re.IGNORECASE)

    return(len(count))



if __name__ == "__main__":y
    main()


