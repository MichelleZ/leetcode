#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/subarray-product-less-than-k/
# Author: Miao Zhang
# Date:   2021-03-03

class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k <= 1: return 0
        res = 0
        prod = 1
        left = 0
        for right in range(0, len(nums)):
            prod *= nums[right]
            while left <= right and prod >= k: 
                prod /= nums[left]
                left += 1
            res += right - left + 1
        return res
