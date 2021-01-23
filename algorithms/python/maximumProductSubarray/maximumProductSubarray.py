#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-product-subarray/
# Author: Miao Zhang
# Date:   2021-01-22

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        minval = maxval = globalmax = nums[0]
        for i in range(1, len(nums)):
            lastmax = maxval
            maxval = max(maxval * nums[i], minval * nums[i], nums[i])
            minval = min(minval * nums[i], lastmax * nums[i], nums[i])
            globalmax = max(globalmax, maxval)
        return globalmax
