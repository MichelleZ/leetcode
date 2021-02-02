#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/burst-balloons/
# Author: Miao Zhang
# Date:   2021-02-01

class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        n = len(nums)
        nums.append(1)
        nums.insert(0, 1)
        
        dp = [[0 for _ in range(n + 2)] for _ in range(n + 2)]
        for l in range(1, n + 1):
            for i in range(1, n - l + 2):
                j = i + l - 1
                for k in range(i, j + 1):
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + nums[i - 1] * nums[k] * nums[j + 1] + dp[k + 1][j])
