#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-pivot-index/
# Author: Miao Zhang
# Date:   2021-03-04

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        l, r = 0, sum(nums)
        for i in range(len(nums)):
            r -= nums[i]
            if l == r: return i
            l += nums[i]
        return -1
