#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/strange-printer/
# Author: Miao Zhang
# Date:   2021-02-27

class Solution:
    def strangePrinter(self, s: str) -> int:
        n = len(s)
        dp = [[0 for _ in range(n)] for _ in range(n)]
        return self.print(s, 0, n - 1, dp)

    def print(self, s: str, i: int, j: int, dp: List[List[int]]) -> int:
        if i > j: return 0
        if dp[i][j] > 0: return dp[i][j]
        res = self.print(s, i, j - 1, dp) + 1
        for k in range(i, j):
            if s[k] == s[j]:
                res = min(res, self.print(s, i, k, dp) + self.print(s, k + 1, j - 1, dp))
        dp[i][j] = res
        return dp[i][j]
