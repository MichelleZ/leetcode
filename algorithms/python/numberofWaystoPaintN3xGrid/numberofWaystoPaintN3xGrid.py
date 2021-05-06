#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
# Author: Miao Zhang
# Date:   2021-05-05

class Solution:
    def numOfWays(self, n: int) -> int:
        kMod = 10 ** 9 + 7
        dp = [[0 for _ in range(2)] for _ in range(n + 1)]
        dp[1][0] = 6
        dp[1][1] = 6
        for i in range(2, n + 1):
            dp[i][0] = (3 * dp[i - 1][0] + 2 * dp[i - 1][1]) % kMod
            dp[i][1] = (2 * dp[i - 1][0] + 2 * dp[i - 1][1]) % kMod
        return (dp[n][0] + dp[n][1]) % kMod
