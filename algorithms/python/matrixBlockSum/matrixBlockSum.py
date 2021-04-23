#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/matrix-block-sum/
# Author: Miao Zhang
# Date:   2021-04-23

class Solution:
    def matrixBlockSum(self, mat: List[List[int]], k: int) -> List[List[int]]:
        m = len(mat)
        n = len(mat[0])
        dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1]
        res = mat
        for i in range(m):
            for j in range(n):
                x1 = max(0, i - k)
                x2 = min(m - 1, i + k)
                y1 = max(0, j - k)
                y2 = min(n - 1, j + k)
                res[i][j] = dp[x2 + 1][y2 + 1] - dp[x2 + 1][y1] - dp[x1][y2 + 1] + dp[x1][y1]
        return res
