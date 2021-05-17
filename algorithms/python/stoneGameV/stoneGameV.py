#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/stone-game-v/
# Author: Miao Zhang
# Date:   2021-05-16

class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        n = len(stoneValue)
        sums = [0] * (n + 1)
        for i in range(n):
            sums[i + 1] = sums[i] + stoneValue[i]

        @lru_cache(None)
        def dp(l, r):
            if l == r: return 0
            res = 0
            for k in range(l, r):
                suml = sums[k + 1] - sums[l]
                sumr = sums[r + 1] - sums[k + 1]
                if suml < sumr:
                    res = max(res, suml + dp(l, k))
                elif sumr < suml:
                    res = max(res, sumr + dp(k + 1, r))
                else:
                    res = max(res, suml + max(dp(l, k), dp(k + 1, r)))
            return res

        return dp(0, n - 1)
