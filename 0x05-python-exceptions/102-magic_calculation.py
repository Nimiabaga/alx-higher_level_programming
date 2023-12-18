#!/usr/bin/python3
def magic_calculation(a, b):
    count = 0
    for u in range(1, 3):
        try:
            if u > a:
                raise Exception('Too Far')
            count += a ** b / u
        except Exception:
            val = b + a
            break
    return count
