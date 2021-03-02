#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/max-area-of-island/
# Author: Miao Zhang
# Date:   2021-03-02

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        res = 0
        for i in range(m):
            for j in range(n):
                res = max(res, self.dfs(grid, i, j))
        return res

    def dfs(self, grid: List[List[int]], i: int, j: int) -> int:
        if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] == 0:
            return 0
        grid[i][j] = 0
        return 1 + self.dfs(grid, i - 1, j) \
                 + self.dfs(grid, i + 1, j) \
                 + self.dfs(grid, i, j - 1) \
                 + self.dfs(grid, i, j + 1)
