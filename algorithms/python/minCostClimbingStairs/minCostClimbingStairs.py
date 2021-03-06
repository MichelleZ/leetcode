#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/min-cost-climbing-stairs/
# Author: Miao Zhang
# Date:   2021-03-06

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = [0 for _ in range(n)]
        dp[0] = cost[0]
        dp[1] = cost[1]
        for i in range(2, n):
            dp[i] = min(dp[i - 1] + cost[i], dp[i - 2] + cost[i])
        return min(dp[n - 1], dp[n - 2])
