#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/allocate-mailboxes/
# Author: Miao Zhang
# Date:   2021-05-10

class Solution:
    def minDistance(self, houses: List[int], k: int) -> int:
        n = len(houses)
        houses.sort()
        cost = [[0 for _ in range(n)] for _ in range(n)]
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                cost[i][j] = cost[i + 1][j - 1] + houses[j] - houses[i]
        dp = [[float('inf') for _ in range(k + 1)] for _ in range(n)]
        for i in range(n):
            dp[i][1] = cost[0][i]
            for j in range(2, min(k, i + 1) + 1):
                for p in range(i):
                    dp[i][j] = min(dp[i][j], dp[p][j - 1] + cost[p + 1][i])
        return dp[n - 1][k]
