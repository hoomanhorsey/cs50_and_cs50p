import pytest
import datetime
from seasons import getdate, calcdate

today = datetime.date.today()
year = datetime.timedelta(days=365)
less_one_year = today - year
less_two_year = today - (year * 2)


def test_oneyear():
    assert calcdate(less_one_year) == "Five hundred twenty-five thousand, six hundred"

def test_twoyear():
    assert calcdate(less_two_year) == "One million, fifty-one thousand, two hundred"

def test_wrongformat():
    with pytest.raises(SystemExit):
        assert getdate("12 January 2021")