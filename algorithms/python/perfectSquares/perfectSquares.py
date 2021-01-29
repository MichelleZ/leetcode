#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/perfect-squares/
# Author: Miao Zhang
# Date:   2021-01-29

class Solution:
    def numSquares(self, n: int) -> int:
        '''
        dp[i] = min(dp[i], dp[i - j * j]  + 1)
        '''
        dp = [0] * (n + 1)
        for i in range(1, n + 1):
            dp[i] = i
            for j in range(1, int(i ** 0.5) + 1):
                dp[i] = min(dp[i], dp[i - j * j] + 1)
        return dp[n]
