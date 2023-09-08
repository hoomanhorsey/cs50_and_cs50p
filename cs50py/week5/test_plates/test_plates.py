import pytest

from plates import is_valid

# check for char number
def test_charnumber():
    assert is_valid("A") == False
    assert is_valid("AAAAAAA") == False

# check for period, spaces or punctuation marks
def test_punctuation():
    assert is_valid("AAA,AA") == False
    assert is_valid("AAA AA") == False
    assert is_valid("AAA.AA") == False
# check first two chars are alpha

def test_firsttwoalpha():
    assert is_valid("12") == False
    assert is_valid("A2") == False
    assert is_valid("1A") == False
    assert is_valid("AA") == True

# The first number used cannot be a ‘0’.

def test_firstnumbernotzero():
    assert is_valid("AA0123") == False
    assert is_valid("AAA012") == False
    assert is_valid("AAAA01") == False
    assert is_valid("AAAA10") == True

 # check location of numbers
    # numbers cannot be used in the middle of a plate, must come at the end.
    # For example, AAA222 would be an acceptable … vanity plate; AAA22A would not be acceptable.

def test_numberlocation():
    assert is_valid("AA12AA") == False
    assert is_valid("AA123A") == False
    assert is_valid("AAAA12") == True


if __name__ == "__main__":
    main()
