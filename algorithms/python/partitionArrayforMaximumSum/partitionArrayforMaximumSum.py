#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/partition-array-for-maximum-sum/
# Author: Miao Zhang
# Date:   2021-04-06

class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        n = len(arr)
        dp = [0] * (n + 1)
        for i in range(1, n + 1):
            m = float('-inf')
            for l in range(1, min(k, i) + 1):
                m = max(m, arr[i - l])
                dp[i] = max(dp[i], dp[i - l] + m * l)
        return dp[n]
