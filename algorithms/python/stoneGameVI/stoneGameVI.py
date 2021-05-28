#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/stone-game-vi/
# Author: Miao Zhang
# Date:   2021-05-27

class Solution:
    def stoneGameVI(self, aliceValues: List[int], bobValues: List[int]) -> int:
        n = len(aliceValues)
        sums = []
        for i in range(n):
            sums.append([aliceValues[i] + bobValues[i], i])
        sums.sort(reverse=True)
        res = 0
        for i in range(n):
            idx = sums[i][1]
            res += (bobValues[idx] if i & 1 else aliceValues[idx]) * (-1 if i & 1 else 1)
        return -1 if res < 0 else (1 if res > 0 else 0)
