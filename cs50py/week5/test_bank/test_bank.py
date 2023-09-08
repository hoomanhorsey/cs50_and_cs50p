from bank import value
import pytest

#change names of test

def test_hello():
    assert value("hello") == 0

def test_h():
    assert value("h") == 20

def test_excluding_h():
    list = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'i',]
    for i in list:
        value(i) == 100

# So the following are confusing...
# they didn't work for ages until I realised that when you clean up the parameter for a function before it goes into the function
# then when you insert it into the function in the test, it goes in without being stripped of space, or case
# insensitivity.  So best practice is to treat variables and clean them up as they enter a function to ensure
# that they are fit for processing. That lesson took about 2 hours!


def test_caseinsensitive():
    assert value("H") == 20

def test_entirephrase():
    assert value("Hello, how are you sir?") == 0

if __name__ == "__main__":
    main()
