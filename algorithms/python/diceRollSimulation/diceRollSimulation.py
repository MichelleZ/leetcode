#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/dice-roll-simulation/
# Author: Miao Zhang
# Date:   2021-04-18

class Solution:
    def dieSimulator(self, n: int, rollMax: List[int]) -> int:
        kMaxRolls = 15
        kMod = 10 ** 9 + 7
        
        dp = [[[0 for _ in range(kMaxRolls + 1)] for _ in range(6)] for _ in range(n + 1)]
        for j in range(6):
            dp[1][j][1] = 1
        for i in range(2, n + 1):
            for j in range(6):
                for p in range(6):
                    for k in range(1, rollMax[p] + 1):
                        if p != j:
                            dp[i][j][1] = (dp[i][j][1] + dp[i - 1][p][k]) % kMod
                        elif k < rollMax[j]:
                            dp[i][j][k + 1]= dp[i - 1][j][k]
        res = 0
        for j in range(6):
            for k in range(1, rollMax[j] + 1):
                res = (res + dp[n][j][k]) % kMod
        return res
