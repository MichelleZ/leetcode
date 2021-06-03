#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/
# Author: Miao Zhang
# Date:   2021-06-03

class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        events.sort(key=lambda x: x[1])
        n = len(events)
        dp = [[0 for _ in range(k + 1)] for _ in range(n + 1)]
        for i in range(1, n + 1):
            non_overlap = 0
            for l in range(i - 1, 0, -1):
                if events[l - 1][1] < events[i - 1][0]:
                    non_overlap = l
                    break
            for j in range(1, k + 1):
                dp[i][j] = max(dp[non_overlap][j - 1] + events[i - 1][2],
                               dp[i - 1][j])
        return dp[n][k]
