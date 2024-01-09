#!/usr/bin/python3
"""class Student that defines a student"""


class Student:
    """student representation"""

    def __init__(self, first_name, last_name, age):
        """Initializing student"""
        self.first_name = first_name
        self.last_name = last_name
        self.age = age

    def to_json(self, attrs=None):
        """dictionary representation"""
        if (type(attrs) == list and
                all(type(ele) == str for ele in attrs)):
            return {u: getattr(self, u) for u in attrs if hasattr(self, u)}
        return self.__dict__

    def reload_from_json(self, json):
        """replace student attributes"""
        for i, j in json.items():
            setattr(self, i, j)
