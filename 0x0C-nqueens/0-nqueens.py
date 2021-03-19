#!/usr/bin/python3
"""
Working with some pseudocode for the nqueen problem
"""

import sys


def nqueens(size):
    """
    Root function for the nqueen program
    """
    all_queens = 0

    if all_queens == size:
        return True


def queen_is_safe(row, column, size):
    """
    Function to check if a queen position is safe
    """
    return 0


def main():
    """
    Main function to be executed
    """
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    if sys.argv[1].isdigit() is not True:
        print("N must be a number")
        exit(1)
    size = int(sys.argv[1])
    if size < 4:
        print("N must be at least 4")
        exit(1)
    nqueens(size)
    return 0

main()
