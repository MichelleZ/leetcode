#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/stone-game-viii/
# Author: Miao Zhang
# Date:   2021-06-16

class Solution:
    def stoneGameVIII(self, stones: List[int]) -> int:
        n = len(stones)
        sums = list(accumulate(stones))
        dp = [0] * n
        dp[n - 1] = sums[n - 1]
        for i in range(n - 2, 0, -1):
            dp[i] = max(dp[i + 1], sums[i] - dp[i + 1])
        return dp[1]
