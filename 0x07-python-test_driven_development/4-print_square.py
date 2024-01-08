#!/usr/bin/python3
"""function prints a square with the character #"""


def print_square(size):
    """size is the size length of the square / integer"""
    if not isinstance(size, int):
        raise TypeError("size must be an integer")
    if size < 0:
        raise ValueError("size must be >= 0")

    for u in range(size):
        [print("#", end="") for v in range(size)]
        print("")
