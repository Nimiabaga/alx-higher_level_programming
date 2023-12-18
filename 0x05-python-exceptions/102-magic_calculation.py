#!/usr/bin/python3
def magic_calculation(a, b):
    val = 0
    for u in range(1, 3):
        try:
            if u > a:
                raise Exception('Too Far')
            val += a ** b / u
        except Exception:
            val = b + a
            break
    return val
