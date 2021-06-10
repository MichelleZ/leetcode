#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-sideway-jumps/
# Author: Miao Zhang
# Date:   2021-06-10

class Solution:
    def minSideJumps(self, obstacles: List[int]) -> int:
        n = len(obstacles)
        dp = [[float('inf') for _ in range(3)] for _ in range(n)]
        # dp[i][j]: ith location, jth lane
        dp[0][0], dp[0][1], dp[0][2] = 1, 0, 1
        for i in range(1, n):
            if obstacles[i] != 1: dp[i][0] = dp[i - 1][0]
            if obstacles[i] != 2: dp[i][1] = dp[i - 1][1]
            if obstacles[i] != 3: dp[i][2] = dp[i - 1][2]
            if obstacles[i] != 1: dp[i][0] = min(dp[i][0], dp[i][1] + 1, dp[i][2] + 1)
            if obstacles[i] != 2: dp[i][1] = min(dp[i][1], dp[i][0] + 1, dp[i][2] + 1)
            if obstacles[i] != 3: dp[i][2] = min(dp[i][2], dp[i][0] + 1, dp[i][1] + 1)
        return min(dp[n - 1])
