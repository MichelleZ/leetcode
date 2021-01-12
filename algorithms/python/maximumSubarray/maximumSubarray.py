#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-subarray/
# Author: Miao Zhang
# Date:   2021-01-12

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        for i in range(1, len(nums)):
            cur_num = max(nums[i] + nums[i -1], nums[i])
            nums[i] = cur_num
        return max(nums)
