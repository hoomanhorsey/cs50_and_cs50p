import pytest
from um import count


def test_correct():
    assert count("um") == 1

def test_correct_punct():
    assert count("um?") == 1

def test_correct_expressioncaseinsensitive():
    assert count("Um, thanks for the album.") == 1

def test_correct_expressionandpunctspaces():
    assert count("Um, thanks, um....") == 2

