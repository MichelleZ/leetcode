#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/paint-house-iii/
# Author: Miao Zhang
# Date:   2021-05-09

class Solution:
    def minCost(self, houses: List[int], cost: List[List[int]], m: int, n: int, target: int) -> int:
        dp = [[[float('inf') for _ in range(n + 1)] for _ in range(m + 1)] for _ in range(target + 1)]
        for i in range(n + 1):
            dp[0][0][i] = 0
        for k in range(1, target + 1):
            for i in range(k, m + 1):
                hi = houses[i - 1]
                hj = houses[i - 2] if i >= 2 else 0
                si, sj = 1, 1
                ei, ej = n, n
                if hi:
                    si, ei = hi, hi
                if hj:
                    sj, ej = hj, hj
                for ci in range(si, ei + 1):
                    v = 0 if ci == hi else cost[i - 1][ci - 1]
                    for cj in range(sj, ej + 1):
                        dp[k][i][ci] = min(dp[k][i][ci], dp[k - (ci != cj)][i - 1][cj] + v)
        res = min(dp[target][m])
        return -1 if res == float('inf') else res
