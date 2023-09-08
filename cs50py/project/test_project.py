import pytest

# remember to change name of proejct file

# need to type command "pytest test_project.py -s -vv"
# -s allows user to input variable.  Variables to be inputted are "1" and "N", in that order.
# -vv provides info for the test results if it fails.

from project import getcitylist, getstate, selectcity, poplist



def test_getcitylist():
    assert getcitylist("Monaco") == [{'ref': 1, 'name': 'Monaco', 'state/province': None, 'country': 'Monaco', 'population': 32965, 'coordinates': {'lon': 7.41667, 'lat': 43.73333}}]

# Attempted to parametrize previous test.
@pytest.mark.parametrize("test_input, expected1", [("Monaco", [{'ref': 1, 'name': 'Monaco', 'state/province': None, 'country': 'Monaco', 'population': 32965, 'coordinates': {'lon': 7.41667, 'lat': 43.73333}}])])
def test_paramaterize_getcitylist(test_input, expected1):
    assert getcitylist(test_input) == expected1

def test_getstate():
    assert getstate([{'ref': 1, 'name': 'Monaco', 'state/province': None, 'country': 'Monaco', 'population': 32965, 'coordinates': {'lon': 7.41667, 'lat': 43.73333}}]) == [{'ref': 1, 'name': 'Monaco', 'state/province': 'Not applicable', 'country': 'Monaco', 'population': 32965, 'coordinates': {'lon': 7.41667, 'lat': 43.73333}}]


# User must enter '1' when prompted
def test_selectcity1():
    assert selectcity([{'ref': 1, 'name': 'Monaco', 'state/province': 'Not applicable', 'country': 'Monaco', 'population': 32965, 'coordinates': {'lon': 7.41667, 'lat': 43.73333}}]) == {'ref': 1, 'name': 'Monaco', 'state/province': 'Not applicable', 'country': 'Monaco', 'population': 32965, 'coordinates': {'lon': 7.41667, 'lat': 43.73333}}

# User must enter 'N' when prompted

def test_selectcityNO():
    assert selectcity([{'ref': 1, 'name': 'Monaco', 'state/province': 'Not applicable', 'country': 'Monaco', 'population': 32965, 'coordinates': {'lon': 7.41667, 'lat': 43.73333}}]) == None


def test_poplist():
    assert poplist(32965) == [{'ref': 1, 'name': 'Pirgaaj', 'state/province': None, 'country': 'Bangladesh', 'population': 34606, 'coordinates': {'lon': 88.35943, 'lat': 25.85587}}, {'ref': 2, 'name': 'Caivano', 'state/province': None, 'country': 'Italy', 'population': 34604, 'coordinates': {'lon': 14.30591, 'lat': 40.95753}}, {'ref': 3, 'name': 'San Miguel Topilejo', 'state/province': None, 'country': 'Mexico', 'population': 34603, 'coordinates': {'lon': -99.14193, 'lat': 19.20264}}, {'ref': 4, 'name': 'Steinfurt', 'state/province': None, 'country': 'Germany', 'population': 34601, 'coordinates': {'lon': 7.33664, 'lat': 52.15045}}, {'ref': 5, 'name': 'Uden', 'state/province': None, 'country': 'Netherlands', 'population': 34601, 'coordinates': {'lon': 5.61944, 'lat': 51.66083}}, {'ref': 6, 'name': 'Santa Cruz del Sur', 'state/province': None, 'country': 'Cuba', 'population': 34601, 'coordinates': {'lon': -77.99816, 'lat': 20.71633}}, {'ref': 7, 'name': 'Barcellona Pozzo di Gotto', 'state/province': None, 'country': 'Italy', 'population': 34598, 'coordinates': {'lon': 15.21469, 'lat': 38.14772}}, {'ref': 8, 'name': 'Kaneohe', 'state/province': None, 'country': 'United States', 'population': 34597, 'coordinates': {'lon': -157.79895, 'lat': 21.39994}}, {'ref': 9, 'name': 'Nakhon Phanom', 'state/province': None, 'country': 'Thailand', 'population': 34595, 'coordinates': {'lon': 104.77856, 'lat': 17.41081}}, {'ref': 10, 'name': 'Kattivakkam', 'state/province': None, 'country': 'India', 'population': 34595, 'coordinates': {'lon': 80.31667, 'lat': 13.21667}}]

