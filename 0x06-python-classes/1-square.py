#!/usr/bin/python3

class Square:
    """
    This is a class Square that defines a square by its private instance attribute: size.
    """
    def __init__(self, size):
        """
        Initializes a new instance of the Square class.
        Args:
            size (int): The size of the square.
        """
        self.__size = size
