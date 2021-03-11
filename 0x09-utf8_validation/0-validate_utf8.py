#!/usr/bin/python3

"""
Function to check if a data set is a valid UTF-8 char
"""

import sys


def validUTF8(data):
    """Return: True if data is a valid UTF-8 encoding, else return False
    A character in UTF-8 can be 1 to 4 bytes long
    The data set can contain multiple characters
    The data will be represented by a list of integers
    Each integer represents 1 byte of data, therefore you only need
    to handle the 8 least significant bits of each integer
    """

    cont = 0
    status = False

    for chara in data:

        byte = format(chara, '#010b')[-8:]

        if cont == 0:
            if byte[0] == '1':
                cont = len(byte.split('0')[0])

            if cont == 1 or cont > 4:
                return False

            if cont == 0:
                continue

        else:
            if not byte.startswith('10'):
                return False

        cont -= 1

    if cont == 0:
        status = True

    return status
