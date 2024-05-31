#!/usr/bin/python3

"""
    Module minoperations
    A method to define the fewest number of operations needed
    to result in exactly n H characters in the file.

"""


def minOperations(n):
    """
        a method that calculates the fewest number of operations needed
        to result in exactly n H characters in the file

    
        n: number of operations

        Return as an int the number of operations
    """
    if n <= 1:
        return 0
    
    operations = 0
    factor = 2

    while n > 1:
        while n % factor == 0:
            operations += factor
            n //= factor
        factor += 1

    return operations
