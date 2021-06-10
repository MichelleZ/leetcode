#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/frequency-of-the-most-frequent-element/
# Author: Miao Zhang
# Date:   2021-06-11

class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        l, sums, res = 0, 0, 0
        for r in range(len(nums)):
            sums += nums[r]
            while l < r and nums[r] * (r - l + 1) - sums > k:
                sums -= nums[l]
                l += 1
            res = max(res, r - l + 1)
        return res
