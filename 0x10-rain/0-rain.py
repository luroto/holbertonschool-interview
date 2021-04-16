#!/usr/bin/python3
"""
Function to solve the rain problem
"""


def rain(array):
    """
    Function to calculate how much water blocks are filled
    after rain between walls
    """
    endofArray = len(array)
    if endofArray == 0:
        return 0
    if array[0] == 0:
        i = 1
    else:
        i = 0
    water = []
    while i < endofArray:
        while array[i] == 0 and i != endofArray:
            if i == endofArray - 1:
                break
            i += 1
        lowestWallIndex = i
        lowestWall = array[i]
        bloques = 0
        for j in range(i + 1, endofArray):
            if array[j] >= lowestWall and array[j] > 0:
                highestWallIndex = j
                height = lowestWall
                width = highestWallIndex - lowestWallIndex - 1
                water.append((height * width) - bloques)
                if highestWallIndex == endofArray - 1:
                    i = highestWallIndex
                    break
                if (array[highestWallIndex + 1] == 0 or
                        array[highestWallIndex + 1] < array[highestWallIndex]):
                    i = highestWallIndex - 1
                else:
                    i = highestWallIndex
                break
            bloques += array[j]
        i += 1
    total = sum(water)
    return total
