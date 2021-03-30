#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/unique-paths-iii/
# Author: Miao Zhang
# Date:   2021-03-30

# Time limit Exceeded
class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        cache = [[[-1 for _ in range(1 << m * n)] for _ in range(n)] for _ in range(m)]
        sx = -1
        sy = -1
        state = 0

        def ckey(r, c):
            return 1 << (r * n + c)

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0 or grid[i][j] == 2:
                    state |= ckey(i, j)
                elif grid[i][j] == 1:
                    sx = i
                    sy = j

        def dfs(i, j, state):
            if cache[i][j][state] != -1:
                return cache[i][j][state]
            if grid[i][j] == 2:
                return state == 0
            paths = 0
            for d in dirs:
                x = i + d[0]
                y = j + d[1]
                if x < 0 or x >= m or y < 0 or y >= n or grid[x][y] == -1:
                    continue
                if not (state & ckey(x, y)):
                    continue
                paths += dfs(x, y, state ^ ckey(x, y))
            cache[i][j][state] = paths
            return paths

        return dfs(sx, sy, state)
