#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/surface-area-of-3d-shapes/
# Author: Miao Zhang
# Date:   2021-03-22

class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        res = 0
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]:
                    res += 2
                    for d in dirs:
                        x = i + d[0]
                        y = j + d[1]
                        if 0 <= x < len(grid) and 0 <= y < len(grid):
                            val = grid[x][y]
                        else:
                            val = 0
                        res += max(grid[i][j] - val, 0)
        return res
