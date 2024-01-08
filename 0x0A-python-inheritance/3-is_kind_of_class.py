#!/usr/bin/python3
"""inherited class-checking function"""


def is_kind_of_class(obj, a_class):
    """verifies an obj. is an instance or inherited instance"""
    if isinstance(obj, a_class):
        return True
    return False
