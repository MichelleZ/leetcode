#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/projection-area-of-3d-shapes/
# Author: Miao Zhang
# Date:   2021-03-21

class Solution:
    def projectionArea(self, grid: List[List[int]]) -> int:
        n = len(grid)
        res = 0
        for i in range(n):
            bestrow = 0
            bestcol = 0
            for j in range(n):
                if grid[i][j]: res += 1
                bestrow = max(bestrow, grid[i][j])
                bestcol = max(bestcol, grid[j][i])
            res += bestrow + bestcol
        return res
