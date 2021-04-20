#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
# Author: Miao Zhang
# Date:   2021-04-20

class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        '''
        dp[i][j]: the ith operation, postion is j
        dp[i][j] = dp[i-1][j] + dp[i-1][j]+ dp[i-1][j+1]
        dp[0][0] = 1
        dp[steps][0]
        '''
        kMod = 10 ** 9 + 7
        n = min(steps + 1, arrLen)
        dp = [[0 for _ in range(n)] for _ in range(steps + 1)]
        dp[0][0] = 1
        for i in range(1, steps + 1):
            for j in range(n):
                for k in [-1, 0, 1]:
                    if 0 <= j - k < n:
                        dp[i][j] += dp[i - 1][j - k]
        return dp[steps][0] % kMod
