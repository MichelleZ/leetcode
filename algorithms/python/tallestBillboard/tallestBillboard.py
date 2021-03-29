#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/tallest-billboard/
# Author: Miao Zhang
# Date:   2021-03-29

class Solution:
    def tallestBillboard(self, rods: List[int]) -> int:
        sums = sum(rods)
        dp = [-1 for _ in range(sums + 1)]
        dp[0] = 0
        for r in rods:
            cur = dp[:]
            for i in range(sums - r + 1):
                if cur[i] < 0: continue
                dp[i + r] = max(dp[i + r], cur[i])
                dp[abs(i - r)] = max(dp[abs(i - r)], cur[i] + min(r, i))
        return dp[0]
