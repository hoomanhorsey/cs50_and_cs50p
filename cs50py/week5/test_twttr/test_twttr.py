from twttr import shorten


def test_shorten():
    assert shorten("hello") == "hll"

def test_captialized_vowel_replacement():
    assert shorten("A") == ""

def test_omission_numbers():
    assert shorten("5") == "5"

def test_omission_puncuation():
    assert shorten(",") == ","

if __name__ == "__main__":
    main()