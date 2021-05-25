#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-sorted-vowel-strings/
# Author: Miao Zhang
# Date:   2021-05-25

class Solution:
    def countVowelStrings(self, n: int) -> int:
        dp = [[1 for _ in range(5)] for _ in range(n + 1)]
        for i in range(2, n + 1):
            tmp = 0
            for j in range(5):
                tmp += dp[i - 1][j]
                dp[i][j] = tmp
        return sum(dp[n])
