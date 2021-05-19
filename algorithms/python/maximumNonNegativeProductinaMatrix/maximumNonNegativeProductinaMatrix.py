#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/
# Author: Miao Zhang
# Date:   2021-05-19

class Solution:
    def maxProductPath(self, grid: List[List[int]]) -> int:
        kMod = 10 ** 9 + 7
        m = len(grid)
        n = len(grid[0])
        dpmax = [[0 for _ in range(n)] for _ in range(m)]
        dpmin = [[0 for _ in range(n)] for _ in range(m)]
        dpmax[0][0] = dpmin[0][0] = grid[0][0]
        for i in range(1, m):
            dpmax[i][0] = dpmin[i][0] = dpmin[i - 1][0] * grid[i][0]
        for j in range(1, n):
            dpmax[0][j] = dpmin[0][j] = dpmin[0][j - 1] * grid[0][j]
        for i in range(1, m):
            for j in range(1, n):
                if grid[i][j] > 0:
                    dpmax[i][j] = max(dpmax[i - 1][j], dpmax[i][j - 1]) * grid[i][j]
                    dpmin[i][j] = min(dpmin[i - 1][j], dpmin[i][j - 1]) * grid[i][j]
                else:
                    dpmax[i][j] = min(dpmin[i - 1][j], dpmin[i][j - 1]) * grid[i][j]
                    dpmin[i][j] = max(dpmax[i - 1][j], dpmax[i][j - 1]) * grid[i][j]
        return dpmax[m - 1][n - 1] % kMod  if dpmax[m - 1][n - 1] >= 0 else -1
