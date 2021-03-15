#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/making-a-large-island/
# Author: Miao Zhang
# Date:   2021-03-15

class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        
        def getArea(i, j):
            if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] != 1: return 0
            grid[i][j] = color
            return 1 + getArea(i - 1, j) + getArea(i + 1, j) + getArea(i, j - 1) + getArea(i, j + 1)
        
        def getColor(i, j):
            if i < 0 or i >= m or j < 0 or j >= n: return 0
            return grid[i][j]
        
        m = len(grid)
        n = len(grid[0])
        color = 1
        areas = collections.defaultdict(int)
        res = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    color += 1
                    areas[color] = getArea(i, j)
                    res = max(res, areas[color])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    area = 1
                    for color in set([getColor(i - 1, j), getColor(i + 1, j),
                                      getColor(i, j + 1), getColor(i, j - 1)]):
                        area += areas[color]
                    res = max(res, area)
        return res
        
