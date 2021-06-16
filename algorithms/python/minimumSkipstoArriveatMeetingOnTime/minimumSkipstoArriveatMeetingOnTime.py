#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-skips-to-arrive-at-meeting-on-time/
# Author: Miao Zhang
# Date:   2021-06-16

class Solution:
    def minSkips(self, dist: List[int], speed: int, hoursBefore: int) -> int:
        eps = 1e-8
        n = len(dist)
        dp = [[float('inf') for _ in range(n + 1)] for _ in range(n + 1)]
        dp[0][0] = 0
        for i in range(1, n + 1):
            t = dist[i - 1] / speed;
            for j in range(i + 1):
                if j < i:
                    dp[i][j] = ceil(dp[i - 1][j] + t - eps)
                if j >= 1:
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + t)
        for j in range(n + 1):
            if dp[n][j] <= hoursBefore:
                return j
        return -1
