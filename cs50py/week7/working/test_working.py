import pytest

from working import convert




def test_text():
    with pytest.raises(ValueError):
        convert("9 AM - 5 PM")

def test_wrongformat():
    with pytest.raises(ValueError):
        convert("09:00 AM - 17:00 PM")

def test_wrongminutes():
    with pytest.raises(ValueError):
        convert("9:60 AM to 5:60 PM")

def test_wronghours():
    with pytest.raises(ValueError):
        convert("14 AM to 5 PM")

def test_correcttimeshort():
    assert convert("9 AM to 5 PM") == "09:00 to 17:00"

def test_correcttimelong():
    assert convert("10:30 PM to 8:50 AM") == "22:30 to 08:50"


