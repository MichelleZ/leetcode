#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximize-score-after-n-operations/
# Author: Miao Zhang
# Date:   2021-06-08

class Solution:
    def maxScore(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[0 for _ in range(n // 2 + 1)] for _ in range(1 << n)]
        for mask in range(1 << n):
            c = bin(mask).count('1')
            if c & 1: continue
            k = c // 2 + 1
            for i in range(n):
                for j in range(i + 1, n):
                    if (mask & (1 << i)) + (mask & (1 << j)) == 0:
                        newmask = mask | (1 << i) | (1 << j)
                        dp[newmask][k] = max(dp[newmask][k],
                                    k * gcd(nums[i], nums[j]) + dp[mask][k - 1])
        return dp[(1 << n) - 1][n // 2]
