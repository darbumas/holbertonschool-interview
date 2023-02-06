#!/usr/bin/python3

"""Minimum operations calculates the fewest steps it takes to
"coppy all/paste" to produce 'n' number characters starting from 1."""


def minOperations(n):
    """sums up factors of n to find the minimum operations"""
    if (n <= 1):
        return 0

    i = 1
    ops = 0
    pastebin = 0

    while i != n:
        if n % i == 0:
            pastebin = i
            ops += 1
        i = i + pastebin
        ops += 1

    return ops
