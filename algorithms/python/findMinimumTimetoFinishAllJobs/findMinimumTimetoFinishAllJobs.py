#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/
# Author: Miao Zhang
# Date:   2021-06-01

class Solution:
    def minimumTimeRequired(self, jobs: List[int], k: int) -> int:
        n = len(jobs)
        dp = [[float('inf') for _ in range(1 << n)] for _ in range(k + 1)]
        dp[0][0] = 0
        cost = [0] * (1 << n)
        for s in range(1 << n):
            for i in range(n):
                if (s >> i) & 1: cost[s] += jobs[i];
            dp[1][s] = cost[s]
        for i in range(2, k + 1):
            for s in range(1 << n):
                subset = s
                while subset:
                    dp[i][s] = min(dp[i][s], max(dp[i - 1][subset], cost[subset ^ s]))
                    subset = (subset - 1) & s
        return dp[k][(1 << n) - 1]
