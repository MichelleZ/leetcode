#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/
# Author: Miao Zhang
# Date:   2021-05-16

class Solution:
    def minDays(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        seen = [0] * (m * n)

        def dfs(i, j):
            if i < 0 or i >= m or j < 0 or j >= n: return
            if grid[i][j] == 0: return
            if seen[i * n + j]: return
            seen[i * n + j] = 1
            for d in dirs:
                x = i + d[0]
                y = j + d[1]
                dfs(x, y)

        def disconnected():
            cnt = 0
            for i in range(len(seen)):
                seen[i] = 0
            for i in range(m):
                for j in range(n):
                    if grid[i][j] and seen[i * n + j] == 0:
                        dfs(i, j)
                        cnt += 1
                        if cnt > 1: return True
            if cnt == 0:
                return True
            return False

        if disconnected():
            return 0
        for i in range(m):
            for j in range(n):
                if not grid[i][j]: continue
                grid[i][j] = 0
                if disconnected(): return 1
                grid[i][j] = 1
        return 2
