#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-different-palindromic-subsequences/
# Author: Miao Zhang
# Date:   2021-03-04

class Solution:
    def countPalindromicSubsequences(self, S: str) -> int:
        kMod = 10 ** 9 + 7
        n = len(S)
        dp = [[0 for _ in range(n)] for _ in range(n)]
        for i in range(n):
            dp[i][i] = 1
        for size in range(2, n + 1):
            for i in range(n - size + 1):
                j = i + size - 1
                if S[i] == S[j]:
                    dp[i][j] = dp[i + 1][j - 1] * 2
                    l = i + 1
                    r = j - 1
                    while l <= r and S[l] != S[i]: l += 1
                    while l <= r and S[r] != S[i]: r -= 1
                    if l > r: dp[i][j] += 2
                    elif l == r: dp[i][j] += 1
                    else: dp[i][j] -= dp[l + 1][r - 1]
                else:
                    dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1]

                dp[i][j] = (dp[i][j] + kMod) % kMod
        return dp[0][n - 1]
