#!/usr/bin/python3
"""func returns True if obj is an instance of a class
    that inherited (directly or indirectly),otherwise False"""


def inherits_from(obj, a_class):
    """Checks if an object is an inherited instance of a class"""

    if isinstance(obj, a_class) and type(obj) is not a_class:
        return True

    return False
