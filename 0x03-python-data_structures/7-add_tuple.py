#!/usr/bin/python3

def add_tuple(tuple_a=(), tuple_b=()):
    # Ensure each tuple has at least 2 elements
    a = tuple_a + (0, 0)
    b = tuple_b + (0, 0)

    # Calculate the sum of corresponding elements
    sum_tuple = (a[0] + b[0], a[1] + b[1])

    return sum_tuple
