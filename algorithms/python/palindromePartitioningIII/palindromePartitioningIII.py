#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/palindrome-partitioning-iii/
# Author: Miao Zhang
# Date:   2021-04-21

class Solution:
    def palindromePartition(self, s: str, k: int) -> int:
        n = len(s)
        cost = [[0 for _ in range(n)] for _ in range(n)]
        for l in range(2, n + 1):
            i = 0
            j = l - 1
            while j < n:
                cost[i][j] = cost[i + 1][j - 1] + (1 if s[i] != s[j] else 0)
                i += 1
                j += 1
        dp = [[float('inf') for _ in range(k + 1)] for _ in range(n)]
        for i in range(n):
            dp[i][1] = cost[0][i]
            for m in range(2, k + 1):
                for j in range(0, i):
                    dp[i][m] = min(dp[i][m], dp[j][m - 1] + cost[j + 1][i])
        return dp[n - 1][k]
