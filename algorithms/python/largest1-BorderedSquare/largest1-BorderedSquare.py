#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/largest-1-bordered-square/
# Author: Miao Zhang
# Date:   2021-04-12

class Solution:
    def largest1BorderedSquare(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + grid[i - 1][j - 1]
                
        def getArea(x1, y1, x2, y2):
            return dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]
        
        for l in range(min(m, n), 0, -1):
            for x1 in range(1, m - l + 2):
                x2 = x1 + l - 1
                for y1 in range(1, n - l + 2):
                    y2 = y1 + l - 1
                    if getArea(x1, y1, x2, y1) == l and \
                       getArea(x1, y1, x1, y2) == l and \
                       getArea(x1, y2, x2, y2) == l and \
                       getArea(x2, y1, x2, y2) == l:
                        return l * l
        return 0
