#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/k-inverse-pairs-array/
# Author: Miao Zhang
# Date:   2021-02-25

class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        mod = 10 ** 9 + 7
        dp = [[0 for _ in range(k + 1)] for _ in range(n + 1)]
        dp[0][0] = 1
        for i in range(1, n + 1):
            dp[i][0] = 1
            for j in range(1, k + 1):
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod
                if j >= i:
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + mod) % mod
        return dp[n][k]
