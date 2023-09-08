import pytest
from jar import Jar




def test_init():
    jar = Jar()
    assert jar.capacity == 12

def test_str():
    jar = Jar()
    assert str(jar) == ""
    jar.deposit(1)
    assert str(jar) == "🍪"
    jar.deposit(11)
    assert str(jar) == "🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪"

def test_deposit():
    jar = Jar()
    jar.deposit(5)
    assert jar.size == 5
    with pytest.raises(ValueError):
        assert jar.deposit(20)

def test_withdraw():
    jar = Jar()
    jar._size = 5
    jar.withdraw(2)
    assert jar._size == 3
    with pytest.raises(ValueError):
        assert jar.withdraw(10)

