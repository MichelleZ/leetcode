#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/
# Author: Miao Zhang
# Date:   2021-06-07

class Solution:
    def longestPalindrome(self, word1: str, word2: str) -> int:
        l1 = len(word1)
        l2 = len(word2)
        s = word1 + word2
        n = l1 + l2
        dp = [[0 for _ in range(n)] for _ in range(n)]
        for i in range(n): dp[i][i] = 1
        for l in range(2, n + 1):
            for i in range(n - l + 1):
                j = i + l - 1
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1] + 2
                else:
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
        res = 0
        for i in range(l1):
            for j in range(l2):
                if word1[i] == word2[j]:
                    res = max(res, dp[i][l1 + j])
        return res
