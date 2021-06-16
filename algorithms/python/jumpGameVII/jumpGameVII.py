#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/jump-game-vii/
# Author: Miao Zhang
# Date:   2021-06-16

class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        n = len(s)
        dp = [0] * n
        sums = [0] * n
        dp[0] = 1
        for i in range(minJump): sums[i] = 1
        for i in range(minJump, n):
            l, r = i - maxJump, i - minJump
            if s[i] == '0':
                total = sums[r] - (0 if l <= 0 else sums[l - 1])
                dp[i] = total != 0
            sums[i] = sums[i - 1] + dp[i]
        return dp[n - 1]
