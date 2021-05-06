#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/
# Author: Miao Zhang
# Date:   2021-05-06

class Solution:
    def numberWays(self, hats: List[List[int]]) -> int:
        kMod = 10 ** 9 + 7
        n = len(hats)
        maxhat = 0
        for i in range(n):
            for h in hats[i]:
                maxhat = max(maxhat, h)
        hat2People = [[] for _ in range(maxhat + 1)]
        for i in range(n):
            for h in hats[i]:
                hat2People[h].append(i)
        dp = [[0 for _ in range(1 << n)] for _ in range(maxhat + 1)]
        dp[0][0] = 1
        for i in range(1, maxhat + 1):
            dp[i] = dp[i - 1]
            for mask in range((1 << n) - 1, -1, -1):
                for p in hat2People[i]:
                    if mask & (1 << p): continue
                    dp[i][mask | (1 << p)] += dp[i - 1][mask]
                    dp[i][mask | (1 << p)] %= kMod
        return dp[-1][-1]
