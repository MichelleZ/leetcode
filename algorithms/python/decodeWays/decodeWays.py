#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/decode-ways/
# Author: Miao Zhang
# Date:   2021-01-15

class Solution:
    def numDecodings(self, s: str) -> int:
        dp = [0 for _ in range(len(s) + 1)]
        dp[0] = 1
        for i in range(len(s)):
            if s[i] != '0':
                dp[i + 1] += dp[i]
            if i > 0 and '09' < s[i - 1: i + 1] < '27':
                dp[i + 1] += dp[i - 1]
        return dp[len(s)]
