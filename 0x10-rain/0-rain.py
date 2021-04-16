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
        while array[i] == 0:
            i += 1
        lowestWallIndex = i
        lowestWall = array[i]
        bloques = 0
        for j in range(i + 1, endofArray):
            if array[j] >= lowestWall and array[j] > 0:
                highestWallIndex = j
                highestWall = array[j]
                """print("lowestWall {} on index {}, highestWall {}
                on index {}".format(lowestWall, lowestWallIndex,
                highestWall, highestWallIndex))"""
                height = highestWall - lowestWall
                width = highestWallIndex - lowestWallIndex
                """print("height {}, width {}, bloques
                {}".format(height, width, bloques))"""
                water.append((height * width) - bloques)
                """print(water)"""
                break
            bloques += array[j]
        i += 1
    total = sum(water)
    return total
