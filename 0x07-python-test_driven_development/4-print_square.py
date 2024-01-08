#!/usr/bin/python3
"""Text indentation"""


def text_indentation(text):
    """function prints text with 2 \n after each of these chars: ., ? and :"""
    if not isinstance(text, str):
        raise TypeError("text must be a string")

    u = 0
    while u < len(text) and text[u] == " ":
        u = u + 1

    while u < len(text):
        print(text[u], end="")
        if text[u] == "\n" or text[u] in ".?:":
            if text[u] in ".?:":
                print("\n")
            u = u + 1
            while u < len(text) and text[u] == " ":
                u = u + 1
            continue
        u = u + 1
