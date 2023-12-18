#!/usr/bin/python3
def safe_print_list(my_list=[], x=0):
    count = 0
    for u in range(x):
        try:
            print("{}".format(my_list[u]), end="")
            count += 1
        except IndexError:
            break
    print("")
    return (count)
