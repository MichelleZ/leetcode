#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/unique-paths-ii/
# Author: Miao Zhang
# Date:   2021-01-13

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        if obstacleGrid[m - 1][n - 1] == 1:
            return 0
        dp = [[0 for _ in range(n)] for _ in range(m)]
        if obstacleGrid[0][0] == 0:
            dp[0][0] = 1
        for i in range(m):
            for j in range(n):
                if i - 1 >= 0 and obstacleGrid[i - 1][j] == 0:
                    dp[i][j] += dp[i - 1][j]
                if j - 1 >= 0 and obstacleGrid[i][j - 1] == 0:
                    dp[i][j] += dp[i][j - 1]
        return dp[m - 1][n - 1]
