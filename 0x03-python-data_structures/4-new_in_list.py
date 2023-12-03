#!/usr/bin/python3

def new_in_list(my_list, idx, element):
    if idx < 0 or idx >= len(my_list):
        return my_list.copy()  # Return a copy of the original list if idx is out of range

    new_list = my_list.copy()  # Create a copy of the original list
    new_list[idx] = element    # Replace the element at the specified index
    return new_list
