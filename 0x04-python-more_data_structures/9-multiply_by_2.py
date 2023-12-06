#!/usr/bin/python3
def multiply_by_2(a_dictionary):
    u = a_dictionary.copy()
    v = list(u.keys())
    for k in v:
        u[k] *= 2
    return (u)
