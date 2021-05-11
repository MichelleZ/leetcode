#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
# Author: Miao Zhang
# Date:   2021-05-11

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        l = 0
        sums = 0
        res = 0
        for r in range(n):
            sums += nums[r]
            while l < r and sums < r - l:
                sums -= nums[l]
                l += 1
            res = max(res, r - l)
        return res
