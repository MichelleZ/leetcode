#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/flip-string-to-monotone-increasing/
# Author: Miao Zhang
# Date:   2021-03-25

class Solution:
    def minFlipsMonoIncr(self, S: str) -> int:
        n = len(S)
        dp = [[0 for _ in range(2)] for _ in range(n)]
        for i in range(n):
            if S[i] == '0':
                dp[i][0] = dp[i - 1][0]
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1
            else:
                dp[i][0] = dp[i - 1][0] + 1
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1])
        return min(dp[n - 1][0], dp[n - 1][1])
