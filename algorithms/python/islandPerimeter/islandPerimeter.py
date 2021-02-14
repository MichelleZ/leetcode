#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/island-perimeter/
# Author: Miao Zhang
# Date:   2021-02-14

class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        res = 0
        recount = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    res += 1
                    if i > 0 and grid[i - 1][j] == 1:
                        recount += 1
                    if j > 0 and grid[i][j - 1] == 1:
                        recount += 1
                    if i + 1 < m and grid[i + 1][j] == 1:
                        recount += 1
                    if j + 1 < n and grid[i][j + 1] == 1:
                        recount += 1
        return 4 * res - recount
