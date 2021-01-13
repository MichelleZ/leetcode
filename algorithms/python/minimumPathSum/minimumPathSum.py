#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-path-sum/
# Author: Miao Zhang
# Date:   2021-01-13

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        dp = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if i - 1 >= 0 and j - 1 >= 0:
                    tmp = min(dp[i - 1][j], dp[i][j - 1])
                elif i - 1 >= 0:
                    tmp = dp[i - 1][j]
                elif j - 1 >= 0:
                    tmp = dp[i][j - 1]
                else:
                    tmp = 0
                
                dp[i][j] = grid[i][j] + tmp
        return dp[m - 1][n - 1]
