#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/regular-expression-matching/
# Author: Miao Zhang
# Date:   2021-01-05

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if p == '':
            return s == ''
        firstmatch = len(s) > 0 and (s[0] == p[0] or p[0] == '.')

        if len(p) > 1 and p[1] == '*':
            return self.isMatch(s, p[2:]) or (firstmatch and self.isMatch(s[1:], p))
        else:
            return (firstmatch and self.isMatch(s[1:], p[1:]))

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m = len(s)
        n = len(p)
        dp = [[False for _ in range(n + 1)] for _ in range(m + 1)]
        dp[0][0] = True
        for i in range(m + 1):
            for j in range(1, n + 1):
                if j > 1 and p[j - 1] == '*':
                    dp[i][j] = dp[i][j - 2] or (i > 0 and dp[i - 1][j] and (s[i -1] == p[j-2] or p[j - 2] == '.'))
                else:
                    dp[i][j] = i > 0 and dp[i - 1][j - 1] and (s[i - 1] == p[j - 1] or p[j - 1] == '.')
        return dp[m][n]

