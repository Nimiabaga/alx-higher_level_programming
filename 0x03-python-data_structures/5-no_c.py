#!/usr/bin/python3

def no_c(my_string):
    text = ""
    for char in my_string:
        if char.lower() != 'c':
            text += char
    return text
