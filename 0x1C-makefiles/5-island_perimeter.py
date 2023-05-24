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
    rows = len(grid)
    cols = len(grid[0])
    perimeter = 0

    for row in range(rows):
        for col in range(cols):
            if grid[row][col] == 1:
                perimeter += 4
                if row > 0 and grid[row-1][col] == 1:
                    perimeter -= 2
                if col > 0 and grid[row][col-1] == 1:
                    perimeter -= 2
    return perimeter
