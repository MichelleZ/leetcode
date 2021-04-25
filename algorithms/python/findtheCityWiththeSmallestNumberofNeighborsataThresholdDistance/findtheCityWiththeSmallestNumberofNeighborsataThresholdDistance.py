#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
# Author: Miao Zhang
# Date:   2021-04-25

class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        dp = [[float('inf') for _ in range(n)] for _ in range(n)]
        for i in range(n):
            dp[i][i] = 0
        for u, v, w in edges:
            dp[u][v] = w
            dp[v][u] = w
        for k in range(n):
            for u in range(n):
                for v in range(n):
                    dp[u][v] = min(dp[u][v], dp[u][k] + dp[k][v])
        res = {sum(t <= distanceThreshold for t in dp[i]):i for i in range(n)}
        return res[min(res)]
                    
