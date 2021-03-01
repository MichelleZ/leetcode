#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-longest-increasing-subsequence/
# Author: Miao Zhang
# Date:   2021-02-28

class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1] * n
        cnt = [1] * n
        for i in range(len(nums)):
            for j in range(i):
                if nums[j] < nums[i]:
                    if dp[j] + 1 > dp[i]:
                        dp[i] = dp[j] + 1
                        cnt[i] = cnt[j]
                    elif dp[j] + 1 == dp[i]:
                        cnt[i] += cnt[j]
        max_len = max(dp)
        return sum(c for i, c in enumerate(cnt) if dp[i] == max_len)
