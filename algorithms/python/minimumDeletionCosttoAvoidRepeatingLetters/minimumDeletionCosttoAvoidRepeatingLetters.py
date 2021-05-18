#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/
# Author: Miao Zhang
# Date:   2021-05-18

class Solution:
    def minCost(self, s: str, cost: List[int]) -> int:
        sums = cost[0]
        maxval = cost[0]
        res = 0
        for i in range(1, len(s)):
            if s[i] != s[i - 1]:
                res += sums - maxval
                sums = 0
                maxval = 0
            sums += cost[i]
            maxval = max(maxval, cost[i])
        return res + (sums - maxval)
