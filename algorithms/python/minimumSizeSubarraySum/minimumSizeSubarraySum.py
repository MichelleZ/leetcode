#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-size-subarray-sum/
# Author: Miao Zhang
# Date:   2021-01-26

class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        l, r = 0, 0
        res = float('inf')
        cursum = 0
        while r < len(nums):
            cursum += nums[r]
            while cursum >= s:
                res = min(res, r - l + 1);
                cursum -= nums[l];
                l += 1
            r += 1
        return res if res != float('inf') else 0
