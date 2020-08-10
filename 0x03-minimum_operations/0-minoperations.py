#!/usr/bin/python3
'''Function for finding the number of operations required to get a number using
just copy paste'''


def minOperations(num):
    ''' Function that calculates the minimun number of operations '''
    if isinstance(num, int) is False:
        return (0)
    min = 0
    i = 2
    while i <= num:
        while (num % i == 0):
            min += i
            num = num/i
        else:
            i += 1
    return (min)
