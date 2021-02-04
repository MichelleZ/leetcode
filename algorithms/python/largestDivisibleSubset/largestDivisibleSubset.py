#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/largest-divisible-subset/
# Author: Miao Zhang
# Date:   2021-02-04

class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        if not nums: return []
        nums.sort()
        dp = [0] * len(nums)
        parent = [0] * len(nums)
        maxval = 0
		index = -1
        for i in range(len(nums)):
            for j in range(i - 1, -1, -1):
                if nums[i] % nums[j] == 0 and dp[i] < dp[j] + 1:
                    dp[i] = dp[j] + 1
                    parent[i] = j
                    if dp[i] > maxval:
                        maxval = dp[i]
                        index = i
        res = []
        for k in range(maxval + 1):
            res.append(nums[index])
            index = parent[index]
        return res[::-1]
