#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-cost-to-merge-stones/
# Author: Miao Zhang
# Date:   2021-03-31

class Solution:
    def mergeStones(self, stones: List[int], K: int) -> int:
        n = len(stones)
        if (n - 1) % (K - 1): return -1
        sums = [0] * (n + 1)
        for i in range(n):
            sums[i + 1] = sums[i] + stones[i]
        dp = [[float('inf') for _ in range(n)] for _ in range(n)]
        for i in range(n):
            dp[i][i] = 0
        for l in range(2, n + 1):
            for i in range(n - l + 1):
                j = i + l - 1
                for m in range(i, j, K - 1):
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j])
                if (l - 1) % (K - 1) == 0:
                    dp[i][j] += sums[j + 1] - sums[i]
        return dp[0][n - 1]
