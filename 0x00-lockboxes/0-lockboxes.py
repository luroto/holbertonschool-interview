#!/usr/bin/python3
'''
This is my solution to the first problem
'''


def canUnlockAll(boxes):
    '''
    This function determines if all the boxes in a list of lists can be opened
    '''
    keychain = boxes[0].copy()
    i = len(boxes)

    for key in keychain:
        for llave in boxes[key]:
            if llave < i and llave not in keychain:
                keychain.append(llave)

    for j in range(1, i):
        if j not in keychain:
            return (False)

    return (True)
