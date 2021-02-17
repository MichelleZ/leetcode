#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/target-sum/
# Author: Miao Zhang
# Date:   2021-02-17

class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        n = len(nums)
        sums = sum(nums)
        if sums < abs(S): return 0
        offset = sums
        dp = [0] * (sums + offset + 1)
        dp[offset] = 1
        for n in nums:
            tmp = [0] * (sums + offset + 1)
            for i in range(n, sums + offset + 1 - n):
                if dp[i]:
                    tmp[i + n] += dp[i]
                    tmp[i - n] += dp[i]
            tmp, dp = dp, tmp
        return dp[S + offset]
