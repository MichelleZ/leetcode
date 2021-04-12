#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/stone-game-ii/
# Author: Miao Zhang
# Date:   2021-04-12

class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        presum = 0
        dp = [[0 for _ in range(n + 1)] for _ in range(n)]
        for i in range(n - 1, -1, -1):
            presum += piles[i]
            for m in range(1, n + 1):
                if i + 2 * m >= n:
                    dp[i][m] = presum
                else:
                    for x in range(1, 2 * m + 1):
                        dp[i][m] = max(dp[i][m], presum - dp[i + x][max(x, m)])
        return dp[0][1]
