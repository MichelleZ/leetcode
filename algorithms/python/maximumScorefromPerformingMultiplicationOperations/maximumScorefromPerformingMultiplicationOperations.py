#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/
# Author: Miao Zhang
# Date:   2021-06-04

class Solution:
    def maximumScore(self, nums: List[int], multipliers: List[int]) -> int:
        m = len(multipliers)
        n = len(nums)
        dp = [[float('-inf') for _ in range(m + 1)] for _ in range(m + 1)]
        dp[0][0] = 0
        res = float('-inf')
        for k in range(1, m + 1):
            for i in range(k + 1):
                j = k - i
                if i: dp[i][j] = max(dp[i][j], dp[i - 1][j] + nums[i - 1] * multipliers[k - 1])
                if j: dp[i][j] = max(dp[i][j], dp[i][j - 1] + nums[n - j] * multipliers[k - 1])
                if k == m: res = max(res, dp[i][j])
        return res

class Solution:
    def maximumScore(self, nums: List[int], multipliers: List[int]) -> int:
        m = len(multipliers)
        n = len(nums)
        cache = [[float('-inf') for _ in range(m)] for _ in range(m)]
        def dp(i, j):
            k = n - (j - i + 1)
            if k == m: return 0
            if cache[i][k] != float('-inf'):
                return cache[i][k]
            cache[i][k] = max(dp(i + 1, j) + nums[i] * multipliers[k],
                              dp(i, j - 1) + nums[j] * multipliers[k])
            return cache[i][k]

        return dp(0, n - 1)
