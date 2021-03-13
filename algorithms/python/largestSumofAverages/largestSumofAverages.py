#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/largest-sum-of-averages/
# Author: Miao Zhang
# Date:   2021-03-13

class Solution:
    def largestSumOfAverages(self, A: List[int], K: int) -> float:
        n = len(A)
        dp = [0.0 for _ in range(n + 1)]
        sums = [0.0 for _ in range(n + 1)]
        for i in range(1, n + 1):
            sums[i] = sums[i - 1] + A[i - 1]
            dp[i] = sums[i] / i
        for k in range(2, K + 1):
            tmp = [0.0 for _ in range(n + 1)]
            for i in range(k, n + 1):
                for j in range(k - 1, i):
                    tmp[i] = max(tmp[i], dp[j] + (sums[i] - sums[j]) / (i - j))
            dp, tmp = tmp, dp
        return dp[n]
