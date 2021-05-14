#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
# Author: Miao Zhang
# Date:   2021-05-15

class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        cuts.sort()
        cuts.insert(0, 0)
        cuts.append(n)
        m = len(cuts)
        dp = [[0 for _ in range(m)] for _ in range(m)]
        for i in range(m - 1, -1, -1):
            for j in range(i + 1, m):
                dp[i][j] = 0 if (i + 1) == j else float('inf')
                for k in range(i + 1, j):
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i])
        return dp[0][m - 1]
