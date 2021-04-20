#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-closed-islands/
# Author: Miao Zhang
# Date:   2021-04-20

class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])

        def dfs(i, j):
            if i < 0 or i >= m or j < 0 or j >= n:
                self.val = 0
                return
            if grid[i][j] == 1: return
            grid[i][j] = 1
            dfs(i + 1, j)
            dfs(i - 1, j)
            dfs(i, j + 1)
            dfs(i, j - 1)

        res = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    self.val = 1
                    dfs(i, j)
                    res += self.val
        return res

