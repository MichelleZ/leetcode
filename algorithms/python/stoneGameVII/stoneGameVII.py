#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/stone-game-vii/
# Author: Miao Zhang
# Date:   2021-05-28

class Solution:
    def stoneGameVII(self, stones: List[int]) -> int:
        n = len(stones)
        sums = [0] * (n + 1)
        for i in range(n):
            sums[i + 1] = sums[i] + stones[i]
        dp = [[0 for _ in range(n)] for _ in range(n)]
        for l in range(2, n + 1):
            for i in range(0, n - l + 1):
                j = i + l - 1
                dp[i][j] = max(sums[j + 1] - sums[i + 1] - dp[i + 1][j],
                               sums[j] - sums[i] - dp[i][j - 1])
        
        return dp[0][n - 1]
