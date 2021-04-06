#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/last-stone-weight-ii/
# Author: Miao Zhang
# Date:   2021-04-06

class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        dp = [0] * 1501
        sums = 0
        for st in stones:
            sums += st
        target = sums // 2
        for i in range(len(stones)):
            for j in range(target, stones[i] - 1, -1):
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i])
        return sums - dp[target] * 2
