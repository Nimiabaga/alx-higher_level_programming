#!/usr/bin/python3
"""class Square that inherits from Rectangle"""


Rectangle = __import__('9-rectangle').Rectangle
BaseGeometry = __import__('7-base_geometry').BaseGeometry


class Square(Rectangle):
    """contain class square"""

    def __init__(self, size):
        """Initialization"""
        super().integer_validator("size", size)
        super().__init__(size, size)
        self.__size = size
