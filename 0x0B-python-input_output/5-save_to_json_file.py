#!/usr/bin/python3
"""func writes an Object to a text file"""
import json


def save_to_json_file(my_obj, filename):
    """writes object to a text file using JSON representation"""
    with open(filename, "w") as u:
        json.dump(my_obj, u)
