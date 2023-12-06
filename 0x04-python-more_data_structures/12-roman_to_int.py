#!/usr/bin/python3
def roman_to_int(roman_string):
    if roman_string is None or type(roman_string) != str:
        return 0
    info = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
    u = [info[x] for x in roman_string] + [0]
    v = 0
    for i in range(len(u) - 1):
        if u[i] >= u[i+1]:
            v += u[i]
        else:
            v -= u[i]
    return v
