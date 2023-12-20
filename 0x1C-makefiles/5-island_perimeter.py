#!/usr/bin/env python3
"""Creation of a function that measure an Island's perimeter"""


def island_perimeter(grid):
    """returns the island's perimeter"""
    W = len(grid[0])
    L = len(grid)
    e = 0
    s = 0

    for i in range(L):
        for j in range(W):
            if grid[i][j] == 1:
                s = s + 1
                if (j > 0 and grid[i][j - 1] == 1):
                    e += 1
                if (i > 0 and grid[i - 1][j] == 1):
                    e += 1
    return s * 4 - e * 2
