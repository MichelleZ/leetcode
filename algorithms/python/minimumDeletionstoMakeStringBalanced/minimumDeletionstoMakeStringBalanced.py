#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
# Author: Miao Zhang
# Date:   2021-05-25

class Solution:
    def minimumDeletions(self, s: str) -> int:
        n = len(s)
        dp = [0] * (n + 1)
        b = 0
        for i, c in enumerate(s):
            if c == 'b':
                dp[i + 1] = dp[i]
                b += 1
            else:
                dp[i + 1] = min(b, dp[i] + 1)
        return dp[n]
