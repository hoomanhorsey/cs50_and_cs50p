"""
Suppose that you’d like to implement a cookie jar in which to store cookies. In a file called jar.py, implement a class called Jar with these methods:

    - __init__ should initialize a cookie jar with the given capacity, which represents the maximum number of cookies that can fit in the cookie jar. If capacity is not a non-negative int, though, __init__ should instead raise a ValueError.
    - __str__ should return a str with n 🍪, where 'n' is the number of cookies in the cookie jar. For instance, if there are 3 cookies in the cookie jar, then str should return "🍪🍪🍪"
    - deposit should add n cookies to the cookie jar. If adding that many would exceed the cookie jar’s capacity, though, deposit should instead raise a ValueError.
    - withdraw should remove n cookies from the cookie jar. Nom nom nom. If there aren’t that many cookies in the cookie jar, though, withdraw should instead raise a ValueError.
    - capacity should return the cookie jar’s capacity.
    - size should return the number of cookies actually in the cookie jar.

Structure your class per the below. You may not alter these methods’ parameters, but you may add your own methods.
"""


class Jar:
    def __init__(self, capacity=12):
        self.capacity = capacity
        self._size=0

    def __str__(self):
        cookies = ""
        for _ in range(int(self.size)):
            cookies += "🍪"
        return cookies

    def deposit(self, n):
        if (self._size + n) > self.capacity:
                raise ValueError("Number of cookies exceeds jar capacity")
        self._size = self._size + n
        return self._size

    def withdraw(self, n):
        if (self._size - n) < 0:
                raise ValueError("Number of cookies withdrawn greater than number of cookies stored")
        self._size = self._size - n

    #Getter for capacity
    @property
    def capacity(self):
        return self._capacity

   #Setter for capacity
    @capacity.setter
    def capacity(self, capacity):
        if ((not capacity) or (capacity < 0)):
            raise ValueError("Negative capacity in cookie jar") # raises ValueError if 'capacity' < 0
        self._capacity = capacity

    #Getter for size
    @property
    def size(self):
        return self._size

    #Setter for size
    @size.setter
    def size(self):
        self._size = 0

def main():

    n = int(input("Coins: "))

    cookiejar = Jar()
    cookiejar.deposit(n)

    print(cookiejar)

    print("Capacity: ", cookiejar.capacity)
    print("Cookies: ", cookiejar.size)

if __name__ == "__main__":
    main()