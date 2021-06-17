#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/largest-magic-square/
# Author: Miao Zhang
# Date:   2021-06-17

class Solution:
    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        rows = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            rows[i][0] = grid[i][0]
            for j in range(1, n):
                rows[i][j] = rows[i][j - 1] + grid[i][j]
        cols = [[0 for _ in range(n)] for _ in range(m)]
        for j in range(n):
            cols[0][j] = grid[0][j]
            for i in range(1, m):
                cols[i][j] = cols[i - 1][j] + grid[i][j]
        for l in range(min(m, n), 1, -1):
            for i in range(m - l + 1):
                for j in range(n - l + 1):
                    rowsum = rows[i][j + l - 1] - (rows[i][j - 1] if j else 0)
                    check = True
                    for x in range(i + 1, i + l):
                        if (rows[x][j + l - 1] - (rows[x][j - 1] if j else 0)) != rowsum:
                            check = False
                            break
                    if not check: continue
                    for y in range(j, j + l):
                        if (cols[i + l - 1][y] - (cols[i - 1][y] if i else 0)) != rowsum:
                            check = False
                            break
                    if not check: continue
                    dia1, dia2 = 0, 0
                    for k in range(l):
                        dia1 += grid[i + k][j + k]
                        dia2 += grid[i + k][j + l - 1 - k]
                    if dia1 == rowsum and dia2 == rowsum:
                        return l
        return 1

