#!/usr/bin/python3
"""class Rectangle that defines a rectangle by"""


class Rectangle:
    """class rectangle"""
    number_of_instances = 0
    print_symbol = '#'

    def __init__(self, width=0, height=0):
        """initialize rectangle"""
        self.__width = width
        self.__height = height
        Rectangle.number_of_instances += 1

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
        """rectangle representation with # character"""
        if self.__width == 0 or self. __height == 0:
            return ""
        for u in range(self.__height):
            for v in range(self.__width):
                print(self.print_symbol, end="")
            if u != self.__height - 1:
                print()
        return ""

    def __repr__(self):
        """Return str"""
        rec = "Rectangle(" + str(self.__width)
        rec += ", " + str(self.__height) + ")"
        return rec

    def __del__(self):
        """delete rectangle/print message"""
        type(self).number_of_instances -= 1
        print("Bye rectangle...")
