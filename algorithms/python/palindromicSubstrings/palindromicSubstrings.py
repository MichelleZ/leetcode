#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/palindromic-substrings/
# Author: Miao Zhang
# Date:   2021-02-26

class Solution:
    def countSubstrings(self, s: str) -> int:
        cnt = 0
        n = len(s)
        dp = [[False for _ in range(n)] for _ in range(n)]
        for l in range(1, n + 1):
            for i in range(n - l + 1):
                j = i + l - 1
                if l == 1 or (l == 2 and s[i] == s[j]) or (l >= 3 and s[i] == s[j] and dp[i + 1][j - 1]):
                    dp[i][j] = True
                    cnt += 1
        return cnt
