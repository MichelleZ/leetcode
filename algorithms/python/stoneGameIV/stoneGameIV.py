#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/stone-game-iv/
# Author: Miao Zhang
# Date:   2021-05-12

class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        dp = [0] * (n + 1)
        for i in range(1, n + 1):
            for k in range(int(sqrt(i)), 0, -1):
                if not dp[i - k * k]:
                    dp[i] = True
                    break
        return dp[n]
