import pytest

from numb3rs import validate


def test_letters():
    assert validate("cat") == False

def test_numbers():
    assert validate("999.999.999.999") == False


def test_5numbers():
    assert validate("999.999.999.999.999") == False

def test_1numbers():
    assert validate("123.999.999.999") == False


def test_no_numbers():
    assert validate("") == False

def test_true_numbers():
    assert validate("123.123.123.123") == True
"""
def test_letters():
    with pytest.raises(AttributeError):
        validate("cat")
"""