#!/usr/bin/python3
"""MagicClass that does exactly same as bytecode provided"""
import math


class MagicClass:
    """magic set up"""

    def __init__(self, radius=0):
        """MagicClass initialization"""
        self.__radius = 0
        if type(radius) is not int and type(radius) is not float:
            raise TypeError('radius must be a number')
        self.__radius = radius

    def area(self):
        """return area"""
        return self.__radius ** 2 * math.pi

    def circumference(self):
        """return circumference"""
        return 2 * math.pi * self.__radius
