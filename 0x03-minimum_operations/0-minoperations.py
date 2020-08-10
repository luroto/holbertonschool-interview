#!/usr/bin/python3
'''Function for finding the number of operations required to get a number using
just copy paste'''


def minOperations(num):
    ''' Function that calculates the minimun number of operations '''
    if isinstance(num, int) is False:
        return (0)
    min = 0
    for i in range(2, num+1):
        while (num % i == 0):
            min += i
            num = num/i
    return (min)
