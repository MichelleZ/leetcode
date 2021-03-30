#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-cost-for-tickets/
# Author: Miao Zhang
# Date:   2021-03-30

class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        req = set(days)
        dp = [0] * (days[-1] + 1)
        for i in range(1, len(dp)):
            if not i in req:
                dp[i] = dp[i - 1]
                continue
            dp[i] = min(dp[max(0, i - 1)] + costs[0],
                    dp[max(0, i - 7)] + costs[1],
                    dp[max(0, i - 30)] + costs[2])
        return dp[-1]
