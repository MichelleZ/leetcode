#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-palindromic-subsequence/
# Author: Miao Zhang
# Date:   2021-02-19

class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        dp = [[0 for _ in range(n)] for _ in range(n)]
        for l in range(1, n + 1):
            for i in range(0, n - l + 1):
                j = i + l - 1
                if i == j: 
                    dp[i][j] = 1
                    continue
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1] + 2
                else:
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
        return dp[0][n - 1]
