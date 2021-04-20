#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-servers-that-communicate/
# Author: Miao Zhang
# Date:   2021-04-20

class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        rows = [0 for _ in range(m)]
        cols = [0 for _ in range(n)]
        for i in range(m):
            for j in range(n):
                rows[i] += grid[i][j]
                cols[j] += grid[i][j]
        res = 0
        for i in range(m):
            for j in range(n):
                res += grid[i][j] if rows[i] > 1 or cols[j] > 1 else 0
        return res
