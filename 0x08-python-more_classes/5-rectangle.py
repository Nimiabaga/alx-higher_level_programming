#!/usr/bin/python3
"""class Rectangle that defines a rectangle"""


class Rectangle:
    """class rectangle"""

    def __init__(self, width=0, height=0):
        """initialize rectangle"""
        self.__width = width
        self.__height = height

    @property
    def width(self):
        return self.__width

    @width.setter
    def width(self, value):
        """put width"""
        self.__width = value
        try:
            assert type(self.__width) == int
        except BaseException:
            raise TypeError("width must be an integer")
        if self.__width < 0:
            raise ValueError("width must be >= 0")

    @property
    def height(self):
        return self.__height

    @height.setter
    def height(self, value):
        """put height"""
        self.__height = value
        try:
            assert type(self.__height) == int
        except BaseException:
            raise ValueError("height must be >= 0")

    def area(self):
        """Return area"""
        return self.__width * self.__height

    def perimeter(self):
        """Return perimeter"""
        if self.__height == 0 or self.__width == 0:
            return 0
        return self.__width * 2 + self.__height * 2

    def __str__(self):
        """rectangle representation with the # character"""
        if self.__width == 0 or self. __height == 0:
            return ""
        for u in range(self.__height):
            for v in range(self.__width):
                print("#", end="")
            print()
        return ""

    def __repr__(self):
        rec = "Rectangle(" + str(self.__width)
        rec += ", " + str(self.__height) + ")"
        return rec

    def __del__(self):
        """delete rectangle/print message"""
        print("Bye rectangle...")
