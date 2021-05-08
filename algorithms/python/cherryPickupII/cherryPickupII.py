#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/cherry-pickup-ii/
# Author: Miao Zhang
# Date:   2021-05-08

######################################################################
# dp[x][y1][y2] = max(dp[x + 1][y1'][y2'])
#                 + grid[x][y1] + (grid[x][y2] if x1 != x2 else 0)
# y1': y1-1..y1+1, y2': y2-1..y2+1
# dp[0][0][n - 1]
######################################################################
class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        cache = [[[-1 for _ in range(n)] for _ in range(n)] for _ in range(m)]
        
        def dp(x, y1, y2):
            if x < 0 or x >= m or y1 < 0 or y1 >= n or y2 < 0 or y2 >= n:
                return 0
            if cache[x][y1][y2] != -1: return cache[x][y1][y2]
            res = 0
            cur = grid[x][y1] + (y1 != y2) * grid[x][y2]
            for d1 in [-1, 0, 1]:
                for d2 in [-1, 0, 1]:
                    res = max(res, cur + dp(x + 1, y1 + d1, y2 + d2))
            cache[x][y1][y2] = res    
            return res
        
        return dp(0, 0, n - 1)
