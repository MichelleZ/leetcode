#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
# Author: Miao Zhang
# Date:   2021-04-12

class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        n = len(arr)
        dp = [[0 for _ in range(n)] for _ in range(n)]
        for l in range(2, n + 1):
            for i in range(n - l + 1):
                j = i + l - 1
                dp[i][j] = float('inf')
                for k in range(i, j):
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + max(arr[i: k + 1]) * max(arr[k + 1: j + 1]))
        return dp[0][n - 1]
