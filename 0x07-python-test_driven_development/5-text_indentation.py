#!/usr/bin/python3
"""Text indentation"""


def text_indentation(text):
    """Prints text with 2 newlines after each of these chars: ., ? and :"""
    if not isinstance(text, str):
        raise TypeError("text must be a string")

    indentation_level = 0
    for char in text:
        print(char, end="")

        if char in ".?:":
            print("\n\n", end="")
            indentation_level = 0
        elif char == " ":
            indentation_level += 1
        else:
            indentation_level = 0
