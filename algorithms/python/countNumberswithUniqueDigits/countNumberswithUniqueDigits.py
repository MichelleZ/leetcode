#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-numbers-with-unique-digits/
# Author: Miao Zhang
# Date:   2021-02-04

class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n == 0: return 1
        dp = [0 for _ in range(9)]
        dp[1] = 10
        dp[2] = 9 * 9
        for i in range(3, min(9, n + 1)):
            dp[i] = dp[i - 1] * (10 - i + 1)
        res = 0
        for i in range(min(9, n + 1)):
            res += dp[i]
        return res
