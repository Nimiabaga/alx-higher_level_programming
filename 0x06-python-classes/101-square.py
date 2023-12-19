#!/usr/bin/python3
"""class Square definition"""


class Square:
    """square representation"""

    def __init__(self, size=0, position=(0, 0)):
        """new square initialization"""
        self.size = size
        self.position = position

    @property
    def size(self):
        """set size"""
        return self.__size

    @size.setter
    def size(self, value):
        if not isinstance(value, int):
            raise TypeError("size must be an integer")
        elif value < 0:
            raise ValueError("size must be >= 0")
        self.__size = value

    @property
    def position(self):
        """set position"""
        return self.__position

    @position.setter
    def position(self, value):
        if (not isinstance(value, tuple) or
                len(value) != 2 or
                not all(isinstance(num, int) for num in value) or
                not all(num >= 0 for num in value)):
            raise TypeError("position must be a tuple of 2 positive integers")
        self.__position = value

    def area(self):
        """return square area"""
        return self.__size * self.__size

    def my_print(self):
        """square printed with #"""
        if self.__size == 0:
            print("")
            return

        [print("") for u in range(0, self.__position[1])]
        for u in range(0, self.__size):
            [print(" ", end="") for v in range(0, self.__position[0])]
            [print("#", end="") for w in range(0, self.__size)]
            print("")

    def __str__(self):
        """print rep. of a square defined"""
        if self.__size != 0:
            [print("") for u in range(0, self.__position[1])]
        for u in range(0, self.__size):
            [print(" ", end="") for v in range(0, self.__position[0])]
            [print("#", end="") for w in range(0, self.__size)]
            if u != self.__size - 1:
                print("")
        return ("")
