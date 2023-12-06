#!/usr/bin/python3
def square_matrix_map(matrix=[]):
    return list(map(lambda u: list(map(lambda c: c**2, u)), matrix))
