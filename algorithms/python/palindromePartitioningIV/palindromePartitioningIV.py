#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/palindrome-partitioning-iv/
# Author: Miao Zhang
# Date:   2021-06-02

class Solution:
    def checkPartitioning(self, s: str) -> bool:
        n = len(s)
        dp = [[1 for _ in range(n)] for _ in range(n)]
        for l in range(2, n + 1):
            for i in range(n - l + 1):
                j = i + l - 1
                dp[i][j] = (s[i] == s[j]) and dp[i + 1][j - 1]
        for i in range(1, n):
            for j in range(i, n - 1):
                if dp[0][i - 1] and dp[i][j] and dp[j + 1][n - 1]:
                    return True
        return False
