#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-ascending-subarray-sum/
# Author: Miao Zhang
# Date:   2021-06-08

class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        res = 0
        sums = nums[0]
        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                sums += nums[i]
            else:
                res = max(res, sums)
                sums = nums[i]
        res = max(res, sums)
        return res



