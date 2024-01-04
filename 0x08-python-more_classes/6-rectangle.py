#!/usr/bin/python3
"""class Rectangle that defines a rectangle by"""


class Rectangle:
    """class rectangle"""
    number_of_instances = 0

    def __init__(self, width=0, height=0):
        """Initialize rectangle"""
        type(self).number_of_instances += 1
        self.width = width
        self.height = height

    @property
    def width(self):
        return self.__width

    @width.setter
    def width(self, value):
        """put width"""
        if not isinstance(value, int):
            raise TypeError("width must be an integer")
        if value < 0:
            raise ValueError("width must be >= 0")
        self.__width = value

    @property
    def height(self):
        return self.__height

    @height.setter
    def height(self, value):
        """put height"""
        if not isinstance(value, int):
            raise TypeError("height must be an integer")
        if value < 0:
            raise ValueError("height must be >= 0")
        self.__height = value

    def area(self):
        """Return area"""
        return self.__width * self.__height

    def perimeter(self):
        """Return perimeter"""
        if self.__width == 0 or self.__height == 0:
            return (0)
        return self.__width * 2 + self.__height * 2

    def __str__(self):
        """rectangle representation with the # character"""
        if self.__width == 0 or self.__height == 0:
            return ("")

        rec = []
        for u in range(self.__height):
            [rec.append('#') for v in range(self.__width)]
            if u != self.__height - 1:
                rec.append("\n")
        return ("".join(rec))

    def __repr__(self):
        """Return str"""
        rec = "Rectangle(" + str(self.__width)
        rec += ", " + str(self.__height) + ")"
        return rec

    def __del__(self):
        """delete rectangle/print message"""
        type(self).number_of_instances -= 1
        print("Bye rectangle...")
