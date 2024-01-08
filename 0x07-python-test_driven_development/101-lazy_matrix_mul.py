#!/usr/bin/python3

"""This module contains a func that multiplies 2 matrices"""

import numpy as np


def lazy_matrix_mul(m_a, m_b):
    """Return multiplication of 2 matrices"""
    return (np.matmul(m_a, m_b))
