#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
# Author: Miao Zhang
# Date:   2021-06-16

class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        nums.sort()
        for i in range(n // 2):
            res = max(res, nums[i] + nums[n - 1 - i])
        return res
