#!/usr/bin/python3
"""func reads a text file (UTF8) and prints it to stdout"""


def read_file(filename=""):
    """Prints the content to stdout"""
    with open(filename, encoding="utf-8") as f:
        print(f.read(), end="")
