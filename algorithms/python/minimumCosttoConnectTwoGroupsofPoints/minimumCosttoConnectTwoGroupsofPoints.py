#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points/
# Author: Miao Zhang
# Date:   2021-05-19

class Solution:
    def connectTwoGroups(self, cost: List[List[int]]) -> int:
        m = len(cost)
        n = len(cost[0])
        dp = [[float('inf') for _ in range(1 << n)] for _ in range(m + 1)]
        dp[0][0] = 0
        for i in range(m):
            for j in range(n):
                for s in range(1 << n):
                    dp[i + 1][s | (1 << j)] = min(dp[i + 1][s | (1 << j)],
                                                dp[i + 1][s] + cost[i][j],
                                                dp[i][s] + cost[i][j])
        return dp[m][(1 << n) - 1]
