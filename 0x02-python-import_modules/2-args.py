#!/usr/bin/python3
if __name__ == '__main__':
    from sys import argv

    num_args = len(argv) - 1
    args = argv[1:]

    if num_args == 0:
        print("0 arguments.")
    else:
        print("{} argument{}:".format(num_args, 's' if num_args > 1 else ''))
        for i, arg in enumerate(args, 1):
            print("{}: {}".format(i, arg))
