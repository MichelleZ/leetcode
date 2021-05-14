#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/
# Author: Miao Zhang
# Date:   2021-05-15

class Solution:
    def maxNonOverlapping(self, nums: List[int], target: int) -> int:
        n = len(nums)
        idx = {0: -1}
        sums = 0
        dp = [0] * (n + 1)
        for i in range(len(nums)):
            sums += nums[i]
            t = sums - target
            dp[i + 1] = dp[i]
            if t in idx:
                dp[i + 1] = max(dp[i + 1], dp[idx[t] + 1] + 1)
            idx[sums] = i
        return dp[n]
