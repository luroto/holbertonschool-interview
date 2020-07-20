#!/usr/bin/python3
'''
This is my solution to the first problem
'''


def canUnlockAll(boxes):
    '''
    This function determines if all the boxes in a list of lists can be opened
    '''
    if isinstance(boxes, list) is False:
        return (False)
    if len(boxes) == 0:
        return (False)
    if len(boxes) == 1:
        return True
    if len(boxes[0]) == 0:
        return False
    for la in boxes:
        if isinstance(la, list) is False:
            return (False)

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
