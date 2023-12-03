#!/usr/bin/python3
def add_tuple(tuple_a=(), tuple_b=()):
    u = len(tuple_a)
    v = len(tuple_b)
    size = ((tuple_a[0] if u >= 1 else 0) +
            (tuple_b[0] if v >= 1 else 0),
            (tuple_a[1] if u >= 2 else 0) +
            (tuple_b[1] if v >= 2 else 0))
    return size
