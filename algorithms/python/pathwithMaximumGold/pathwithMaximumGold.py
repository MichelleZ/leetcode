#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/path-with-maximum-gold/
# Author: Miao Zhang
# Date:   2021-04-17

class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        
        def dfs(i, j):
            if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == 0:
                return 0
            dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
            tmp = grid[i][j]
            grid[i][j] = 0
            r = 0
            for d in dirs:
                x = i + d[0]
                y = j + d[1]
                r = max(r, dfs(x, y))
            grid[i][j] = tmp
            return r + tmp
            
        res = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    res = max(res, dfs(i, j))
        return res
