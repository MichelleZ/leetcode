#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/
# Author: Miao Zhang
# Date:   2021-05-06

##############################################################
# dp[i][j][s] = dp[i - 1][j][s] * j
#             + sum(dp[i - 1][x][s - 1]) 1 <= x < j
##############################################################
class Solution:
    def numOfArrays(self, n: int, m: int, k: int) -> int:
        if k == 0:
            return 0
        kMod = 10 ** 9 + 7
        dp = [[[0 for _ in range(k + 1)] for _ in range(m + 1)] for _ in range(n + 1)]
        for j in range(1, m + 1):
            dp[1][j][1] = 1
        for i in range(2, n + 1):
            for j in range(1, m + 1):
                for s in range(1, min(k, i) + 1):
                    dp[i][j][s] = dp[i - 1][j][s] * j
                    for j0 in range(1, j):
                        dp[i][j][s] += dp[i - 1][j0][s - 1]
                    dp[i][j][s] %= kMod
        return sum(dp[n][j][k] for j in range(1, m + 1)) % kMod
