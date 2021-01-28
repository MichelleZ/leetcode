#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/product-of-array-except-self/
# Author: Miao Zhang
# Date:   2021-01-28

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = [0] * len(nums)
        res[0] = 1
        tmp = 1
        for i in range(1, len(nums)):
            tmp *= nums[i - 1]
            res[i] = tmp
        tmp = 1
        for i in range(len(nums) - 2, -1, -1):
            tmp = tmp * nums[i + 1]
            res[i] *= tmp
        return res
