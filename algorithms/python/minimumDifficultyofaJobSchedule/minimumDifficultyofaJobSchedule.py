#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
# Author: Miao Zhang
# Date:   2021-04-25

class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        if d > n: return -1
        dp = [[float('inf') for _ in range(d + 1)] for _ in range(n + 1)]
        dp[0][0] = 0
        for i in range(1, n + 1):
            for k in range(1, d + 1):
                tmp = 0
                for j in range(i - 1, k - 2, -1):
                    tmp = max(tmp, jobDifficulty[j])
                    dp[i][k] = min(dp[i][k], dp[j][k - 1] + tmp)
        return dp[n][d]
