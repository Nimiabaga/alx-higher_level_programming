#!/usr/bin/python3
"""Class Rectangle that defines a rectangle"""


class Rectangle:
    """Class rectangle"""
    number_of_instances = 0
    print_symbol = "#"

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
        """Set width"""
        self._validate_dimension(value, "width")
        self.__width = value

    @property
    def height(self):
        return self.__height

    @height.setter
    def height(self, value):
        """Set height"""
        self._validate_dimension(value, "height")
        self.__height = value

    def _validate_dimension(self, value, dimension):
        """Validate dimension (width or height)"""
        if not isinstance(value, int):
            raise TypeError(f"{dimension} must be an integer")
        if value < 0:
            raise ValueError(f"{dimension} must be >= 0")

    def area(self):
        """Return area"""
        return self.__width * self.__height

    def perimeter(self):
        """Return perimeter"""
        if self.__width == 0 or self.__height == 0:
            return 0
        return 2 * (self.__width + self.__height)

    @staticmethod
    def bigger_or_equal(rect_1, rect_2):
        """Return the biggest rectangle based on the area"""
        if not isinstance(rect_1, Rectangle) or not isinstance(rect_2, Rectangle):
            raise TypeError("Both rect_1 and rect_2 must be instances of Rectangle")
        return rect_1 if rect_1.area() >= rect_2.area() else rect_2

    @classmethod
    def square(cls, size=0):
        """Create a square instance"""
        return cls(size, size)

    def __str__(self):
        """Rectangle representation with the # character"""
        if self.__width == 0 or self.__height == 0:
            return ""
        
        return str(self.print_symbol) * self.__width + ("\n" + str(self.print_symbol) * self.__width) * (self.__height - 1)

    def __repr__(self):
        """Return a string representation"""
        return f"Rectangle({self.__width}, {self.__height})"

    def __del__(self):
        """Delete rectangle and print a message"""
        type(self).number_of_instances -= 1
        print("Bye rectangle...")
