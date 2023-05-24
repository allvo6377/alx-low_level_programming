#!/usr/bin/python3
"""Define a script that measures perimeter of island"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid.

    Args:
        grid: A list of lists of integers, where 0 represents a water zone
        and 1 represents a land zone.
    Returns:
        The perimeter of the Island
    """
    perimeter = 0
    for y in range(len(grid)):
        for x in range(len(grid[0])):
            if grid[y][x] == 1:
                perimeter += 4
            elif y == 0 or y == len(grid) - 1 or x == len(grid[0]) - 1:
                perimeter += 2
    return perimeter
