#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-islands/
# Author: Miao Zhang
# Date:   2021-01-25

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        output = 0
        m = len(grid)
        n = len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    output += 1
                    self.dfs(grid, i, j)
        return output

    
    def dfs(self, grid: List[List[str]], i: int, j: int) -> None:
        grid[i][j] = '0'
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        for dx, dy in dirs:
            x = i + dx
            y = j + dy
            if 0 <= x < len(grid) and 0 <= y < len(grid[0]) and grid[x][y] == '1':
                self.dfs(grid, x, y)
