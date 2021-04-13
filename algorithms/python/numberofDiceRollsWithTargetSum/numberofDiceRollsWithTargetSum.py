#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
# Author: Miao Zhang
# Date:   2021-04-13

class Solution:
    def numRollsToTarget(self, d: int, f: int, target: int) -> int:
        from functools import lru_cache
        kMod = 10 ** 9 + 7
        
        @lru_cache(maxsize=None)
        def dp(i, t):
            if i == 0: return 1 if t == 0 else 0
            if t > f * i or t < i: return 0
            res = 0
            for k in range(1, f + 1):
                res = (res + dp(i - 1, t - k)) % kMod
            return res
        
        return dp(d, target)
