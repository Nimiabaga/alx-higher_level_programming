#!/usr/bin/python3

def read_file(filename=""):
    """Prints the content of a text file to stdout."""
    with open(filename, encoding="utf-8") as file:
        print(file.read(), end="")
