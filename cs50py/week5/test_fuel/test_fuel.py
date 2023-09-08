import pytest

from fuel import convert, gauge


def test_convert_XandYnotint():
    with pytest.raises(ValueError):
        convert("aaa/bbb")
"""
def test_ve():
    with pytest.raises(ValueError):
        convert("1/a")
def test_ve():
    with pytest.raises(ValueError):
        convert("a/1")
"""
def test_convert_incorrectints():
    assert convert("4/5") == 80

def test_convert_XandYnotint():
    with pytest.raises(ValueError):
        convert("5/2")

def test_convert_YiszeroY():
    with pytest.raises(ZeroDivisionError):
        convert("0/0")

def test_guage_Eintlessthan1():
    assert gauge(1) == "E"

def test_guageFintgreaterthan99():
    assert gauge(99) == "F"

def test_guage():
    assert gauge(50) == "50%"
