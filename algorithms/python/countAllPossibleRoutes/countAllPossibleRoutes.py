#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-all-possible-routes/
# Author: Miao Zhang
# Date:   2021-05-16

class Solution:
    def countRoutes(self, locations: List[int], start: int, finish: int, fuel: int) -> int:
        kMod = 10 ** 9 + 7
        n = len(locations)
        dp = [[0 for _ in range(fuel + 1)] for _ in range(n)]
        dp[start][fuel] = 1
        for f in range(fuel, 0, -1):
            for i in range(n):
                if not dp[i][f] or abs(locations[i] - locations[finish]) > f:
                    continue
                for j in range(n):
                    d = abs(locations[i] - locations[j])
                    if i == j or f < d:
                        continue
                    dp[j][f - d] = (dp[j][f - d] + dp[i][f]) % kMod
        return sum(dp[finish]) % kMod
