#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/
# Author: Miao Zhang
# Date:   2021-06-15

class Solution:
    def rearrangeSticks(self, n: int, k: int) -> int:
        kMod = 10 ** 9 + 7
        dp = [0] * (k + 1)
        dp[0] = 1
        for i in range(1, n + 1):
            dp2 = [0] * (k + 1)
            for j in range(1, k + 1):
                dp2[j] = (dp[j] * (i - 1) + dp[j - 1]) % kMod
            dp = dp2[:]
        return dp[k]
