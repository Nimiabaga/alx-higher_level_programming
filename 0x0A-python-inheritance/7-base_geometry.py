#!/usr/bin/python3
"""base geometry"""


class BaseGeometry:
    """a class BaseGeometry"""

    def area(self):
        """calculate area"""
        raise Exception("area() is not implemented")

    def integer_validator(self, name, value):
        """confirms a parameter as an int"""
        if type(value) != int:
            raise TypeError("{} must be an integer".format(name))
        if value <= 0:
            raise ValueError("{} must be greater than 0".format(name))
