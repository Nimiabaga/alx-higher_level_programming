#!/usr/bin/python3
def best_score(a_dictionary):
    if a_dictionary:
        # Use the max function with a custom key to find the key with the highest value
        return max(a_dictionary, key=a_dictionary.get)
    else:
        return None
