#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
# Author: Miao Zhang
# Date:   2021-04-23

class Solution:
    def minInsertions(self, s: str) -> int:
        n = len(s)
        dp = [[0 for _ in range(n)] for _ in range(n)]
        for l in range(2, n + 1):
            i = 0
            j = l - 1
            while j < n:
                dp[i][j] = dp[i + 1][j - 1] if s[i] == s[j] else min(dp[i][j - 1], dp[i + 1][j]) + 1
                i += 1
                j += 1
        return dp[0][n - 1]
