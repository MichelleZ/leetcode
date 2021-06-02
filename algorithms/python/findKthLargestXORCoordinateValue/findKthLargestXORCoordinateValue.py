#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/
# Author: Miao Zhang
# Date:   2021-06-02

class Solution:
    def kthLargestValue(self, matrix: List[List[int]], k: int) -> int:
        m = len(matrix)
        n = len(matrix[0])
        dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
        res = []
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                dp[i][j] = dp[i - 1][j] ^ dp[i][j - 1] ^ dp[i - 1][j - 1] ^ matrix[i - 1][j - 1]
                res.append(dp[i][j])
        res.sort(reverse=True)
