#!/usr/bin/python3
def weight_average(my_list=[]):
    if not my_list:
        return 0
    u = 0
    v = 0
    for k in my_list:
        u += k[0] * k[1]
        v += k[1]
    return (u / v)
