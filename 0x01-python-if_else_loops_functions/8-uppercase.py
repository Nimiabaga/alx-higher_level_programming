#!/usr/bin/python3
def uppercase(str):
    """Print a string in uppercaase."""
    for u in str:
        if ord(u) >= 97 and ord(u) <= 122:
            u = chr(ord(u) - 32)
        print("{}".format(u), end="")
    print("")
