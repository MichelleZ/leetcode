#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/cherry-pickup/
# Author: Miao Zhang
# Date:   2021-03-05

############################################################
# from (0, 0) to (r1, c1) t = r1 + c1
# from (0, 0) to (r2, c2) t = r2 + c2
# i: r1, j: r2
############################################################
class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        n = len(grid)
        dp = [[float('-inf') for _ in range(n)] for _ in range(n)]
        dp[0][0] = grid[0][0]
        for t in range(1, 2 * n - 1):
            dp2 = [[float('-inf') for _ in range(n)] for _ in range(n)]
            for i in range(max(0, t - (n - 1)), min(n - 1, t) + 1):
                for j in range(max(0, t - (n - 1)), min(n - 1, t) + 1):
                    if grid[i][t - i] == -1 or grid[j][t - j] == -1:
                        continue
                    val = grid[i][t - i]
                    if i != j: val += grid[j][t - j]
                    dp2[i][j] = max(dp[x][y] + val
                                    for x in (i - 1, i) for y in (j - 1, j)
                                    if x >= 0 and y >= 0)
            dp = dp2
        return max(0, dp[n - 1][n - 1])
