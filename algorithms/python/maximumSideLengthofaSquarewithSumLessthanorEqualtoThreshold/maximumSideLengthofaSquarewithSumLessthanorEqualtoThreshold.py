#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/
# Author: Miao Zhang
# Date:   2021-04-21

class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        m = len(mat)
        n = len(mat[0])
        dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1]

        def rangeSum(x1, y1, x2, y2):
            return dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1]

        res = 0
        l = 0
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                while i + l < m + 1 and j + l < n + 1 and rangeSum(i, j, i + l, j + l) <= threshold:
                    res = l + 1
                    l += 1
        return res
