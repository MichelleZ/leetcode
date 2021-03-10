#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/domino-and-tromino-tiling/
# Author: Miao Zhang
# Date:   2021-03-10

class Solution:
    def numTilings(self, N: int) -> int:
        kMod = 10 ** 9 + 7
        dp = [[0 for _ in range(2)] for _ in range(N + 1)]
        dp[0][0] = dp[1][0] = 1
        for i in range(2, N + 1):
            dp[i][0] = (dp[i - 1][0] + dp[i - 2][0] + 2 * dp[i - 1][1]) % kMod
            dp[i][1] = (dp[i - 2][0] + dp[i - 1][1]) % kMod
        return dp[N][0]
