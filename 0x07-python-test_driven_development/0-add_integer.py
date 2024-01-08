#!/usr/bin/python3
"""function that adds 2 integers"""


def add_integer(c, d=98):
    """Returns an integer: the addition of c and d"""
    if ((not isinstance(c, int) and not isinstance(c, float))):
        raise TypeError("c must be an integer")
    if ((not isinstance(d, int) and not isinstance(d, float))):
        raise TypeError("d must be an integer")
    return int(c) + int(d)
