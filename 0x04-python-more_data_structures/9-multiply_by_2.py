#!/usr/bin/python3
def multiply_by_2(a_dictionary):
    # Use a dictionary comprehension to create a new dictionary with values multiplied by 2
    return {key: value * 2 for key, value in a_dictionary.items()}
