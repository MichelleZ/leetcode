#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/shift-2d-grid/
# Author: Miao Zhang
# Date:   2021-04-20

class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])
        res = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                y = (j + k) % n
                x = (i + (j + k) // n) % m
                res[x][y] = grid[i][j]
        return res
