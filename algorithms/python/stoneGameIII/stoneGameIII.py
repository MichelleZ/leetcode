#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/stone-game-iii/
# Author: Miao Zhang
# Date:   2021-04-30

class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)
        dp = [float('-inf') for _ in range(n + 1)]
        dp[n] = 0
        for i in range(n - 1, -1, -1):
            j = i + 1
            presum = 0
            while j <= i + 3 and j < n + 1:
                presum += stoneValue[j - 1]
                dp[i] = max(dp[i], presum - dp[j])
                j += 1
        return "Bob" if dp[0] < 0 else ("Alice" if dp[0] > 0 else "Tie")
